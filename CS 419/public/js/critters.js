var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

// A very easy to kill enemy
(function (game, cjs, lib) {

    function Critters() {
        game.Enemy.call(this);

        this.addChild(new lib.Zombie4);

        this.originalSpeed = 3;
        this.deceleration = .3;
        this.hp = 150 * game.difficulty;
        this.damageDeal = 20 * game.difficulty;
        this.gold = 150 * game.difficulty;
        this.score = this.gold * 3 * game.difficulty;

        this.speed = this.originalSpeed;

    }
    Critters.prototype = Object.create(game.Enemy.prototype);

    game.Critters = Critters;

}).call(this, game, createjs, lib);