var game = this.game || (this.game={});
var createjs = createjs || {};
var lib = lib || {};

;(function(game, cjs, lib){

  function CCTower1(){
    game.Building.call(this);
    
    // graphics
    this.addChild(new lib.CCTower1());

    // override
    this.hp = 150;
    this.damageDeal = 25;
    this.attackSpeed = 75;
    this.ticks = 0;
    this.on('tick', this.tick);
  }

  CCTower1.prototype = Object.create(game.Building.prototype);

  CCTower1.prototype.summonBullet = function () {
      var bullet = new game.Bullet(this.damageDeal);
      bullet.x = this.x + Math.random() * 20 - 10;
      bullet.y = this.y;
      this.parent.addBullet(bullet);
      cjs.Sound.play("attack_sound");
  };

  CCTower1.prototype.tick = function () {
      if (cjs.Ticker.getPaused()) {
          return;
      }
      this.ticks += 1;

      if (this.ticks % this.attackSpeed === 0) {
          this.summonBullet();
      }
  };

  CCTower1.cost = 30;
  game.CCTower1 = CCTower1;

}).call(this, game, createjs, lib);