const WIDTH = document.getElementById('gameCanvas').width;
const HEIGHT = document.getElementById('gameCanvas').height;
var stage, paused = false;
var ccDeer, ccZombie, ccHat, snowHat;
var i = 0;
function init() {
	loadAssets();
    createStage();
}

function createStage(e) {
    stage = new createjs.Stage(document.getElementById('gameCanvas'));
    createjs.Ticker.setFPS(60);
    createjs.Ticker.addEventListener("tick", gameRunning);

}

function gameRunning(event) {

    if (paused == false) {

		snowHair.x += 1;
        snowHair.y += .5;
        yetiHorn.x += 2;
        ccZombie.x += 2;
        ccZombie.y -= .5;

        stage.update(event);

    }

}

function pause() {
    console.log("Pause Clicked");
    if (paused == true) {
        document.getElementById("pause").innerHTML = "Pause";
        paused = false
    }
    else {
        paused = true;
        document.getElementById("pause").innerHTML = "Unpause";
    }
}