(function (window) {

    window.game = window.game || {}

    function EnemyHealthBar(maxHP) {
        this.maxHP = this.HP = maxHP;
        this.initialize();
    }

    var e = EnemyHealthBar.prototype = new createjs.Container();

    e.Container_initialize = e.initialize;

    e.progressBar = null;
    e.maxHP = null;
    e.HP = null;
    e.hptext = null;

    e.initialize = function () {
        this.Container_initialize();
        this.addHealthBar();
        this.addHP();
    }

    e.addHealthBar = function () {
        var barXOffset = 10;
        var enemyBar = new createjs.Sprite(spritesheet, 'enemyBar');
        var enemyBarBounds = enemyBar.getBounds();
        var barBG = new createjs.Shape();
        barBG.graphics.beginFill('b6b6b6').drawRect(0, 0, enemyBarBounds.width, enemyBarBounds.height);
        this.progressBar = new createjs.Shape();
        this.progressBar.graphics.beginFill('c14545').drawRect(0, 0, enemyBarBounds.width - barXOffset, enemyBarBounds.height);
        this.progressBar.x = barXOffset;
        this.addChild(barBG, this.progressBar, enemyBar);
    }

    e.addHP = function () {
        var txtXOffest = 8;
        var yPOS = 13;
        this.hptext = new createjs.BitmapText(this.HP.toString(), spritesheet);
        this.hptext.letterSpacing = 1;
        this.hptext.x = this.getBounds().width / 2 - txtXOffest;
        this.hptext.y = yPOS;
        this.addChild(this.hptext);
    }

    e.updateHP = function (HP) {
        var percentage;

        this.HP = this.HP - HP < 0 ? 0 : this.HP - HP;
        percentage = this.HP / this.maxHP;
        this.removeChild(this.hptext);
        this.addHP();
        createjs.Tween.get(this.progressBar).to({ scaleX: percentage }, 400);
    }

    window.game.EnemyHealthBar = EnemyHealthBar;

}(window));