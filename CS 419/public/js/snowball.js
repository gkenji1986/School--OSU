var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, cjs, lib) {

    function SnowBall(damageDeal) {

        cjs.Container.call(this);
        this.addChild(new lib.snowball_1());
        this.damageDeal = damageDeal || 1;

        this.on('tick', this.tick);
    }

    SnowBall.prototype = Object.create(cjs.Container.prototype);
    SnowBall.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }
        this.x = this.x - 3.5;
    };
    game.SnowBall = SnowBall;
}).call(this, game, createjs, lib);