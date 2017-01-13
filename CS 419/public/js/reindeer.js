var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

;(function (game, cjs, lib) {

    function Reindeer() {
        game.Building.call(this);
        this.addChild(new lib.DeerTower());

        this.hp = 200;
        this.attackSpeed = 100;
        this.damageDeal = 40;
        this.ticks = 0;
        this.on('tick', this.tick);
        
    }

    Reindeer.prototype = Object.create(game.Building.prototype);

    Reindeer.prototype.summonIcebolt = function () {

        var bullet = new game.IceBolt((this.damageDeal));
        bullet.y = this.y + Math.random() * 20 - 10;
        bullet.x = this.x;
        this.parent.addBullet(bullet);
        cjs.Sound.play("attack_sound");
    };
    
    Reindeer.prototype.tick = function () {

        if (cjs.Ticker.getPaused()) {
            return;
        }

        this.ticks = this.ticks + 1;

        if (this.ticks % this.attackSpeed === 0) {
            this.summonIcebolt();
        }
    };

    Reindeer.cost = 50;
    game.Reindeer = Reindeer;

}).call(this,game,createjs,lib);