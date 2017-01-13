var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, cjs, lib) {

    function Bullet(damageDeal) {

        cjs.Container.call(this);
        this.addChild(new lib.Bullet());
        this.damageDeal = damageDeal || 1;

        this.on('tick', this.tick);
    }

    Bullet.prototype = Object.create(cjs.Container.prototype);
    Bullet.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }
        this.x = this.x - 3.5;
    };
    game.Bullet = Bullet;
}).call(this, game, createjs, lib);