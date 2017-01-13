var game = this.game || (this.game={});
var createjs = createjs || {};
var lib = lib || {};

// A very easy to kill enemy
(function(game, cjs, lib){

  function Zombie1(){
    game.Enemy.call(this);

    this.addChild(new lib.Zombie1);

    this.originalSpeed = 2;
    this.deceleration = 0.25;
    this.hp = 100 * game.difficulty;
    this.damageDeal = 10 * game.difficulty;
    this.gold = 50 * game.difficulty;
    this.score = this.gold * 2 * game.difficulty;

    this.speed = this.originalSpeed;

  }
  Zombie1.prototype = Object.create(game.Enemy.prototype);

  game.Zombie1 = Zombie1;

}).call(this, game, createjs, lib);