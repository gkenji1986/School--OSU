var ccDeer, ccZombie, snowHat, ccHat, snowTux, snowHair, redTurret, greenTurret, whiteTurret;
var yetiGreen, yetiHorn, yetiGrey;
function loadSprites(queue) {
    //console.log(queue.getResult("deer"));

    var deerSheet = new createjs.SpriteSheet({
        "framerate": 20,
        "images": [queue.getResult("deer")],
        "frames": { width: 232, height: 411, count: 10, regX: 118, regY: 208, spacing: 0, margin: 8 },
        "animations": {
            "walk": [0, 9],
        }
    });

    var candyCaneSheet = new createjs.SpriteSheet({
        "framerate": 8,
        "images": [queue.getResult("candyCane")],
        "frames": { width: 205, height: 487, count: 9, regX: 118, regY: 208, spacing: 5.75, margin: 9 },
        "animations": {
            "walk": [0, 8],
        }
    });

    var zombieSheet = new createjs.SpriteSheet({
        "framerate": 8,
        "images": [queue.getResult("zombie")],
        "frames": { width: 232, height: 420, count: 9, regX: 118, regY: 208, spacing: 23, margin: 0 },
        "animations": {
            "walk": [0, 8],
        }
    });

    var yetiGreenSheet = new createjs.SpriteSheet({
        "framerate": 16,
        "images": [queue.getResult("yetiGreen")],
        "frames": { width: 220, height: 266, count: 9, regX: 118, regY: 208, spacing: 12, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }

    });

    var yetiHornSheet = new createjs.SpriteSheet({
        "framerate": 10,
        "images": [queue.getResult("yetiHorn")],
        "frames": { width: 220, height: 280, count: 9, regX: 118, regY: 208, spacing: 6, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }
    });

    var yetiGreySheet = new createjs.SpriteSheet({
        "framerate": 11,
        "images": [queue.getResult("yetiGrey")],
        "frames": { width: 220, height: 250, count: 9, regX: 118, regY: 208, spacing: 6, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }
    });


    var snowTuxSheet = new createjs.SpriteSheet({
        "framerate": 10,
        "images": [queue.getResult("snowTux")],
        "frames": { width: 240, height: 370, count: 9, regX: 118, regY: 208, spacing: 14, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }
    });

    var snowHatSheet = new createjs.SpriteSheet({
        "framerate": 12,
        "images": [queue.getResult("snowHat")],
        "frames": { width: 240, height: 380, count: 9, regX: 118, regY: 208, spacing: 16, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }

    });

    var snowHairSheet = new createjs.SpriteSheet({
        "framerate": 16,
        "images": [queue.getResult("snowHair")],
        "frames": { width: 240, height: 285, count: 9, regX: 118, regY: 208, spacing: 10, margin: 0 },
        "animations": {
            "walk": [0, 7],
        }

    });

    var redTurretSheet = new createjs.SpriteSheet({
        "framerate": 60,
        "images": [queue.getResult("redTurret")],
        "frames": { width: 128, height: 128, count: 64, regX: 64, regY: 64, spacing: 0, margin: 0 },
        "animations": {
            "rotate": [0, 63],
        }

    });

    var greenTurretSheet = new createjs.SpriteSheet({
        "framerate": 60,
        "images": [queue.getResult("greenTurret")],
        "frames": { width: 128, height: 128, count: 64, regX: 64, regY: 64, spacing: 0, margin: 0 },
        "animations": {
            "rotate": [0, 63],
        }

    });

    var whiteTurretSheet = new createjs.SpriteSheet({
        "framerate": 60,
        "images": [queue.getResult("whiteTurret")],
        "frames": { width: 128, height: 128, count: 64, regX: 64, regY: 64, spacing: 0, margin: 0 },
        "animations": {
            "rotate": [0, 63],
        }

    });
    /**************ERASE THESE BELOW --- FOR DEMO PURPOSES ONLY --- ************/

    ccDeer = new createjs.Sprite(deerSheet, "walk");
    ccDeer.y = 350;
    ccDeer.x = 200;
    ccDeer.scaleX = .23;
    ccDeer.scaleY = .23;
    stage.addChild(ccDeer);

    ccHat = new createjs.Sprite(candyCaneSheet, "walk");
    ccHat.y = 350;
    ccHat.x = 300;
    ccHat.scaleX = .23;
    ccHat.scaleY = .23;
    stage.addChild(ccHat);

    ccZombie = new createjs.Sprite(zombieSheet, "walk");
    ccZombie.y = 350;
    ccZombie.x = 100;
    ccZombie.scaleX = .23;
    ccZombie.scaleY = .23;
    stage.addChild(ccZombie);

    snowTux = new createjs.Sprite(snowTuxSheet, "walk");
    snowTux.y = 100;
    snowTux.x = 100;
    snowTux.scaleX = .25;
    snowTux.scaleY = .25;
    stage.addChild(snowTux);

    snowHat = new createjs.Sprite(snowHatSheet, "walk");
    snowHat.y = 100;
    snowHat.x = 200;
    snowHat.scaleX = .25;
    snowHat.scaleY = .25;
    stage.addChild(snowHat);

    snowHair = new createjs.Sprite(snowHairSheet, "walk");
    snowHair.y = 100;
    snowHair.x = 300;
    snowHair.scaleX = .25;
    snowHair.scaleY = .25;
    stage.addChild(snowHair);

    yetiGreen = new createjs.Sprite(yetiGreenSheet, "walk");
    yetiGreen.y = 240;
    yetiGreen.x = 100;
    yetiGreen.scaleX = .25;
    yetiGreen.scaleY = .25;
    stage.addChild(yetiGreen);

    yetiHorn = new createjs.Sprite(yetiHornSheet, "walk");
    yetiHorn.y = 240;
    yetiHorn.x = 200;
    yetiHorn.scaleX = .25;
    yetiHorn.scaleY = .25;
    stage.addChild(yetiHorn);


    yetiGrey = new createjs.Sprite(yetiGreySheet, "walk");
    yetiGrey.y = 240;
    yetiGrey.x = 300;
    yetiGrey.scaleX = .25;
    yetiGrey.scaleY = .25;
    stage.addChild(yetiGrey);

    redTurret = new createjs.Sprite(redTurretSheet, "rotate");
    redTurret.y = 460;
    redTurret.x = 100;
    redTurret.scaleX = .5;
    redTurret.scaleY = .5;
    stage.addChild(redTurret);

    greenTurret = new createjs.Sprite(greenTurretSheet, "rotate");
    greenTurret.y = 460;
    greenTurret.x = 200;
    greenTurret.scaleX = .5;
    greenTurret.scaleY = .5;
    stage.addChild(greenTurret);
    
    whiteTurret = new createjs.Sprite(whiteTurretSheet, "rotate");
    whiteTurret.y = 460;
    whiteTurret.x = 300;
    whiteTurret.scaleX = .5;
    whiteTurret.scaleY = .5;
    stage.addChild(whiteTurret);
    stage.update();


}
