var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

;(function (game, cjs, lib) {

    function Santa() {
        game.Building.call(this);
        this.addChild(new lib.Santa());

        this.hp = 300;
        this.attackSpeed = 150;
        this.damageDeal = 150;

        this.ticks = 0;
        this.on('tick', this.tick);
        
    }

    Santa.prototype = Object.create(game.Building.prototype);

    Santa.prototype.summonPresent = function () {

        var bullet = new game.Present((this.damageDeal));
        bullet.y = this.y + Math.random() * 20 - 10;
        bullet.x = this.x;
        this.parent.addBullet(bullet);
        cjs.Sound.play("attack_sound");
    };
    
    Santa.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }

        this.ticks += 1;

        if (this.ticks % this.attackSpeed === 0) {
            this.summonPresent();
        }
    };

    Santa.cost = 150;
    game.Santa = Santa;

}).call(this, game, createjs, lib);