var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, cjs, lib) {

    function IceBolt(damageDeal) {

        cjs.Container.call(this);
        this.addChild(new lib.iceBolt());
        this.damageDeal = damageDeal || 1;

        this.on('tick', this.tick);
    }

    IceBolt.prototype = Object.create(cjs.Container.prototype);
    IceBolt.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }
        this.x = this.x - 3.5;
    };
    game.IceBolt = IceBolt;
}).call(this, game, createjs, lib);