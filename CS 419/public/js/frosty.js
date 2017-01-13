var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

;(function (game, cjs, lib) {

    function Frosty() {
        game.Building.call(this);
        this.addChild(new lib.YetiCC());

        this.hp = 150;
        this.attackSpeed = 125;
        this.attackRange = 300;
        this.damageDeal = 100;
        this.ticks = 0;
        this.on('tick', this.tick);
        
    }

    Frosty.prototype = Object.create(game.Building.prototype);

    Frosty.prototype.summonSnowball = function () {

        var bullet = new game.SnowBall((this.damageDeal));
        bullet.y = this.y + Math.random() * 20 - 10;
        bullet.x = this.x;
        this.parent.addBullet(bullet);
        cjs.Sound.play("attack_sound");
    };
    
    Frosty.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }

        this.ticks += 1;

        if (this.ticks % this.attackSpeed === 0) {
            this.summonSnowball();
        }
    };

    Frosty.cost = 70;
    game.Frosty = Frosty;

}).call(this, game, createjs, lib);