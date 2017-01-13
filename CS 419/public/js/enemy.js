; (function (game, cjs, lib) {
	var direction = {
		UP: 2,
		DOWN: 3,
		RIGHT: 5,
		LEFT: 7,
		STOP: 11
	};

	function Enemy() {
		cjs.Container.call(this);

		// these are default values. They can be overriden by instances.
		this.originalSpeed = 1; // speed may change over time. This one remains constant.
		this.deceleration = 0.05;
		this.hp = 10;
		this.damageDeal = 10;
		this.attackSpeed = 100; // smaller means faster
		this.time = 0;
		this.switch = true;
		this.blocked = false;
		this.speed = this.originalSpeed;
		this.gold = 50;
		this.score = this.gold * 2;
		this.direction = direction.RIGHT;
		this.currentDirection = direction.RIGHT;
		this.row = 0;
		this.col = 0;
		this.x = 0;
		this.y = 0;/*
		this.visited = new Array();
		this.path = new Array();*/
		this.on('tick', this.tick.bind(this));
		this.on('dblclick', function(event) {
			console.log(this);
		});

	}

	Enemy.prototype = Object.create(cjs.Container.prototype);

	Enemy.prototype.damage = function (damage) {
        this.hp = this.hp - damage;
    };
	Enemy.prototype.tick = function () {
		if (cjs.Ticker.getPaused() == true)
		{
			console.log("PAUSING ENEMIES");
			return;
		}
		if(([63, 64, 65].indexOf(this.y % (game.height / 5)) > -1) && ([63, 64, 65].indexOf(this.x % (game.width / 9)) > -1)) {
			switch(this.direction) {
				case direction.UP:
					this.moveUp();
					break;
				case direction.DOWN:
					this.moveDown();
					break;
				case direction.RIGHT:
					this.moveRight();
					break;
				case direction.LEFT:
					this.moveLeft();
					break;
				case direction.STOP:
					this.stopMovement();
					break;
			}	
		} else {
			switch(this.currentDirection) {
				case direction.UP:
					this.moveUp();
					break;
				case direction.DOWN:
					this.moveDown();
					break;
				case direction.RIGHT:
					this.moveRight();
					break;
				case direction.LEFT:
					this.moveLeft();
					break;
				case direction.STOP:
					this.stopMovement();
					break;
			}
		}
	}
	Enemy.prototype.moveTo = function(col, row) {
		if(this.row > row) {
			this.direction = direction.UP;
		} else if(this.row < row) {
			this.direction = direction.DOWN;
		} else if(this.col > col) {
			this.direction = direction.LEFT;
		} else {
			this.direction = direction.RIGHT;
		}
	}
	Enemy.prototype.moveUp = function() {
		if(this.y < 65) {
			this.y = this.y;
		} else {
			this.currentDirection = direction.UP;
			this.x = this.x;
			this.y -= this.originalSpeed;
			this.col = Math.floor(this.x / 128);
			this.row = Math.floor(this.y / 128);
		}
	}
	Enemy.prototype.moveDown = function() {
		if(this.y > (game.height - 65)) {
			this.y = this.y;
		} else {
			this.currentDirection = direction.DOWN;
			this.x = this.x;
			this.y += this.originalSpeed;
			this.col = Math.floor(this.x / 128);
			this.row = Math.floor(this.y / 128);
		}
	}
	Enemy.prototype.moveRight = function() {
		this.currentDirection = direction.RIGHT;
		this.x += this.originalSpeed;
		this.y = this.y;
		this.col = Math.floor(this.x / 128);
		this.row = Math.floor(this.y / 128);
	}
	Enemy.prototype.moveLeft = function() {
		this.currentDirection = direction.LEFT;
		this.x -= this.originalSpeed;
		this.y = this.y;
		this.col = Math.floor(this.x / 128);
		this.row = Math.floor(this.y / 128);
	}
	Enemy.prototype.stopMovement = function() {
		try {
			this.x = this.x;
			this.y = this.y;
			this.currentDirection = direction.STOP;
			this.enemy.damage(this.damageDeal);
		} catch(e) {
			this.moveRight();
		}
	}
	Enemy.prototype.stopAndAttack = function(enemyBuilding) {
		try {
			if(!enemyBuilding) {
				throw 0;
			} else	{
				this.direction = direction.STOP;
				this.enemy = enemyBuilding;
			}
		} catch(e) {
			this.moveRight();
		}
	}	
	game.Enemy = Enemy;
}).call(this, game, createjs, lib);