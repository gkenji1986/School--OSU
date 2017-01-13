var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};
var target;

; (function (game, cjs, lib) {
    function Board() {
        cjs.Container.call(this); // super
        //This changes where the grid will actually be displayed
        this.x = 0;
        this.y = 0;

        // grid parameters
        this.rows = 5;
        this.cols = 9;
        this.tileWidth = 128;
        this.tileHeight = 128;
        this.bulletList = [];

        // graphics
        var sprite = new lib.Board();
        this.addChild(sprite);
        //sprite.y = this.tileHeight;

        // Selection graphic 
        /*
			this.selection = new lib.Selection();
			this.addChild(this.selection);
			this.selection.visible = false;
		*/
        // by default, we are not adding building
        this.isAddingBuilding = false;

        // list of buildings and enemies
        this.buildingMap = game.helper.create2DArray(this.cols, this.rows);
        this.enemyMap = game.helper.create2DArray(this.cols, this.rows);
        this.enemyList = [];
        this.star = new EasyStar.js();
        // event handling
        game.on('readyToPlaceBuilding', this.readyToPlaceBuilding.bind(this));

        // mouse interaction
        game.stage.on('stagemousemove', this.onMouseMove.bind(this));
        game.stage.on('stagemouseup', this.onClick.bind(this));
        this.on('tick', this.tick);
    }
    Board.prototype = Object.create(cjs.Container.prototype);

    // utilities
    Board.prototype.screenToRowCol = function (x, y) {
        var col = Math.floor(x / this.tileWidth);
        var row = Math.floor(y / this.tileHeight);
        return { col: col, row: row };
    };
    Board.prototype.rowColToScreen = function (row, col) {
        var x = this.tileWidth * (col + 0.5); // +0.5 for tile center
        var y = this.tileHeight * (row + 0.5);
        return { x: x, y: y };
    };

    Board.prototype.areEnemiesCleared = function () {
        return (typeof this.enemyList === "object" && this.enemyList.length === 0);
    }
    // Summon new piece on board
    Board.prototype.addBuildingAtTile = function (buildingClass, col, row) {
        var sprite = new game[buildingClass]();
        this.addChild(sprite);
        var pos = this.rowColToScreen(row, col);
        sprite.x = pos.x;
        sprite.y = pos.y;


        // store row/col for easy access later
        sprite.row = row;
        sprite.col = col;

        this.buildingMap[col][row] = sprite;
    };

    Board.prototype.addEnemy = function (enemyClass) {
        /*var shape = new createjs.Shape();
        shape.graphics.beginFill("#8CDD81").drawRect(0, 0, 100, 100);
        shape.graphics.beginFill("#ff9999").drawRect(200, 200, 400, 400);
        this.addChild(shape);*/
        
        var sprite = new game[enemyClass]();
        this.addChild(sprite);

        var row = Math.floor(Math.random() * this.rows);// random row
        var pos = this.rowColToScreen(row, 0);
        sprite.x = pos.x;
        sprite.y = pos.y;

        // store row/row for easy access later
        sprite.row = row;
        sprite.col = 0;

        this.enemyList.push(sprite);
    };

    function isUndefined(_arr, _index1, _index2) {
        try {
            return _arr[_index1][_index2] == undefined;
        } catch (e) {
            return true;
        }
    }
    function checkWithinBounds(col, row) {
        if (col < 0 || col > this.cols || row < 0 || row > this.rows) {
            return false;
        }
        return true;
    }
    var surroundingNodes = function (mapRef, enemyRef) {
        var nodes = new Array();
        var col, row;

        // top
        col = enemyRef.col;
        row = enemyRef.row - 1;
        if (isUndefined(mapRef, col, row) && checkWithinBounds(col, row)) {
            nodes.push(fCost(enemyRef, enemyRef.target, col, row));
        }

        // left
        col = enemyRef.col - 1;
        row = enemyRef.row;
        if (isUndefined(mapRef, col, row) && checkWithinBounds(col, row)) {
            nodes.push(fCost(enemyRef, enemyRef.target, col, row));
        }

        // right
        col = enemyRef.col + 1;
        row = enemyRef.row;
        if (isUndefined(mapRef, col, row) && checkWithinBounds(col, row)) {
            nodes.push(fCost(enemyRef, enemyRef.target, col, row));
        }

        // bottom
        col = enemyRef.col;
        row = enemyRef.row + 1;
        if (isUndefined(mapRef, col, row) && checkWithinBounds(col, row)) {
            nodes.push(fCost(enemyRef, enemyRef.target, col, row));
        }

        return nodes;
    }

    var cost = function (ref, target) {
        return Math.sqrt(Math.pow(ref.row - target.row, 2) + Math.pow(ref.col - target.col, 2));
    }

    var getTarget = function (mapRef) {
        for (var i = 0; i < mapRef[8].length; i++) {
            if (isUndefined(mapRef, 8, i)) {
                return { col: 8, row: i };
            }
        }
        return { col: 8, row: (Math.floor((Math.random() * 100)) % 5) };
    }

    var generateMatrix = function (ref) {
        var matrix = new Array();
        for (var x = 0; x < ref.length; x++) {
            matrix[x] = new Array();
            for (var y = 0; y < ref[x].length; y++) {
                try {
                    matrix[x][y] = (ref[x][y] == undefined) ? 0 : 1;
                } catch (e) {
                    matrix[x][y] = 0;
                }
            }
        }
        return matrix;
    }
    Board.prototype.tick = function () {
        if (cjs.Ticker.getPaused()) { return; }
        // update the row/col for each enemy on board
        this.enemyMap = game.helper.create2DArray(this.cols, this.rows);
        var matrix = generateMatrix(this.buildingMap);
/*        back = new Shape();
        stage.addChild(back);
        back.x = 0;back.y = 0;
        back.graphics.beginBitmapFill(img,'repeat').drawRect(0,0,canvas.width,canvas.height);*/
        this.star.setGrid(matrix);
        this.star.setAcceptableTiles([0]);

        for (var i = 0, len = this.enemyList.length; i < len; i++) {

            var enemy = this.enemyList[i];

            var rowCol = this.screenToRowCol(enemy.x, enemy.y);

            // update both map and enemy's row/col
            if (isUndefined(this.enemyMap, rowCol.col, rowCol.row)) {

                this.enemyMap[rowCol.col][rowCol.row] = enemy;

                enemy.col = rowCol.col;
                enemy.row = rowCol.row;
            }
            enemy.target = getTarget(this.buildingMap);

            this.pathMove(enemy);

            this.star.calculate();
        }

        // check succeed enemies
        // succeeded enemies means it go through the right
        for (var i = 0, len = this.enemyMap[this.cols - 1].length; i < len; i++) {

            if (!isUndefined(this.enemyMap, this.cols - 1, i)) { // found enemy at the last column
                var enemy = this.enemyMap[this.cols - 1][i];
                game.lives -= 1;
                game.waves.enemiesSummoned -= 1;
                game.helper.removeItem(this.enemyList, enemy);
                enemy.parent.removeChild(enemy);
            }
        }

        //check if bullet hits enemy
        for (var m = this.enemyList.length - 1; m >= 0; m--) {
            for (var n = this.bulletList.length - 1; n >= 0; n--) {
                var bullet = this.bulletList[n];
                var pos = bullet.localToLocal(0, 0, this);
                var rowCol = this.screenToRowCol(pos.x, pos.y);

                if (!isUndefined(this.enemyMap, rowCol.col, rowCol.row)) {
                    var enemy = this.enemyMap[rowCol.col][rowCol.row];

                    //damage enemy
                    cjs.Sound.play("hit");
                    enemy.damage(bullet.damageDeal);

                    if (enemy.hp <= 0) {
                        game.score += enemy.score;
                        game.gold += enemy.gold;
                        this.enemyMap[enemy.col][enemy.row] = undefined;
                        game.helper.removeItem(this.enemyList, enemy);
                        enemy.parent.removeChild(enemy);

                    }
                    //remove bullet
                    game.helper.removeItem(this.bulletList, bullet);
                    bullet.parent.removeChild(bullet);
                }
            }
        }

    };

    //situation when there is no path
    Board.prototype.pathMove = function (enemy) {

        this.star.findPath(enemy.row, enemy.col, enemy.target.row, enemy.target.col, (function (path) {
            try {
                enemy.moveTo(path[1].y, path[1].x);
            }
            catch (e) {
                var nearestTarget = new Array();
                for (var x = 0; x < this.buildingMap.length; x++) {
                    for (var y = 0; y < this.buildingMap[x].length; y++) {
                        try {
                            nearestTarget.push({ cost: cost(enemy, this.buildingMap[x][y]), building: this.buildingMap[x][y] })
                        }
                        catch (e) {
                            // nothing happens
                        }
                    }
                }
                nearestTarget = _.sortBy(nearestTarget, 'cost');
                //if (nearestTarget[0].building !== null || nearestTarget[0].building !== undefined) {


                    this.star.findPath(this.enemy.row, this.enemy.col, nearestTarget[0].building.row, nearestTarget[0].building.col, (function (subpath) {
                        if (subpath) {
                            if (subpath[1].y === this.target.building.col && subpath[1].x === this.target.building.row) {
                                this.enemy.stopAndAttack(this.target.building);
                            }
                            else {
                                this.enemy.moveTo(subpath[1].y, subpath[1].x);
                            }
                        }
                        else {
                            //checks targets above bellow and in front **ok to check hardcode in nearestTarget because there will be more than 4 towers to cause no path
                            if ((this.enemy.row === nearestTarget[0].building.row && this.enemy.col + 1 === nearestTarget[0].building.col) || (this.enemy.row === nearestTarget[1].building.row && this.enemy.col + 1 === nearestTarget[1].building.col) || (this.enemy.row === nearestTarget[2].building.row && this.enemy.col + 1 === nearestTarget[2].building.col) || (this.enemy.row === nearestTarget[3].building.row && this.enemy.col + 1 === nearestTarget[3].building.col)) {
                                var len = nearestTarget.length;
                                var j = 0;

                                //loop to get target in-front of enemy
                                while (j < len) {
                                    if (this.enemy.row === nearestTarget[j].building.row && this.enemy.col + 1 === nearestTarget[j].building.col) {
                                        var target_building = nearestTarget[j].building;
                                        break;
                                    }
                                    j++;
                                }
                                //target in front of enemy
                                if (this.enemy.stopAndAttack(target_building)) {
                                    /*if(subpath !== null)
                                    {
                                        enemy.moveTo(path[1].y, path[1].x);
                                        //this.enemy.moveTo(this.enemy.col + 1, this.enemy.row);
                                    }
                                    else
                                    {*/
                                    //enemy.moveTo(path[1].y, path[1].x);
                                    this.enemy.moveTo(this.enemy.col + 1, this.enemy.row);
                                    //}
                                }

                            }
                            else {
                                this.enemy.moveTo(this.enemy.col + 1, this.enemy.row);
                            }


                            //return;
                        }
                        //this.star.calculate();
                    }).bind({ enemy: this.enemy, target: nearestTarget[0] }));
                //}
            }
        }).bind({ buildingMap: this.buildingMap, star: this.star, enemy: enemy }));
    };

    Board.prototype.removeBuilding = function (building) {
        this.buildingMap[building.col][building.row] = undefined;
        this.removeChild(building);
    };

    Board.prototype.removeAllBuildings = function () {
        game.gold += saveGold;
        saveGold = 0;
        for (var i = 0; i < this.cols; i++) {
            for (var j = 0; j < this.rows; j++) {
                if (this.buildingMap[i][j]) {
                    this.removeBuilding(this.buildingMap[i][j]);
                }
            }
        }
    };


    // Event Handlings
    Board.prototype.readyToPlaceBuilding = function (e) {

        this.upcomingBuildingType = e.buildingType;
        this.isAddingBuilding = true;

    };
    Board.prototype.onMouseMove = function (e) {
        if (!this.isAddingBuilding) { return; }

        var pos = this.globalToLocal(e.stageX, e.stageY);
        // convert to tile row and col
        var rowCol = this.screenToRowCol(pos.x, pos.y);
        var pos = this.rowColToScreen(rowCol.row, rowCol.col);

        //this.selection.visible = true;

        // finally set the position
        //this.selection.x = pos.x;
        //this.selection.y = pos.y;
    };
    Board.prototype.onClick = function (e) {
        if (!this.isAddingBuilding) { return; }

        var pos = this.globalToLocal(e.stageX, e.stageY);
        var rowCol = this.screenToRowCol(pos.x, pos.y);
        var row = rowCol.row;
        var col = rowCol.col;

        // check bounds
        if (row < 0 || row >= this.rows || col < 0 || col >= this.cols) { return; }

        var placementOk = this.buildingPlacementCheck(e);
        if (placementOk === true) {
            this.addBuildingAtTile(this.upcomingBuildingType, col, row);

            this.isAddingBuilding = false;
            //this.selection.visible = false; 
        }

    };

    Board.prototype.buildingPlacementCheck = function (e) {

        var pos = this.globalToLocal(e.stageX, e.stageY);
        var rowCol = this.screenToRowCol(pos.x, pos.y);
        var row = rowCol.row;
        var col = rowCol.col;
        var defined, enemyDefined;
        defined = isUndefined(this.buildingMap, col, row);
        enemyDefined = isUndefined(this.enemyMap, col - 1, row);

        if (col <= 1)
        {
            return false;
        }
        else if (defined === true && enemyDefined === true) {
            return true;
        }       
        else
        {
            return false;
        }

    }
    Board.prototype.addBullet = function (bullet) {
        game.effectLayer.addChild(bullet);
        this.bulletList.push(bullet);
    };

    Board.prototype.removeAllBullets = function () {
        this.bulletList.length = 0;
        game.effectLayer.removeAllChildren();
    };

    game.Board = Board;

}).call(this, game, createjs, lib);