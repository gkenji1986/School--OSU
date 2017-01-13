var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

// A very easy to kill enemy
(function (game, cjs, lib) {

    function Grinch() {
        game.Enemy.call(this);

        this.addChild(new lib.Zombie2);

        this.originalSpeed = 2;
        this.deceleration = 0.25;
        this.hp = 200 * game.difficulty;
        this.gold = 100 * game.difficulty;
        this.score = this.gold * 2 * game.difficulty;
        this.damageDeal = 10 * game.difficulty;
        this.speed = this.originalSpeed;

    }
    Grinch.prototype = Object.create(game.Enemy.prototype);

    game.Grinch = Grinch;

}).call(this, game, createjs, lib);