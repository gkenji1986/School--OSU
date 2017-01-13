var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, cjs, lib) {

    function Present(damageDeal) {

        cjs.Container.call(this);
        this.addChild(new lib.present_1());
        this.damageDeal = damageDeal || 1;

        this.on('tick', this.tick);
    }

    Present.prototype = Object.create(cjs.Container.prototype);
    Present.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }
        this.x = this.x - 3.5;
    };
    game.Present = Present;
}).call(this, game, createjs, lib);