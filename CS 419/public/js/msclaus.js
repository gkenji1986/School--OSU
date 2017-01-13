var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

// A very easy to kill enemy
(function (game, cjs, lib) {

    function MsClaus() {
        game.Enemy.call(this);

        this.addChild(new lib.Zombie5);

        this.originalSpeed = 1.0;
        this.deceleration = 0.1;
        this.hp = 500 * game.difficulty;
        this.damageDeal = 50 * game.difficulty;
        this.gold = 150 * game.difficulty;
        this.score = this.gold * 10 * game.difficulty;

        this.speed = this.originalSpeed;

    }
    MsClaus.prototype = Object.create(game.Enemy.prototype);

    game.MsClaus = MsClaus;

}).call(this, game, createjs, lib);