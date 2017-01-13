// Enemy moves down and attacks buildings
; (function (game, cjs, lib) {
    function Enemy() {
        cjs.Container.call(this);

        // these are default values. They can be overriden by instances.
        this.originalSpeed = 0.5; // speed may change over time. This one remains constant.
        this.deceleration = 0.05;
        this.hp = 10;
        this.damageDeal = 10;
        this.attackSpeed = 100; // smaller means faster
        this.time = 0;
        this.switch = true;
        this.blocked = false;
        this.dChangeUp = false;     //indicator for current direction up
        this.dChangeDown = false;   //indicator for current direction down
        this.dChangeBack = false;   //indicator for current direction back
        this.firstTime = true;      //indicator for stopping up/down/back
        this.UpDownFirstTime = true;    //indicator for resetting speed first time for up/down/back
        // properties
        this.speed = this.originalSpeed;
        this.gold = 50;
        this.score = this.gold * 2;

        this.on('tick', this.tick);
    }

    Enemy.prototype = Object.create(cjs.Container.prototype);

    Enemy.prototype.tick = function () {
        if (cjs.Ticker.getPaused()) { return; }

        // check if speed <0. Min allowed is 0.
        if (this.speed < 0) {
            this.speed = 0;
        } else {
            if (!this.blocked) {
                if (this.dChangeUp == false && this.dChangeDown == false) {
                    this.x += this.originalSpeed;
                    this.firstTime = true;
                    this.dChangeUp = false;
                    this.dChangeDown = false;
                    this.dChangeBack = false;
                }
                else if (this.dChangeDown == true && this.dChangeUp == false) {
                    if (this.y < game.height) {
                        this.y += this.originalSpeed;
                    }
                    //this.blocked = true;

                }
                else if (this.dChangeBack == true) {
                    this.x -= this.originalSpeed;
                    this.firstTime = true;

                }
                else if (this.dChangeDown == false && this.dChangeUp == true) {
                    this.y -= this.originalSpeed;
                    //this.blocked = true;

                }

                this.x = this.x % game.width;
            }
        }

    };

    Enemy.prototype.damage = function (damage) {
        this.hp = this.hp - damage;
    };

    /*Enemy.prototype.changeDirectionUp = function () {

        this.blocked = false;
        if (this.UpDownFirstTime == true) {
            this.speed = this.originalSpeed;
            this.UpDownFirstTime = false;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            //this.speed = this.originalSpeed;
            this.dChangeUp = true;
            this.UpDownFirstTime = true;
        }


        //this.y += this.speed;
    };
    Enemy.prototype.changeDirectionDown = function () {
        this.blocked = false;
        if (this.UpDownFirstTime == true) {
            this.speed = this.originalSpeed;
            this.UpDownFirstTime = false;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            // this.speed = this.originalSpeed;
            this.dChangeDown = true;
            this.UpDownFirstTime = true;
        }
    };*/
    Enemy.prototype.changeDirectionUp = function () {

        this.blocked = false;
        if (this.UpDownFirstTime == true) {
            this.speed = this.originalSpeed;
            this.UpDownFirstTime = false;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            this.dChangeUp = true;
            this.dChangeDown = false;
            this.UpDownFirstTime = true;
        }


        //this.y += this.speed;
    };
    Enemy.prototype.changeDirectionDown = function () {
        this.blocked = false;
        if (this.UpDownFirstTime == true) {
            this.speed = this.originalSpeed;
            this.UpDownFirstTime = false;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            this.dChangeUp = false
            this.dChangeDown = true;
            this.UpDownFirstTime = true;
        }
    };

    Enemy.prototype.changeDirectionRight = function () {
        this.blocked = false;
        this.speed = this.originalSpeed;
        this.dChangeBack = false;
        this.dChangeUp = false;
        this.dChangeDown = false;
    };

    Enemy.prototype.changeDirectionLeft = function () {
        this.blocked = false;
        this.speed = this.originalSpeed;
        this.dChangeBack = true;
        this.dChangeUp = false;
        this.dChangeDown = false;
    };

    Enemy.prototype.changeDirectionBack = function () {

        this.blocked = false;
        if (this.UpDownFirstTime == true) {
            this.speed = this.originalSpeed;
            this.UpDownFirstTime = false;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            // this.speed = this.originalSpeed;
            this.dChangeBack = true;
        }
    };

    Enemy.prototype.stopDirectionUpDown = function () {

        this.blocked = false;
        if ((this.blocked == false) && (this.firstTime == true)) {
            this.speed = this.originalSpeed + .2;
            this.firstTime = false;
            this.UpDownFirstTime = true;
        }
        this.speed -= this.deceleration;

        if (this.speed <= 0) {
            // this.speed = this.originalSpeed;
            this.dChangeDown = false;
            this.dChangeUp = false;

        }

        //this.y += this.speed;
    };

    /* Enemy.prototype.moveRight = function() {
         this.speed = this.originalSpeed;
         this.dChangeUp = false;
         this.dChangeDown = false;
         this.dChangeBack = false;
     }
 
     Enemy.prototype.moveLeft = function() {
         this.speed = -this.originalSpeed;
         this.dChangeUp = false;
         this.dChangeDown = false;
         this.dChangeBack = true;
     }
     Enemy.prototype.moveUp = function() {
         this.speed = this.originalSpeed;
         this.dChangeUp = true;
         this.dChangeDown = false;
         this.dChangeBack = false;
     }
     Enemy.prototype.moveDown = function() {
         this.dChangeUp = false;
         this.dChangeDown = true;
         this.dChangeBack = false;
     }*/

    Enemy.prototype.stopEnemyAndAttack = function (enemyBuilding) {

        this.speed -= this.deceleration;
        this.blocked = true;

        if (this.speed <= 0) {
            // this.speed = this.originalSpeed;
            this.dChangeDown = false;
            this.dChangeUp = false;

        }
        enemyBuilding.damage(this.damageDeal);
    }

    game.Enemy = Enemy;
}).call(this, game, createjs, lib);