var game = this.game || (this.game = {});
var createjs = createjs || {};
var lib = lib || {};

(function (game, createjs, lib) {

    function Tower() {
        createjs.Container.call(this);

        this.damage = 0;
        this.attackRange = 9999;
        this.attackSpeed = 9999;
        this.target = null;
        this.cooldown = 4;
        this.kills = 0;
        this.angle = 0;
    }

    inhert(Tower, Entity);

    Tower.prototype.rotateSpeed = Math.PI / 10;
    Tower.prototype.getShootTolerance = function () {
        return this.rotateSpeed;
    }

    Tower.prototype.shoot = function () {

        var speed = 100;
        var mat = [Math.cos(this.angle), Math.sin(this.angle), -Math.sin(this.angle), Math.cos(this.angle)];

        for(var i = -1; i <=1 ; i += 2)
        {
            var offset = mattvp(mat, [0, i * 5]);
            var b = new Bullet(this.game, this.x + offset[0], this.y + offset[1], speed * mat[0], speed * mat[1], this.angle, this);
            b.damage = Math.pow(1.2, this.level);
            this.game.addBullet(b);
        }
        this.cooldown = this.getCooldownTime();
    }

    Tower.prototype.getCooldownTime = function () {
        return this.cooldown;
    }


    Tower.prototype = Object.create(createjs.Container.prototype);
    Tower.cost = 10;
    game.Tower = Tower;
}).call(this, game, createjs, lib);
