var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

;(function (game, cjs, lib) {

    function Elves() {
        game.Building.call(this);
        this.addChild(new lib.YetiGrey());

        this.hp = 100;
        this.attackSpeed = 25;
        this.damageDeal = 10;
        this.ticks = 0;
        this.on('tick', this.tick);
        
    }

    Elves.prototype = Object.create(game.Building.prototype);

    Elves.prototype.summonOrnament = function () {

        var bullet = new game.Ornament((this.damageDeal));
        bullet.y = this.y + Math.random() * 20 - 10;
        bullet.x = this.x;
        this.parent.addBullet(bullet);
        cjs.Sound.play("attack_sound");
    };
    
    Elves.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }

        this.ticks += 1;

        if (this.ticks % this.attackSpeed === 0) {
            this.summonOrnament();
        }
    };

    Elves.cost = 100;
    game.Elves = Elves;

}).call(this, game, createjs, lib);