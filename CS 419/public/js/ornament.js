var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, cjs, lib) {

    function Ornament(damageDeal) {

        cjs.Container.call(this);
        this.addChild(new lib.ornament_1());
        this.damageDeal = damageDeal || 1;

        this.on('tick', this.tick);
    }

    Ornament.prototype = Object.create(cjs.Container.prototype);
    Ornament.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }
        this.x = this.x - 3.5;
    };
    game.Ornament = Ornament;
}).call(this, game, createjs, lib);