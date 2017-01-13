var assert = require("assert");
var board = require("./tests/board.js")();
var enemy = require("./tests/enemy.js")();

// screenToRowCol tests
board.tileWidth = 128;
board.tileHeight = 128;
assert.equal(board.tileWidth, 128, "tileWidth failure.");
assert.equal(board.tileHeight, 128, "tileHeight failure.");

console.log("Starting screenToRowCol");
for(var x = 0; x < 1280; x++) {
	for(var y = 0; y < 720; y++) {
		var z = board.screenToRowCol(x, y);
		assert.equal(z.col, Math.floor(x / board.tileWidth), "tileWidth failure @ " + x);
		assert.equal(z.row, Math.floor(y / board.tileHeight), "tileHeight failure @ " + y);
	}
}
console.log("Finished screenToRowCol");

/*console.log("Starting rowColToScreen");
for(var x = 0; x < 100; x++) {
	for(var y = 0; y < 100; y++) {
		var z = board.rowColToScreen(x, y);
		assert.equal(z.x, z*board.tileWidth, "tileWidth failure @ " + x);
		assert.equal(z.y, z*board.tileHeight, "tileHeight failure @ " + y);
	}
}
console.log("Finished rowColToScreen");*/

// areEnemiesCleared tests
console.log("Starting areEnemiesCleared");
board.enemyList = new Array();
assert.equal(board.areEnemiesCleared(), true, "Enemy cleared failure");

board.enemyList.push({test: 0});
assert.equal(board.areEnemiesCleared(), false, "Enemy cleared failure");

board.enemyList.pop({test: 0});
assert.equal(board.areEnemiesCleared(), true, "Enemy cleared failure");
console.log("Ending areEnemiesCleared Tests");

// isUndefined tests
console.log("Starting isUndefined");
var arrayTest = new Array();
for(var x = 0; x < 1000; x++) {
	arrayTest[x] = new Array();
	for(var y = 0; y < 1000; y++) {
		var r = Math.floor((Math.random() * 2) % 2);

		if(r) {
			var local = arrayTest[x][y] = undefined;
		} else {
			var local = arrayTest[x][y] = 0;
		}
		assert.equal(board.isUndefined(arrayTest, x, y), arrayTest[x][y] == undefined, "isUndefined Failure");
	}
}
delete arrayTest;
console.log("Ending isUndefined Tests");

// checkWithinBounds tests
console.log("Starting checkWithinBounds");
board.cols = 100;
board.rows = 100;
var arrayTest = new Array();
for(var x = -1000; x < 1000; x++) {
	arrayTest[x] = new Array();
	for(var y = -1000; y < 1000; y++) {
		assert.equal(board.checkWithinBounds(x, y), (x >= 0 && x <= board.cols) && (y >= 0 && y <= board.rows), "checkWithinBounds Failure @ " + x, y);
	}
}
delete arrayTest;
console.log("Ending checkWithinBounds Tests");

// generateMatrix tests
console.log("Starting generateMatrix");
var arrayTest = new Array();
var tester = new Array();
for(var x = 0; x < 1000; x++) {
	arrayTest[x] = new Array();
	tester[x] = new Array();
	for(var y = 0; y < 1000; y++) {
		var r = Math.floor((Math.random() * 2) % 2);
		arrayTest[x][y] = r;
		tester[x][y] = r ? true : undefined;
		delete r;
	}
}
assert.deepEqual(board.generateMatrix(tester), arrayTest, "generateMatrix Failure");
delete arrayTest;
delete tester;
console.log("Ending generateMatrix Tests");

// damage tests
console.log("Starting damage");
enemy.hp = 0;
for(var x = -1000; x < 1000; x++) {
	var hp = enemy.hp - x;
	enemy.damage(x);
	assert.equal(enemy.hp, hp, "HP Failure");
	delete hp;
}
console.log("Ending damage Tests");

var direction = {
	UP: 2,
	DOWN: 3,
	RIGHT: 5,
	LEFT: 7,
	STOP: 11
};

// top right
console.log("Starting Right Tests");
enemy.row = 0;
enemy.col = 0;
enemy.moveTo(1, 0); // move right 
assert.equal(enemy.direction, direction.RIGHT, "Move Right Failure");

var e = enemy.originalSpeed = 1;
var x = enemy.x = 500;
var y = enemy.y = 500;
enemy.moveRight();
assert.equal(enemy.x, x+e, "Move Right Failure");
assert.equal(enemy.y, y, "Move Right Failure");
delete e, x, y;
console.log("Ending Right Tests");

// top down
console.log("Starting Down Tests");
enemy.row = 0;
enemy.col = 0;
enemy.moveTo(0, 1); // move down 
assert.equal(enemy.direction, direction.DOWN, "Move Down Failure");

var e = enemy.originalSpeed = 1;
var x = enemy.x = 500;
var y = enemy.y = 500;
enemy.moveDown();
assert.equal(enemy.x, x, "Move Down Failure");
assert.equal(enemy.y, y+e, "Move Down Failure");
delete e, x, y;
console.log("Ending Down Tests");

// top up
console.log("Starting Up Tests");
enemy.row = 1;
enemy.col = 0;
enemy.moveTo(0, 0); // move up 
assert.equal(enemy.direction, direction.UP, "Move Up Failure");

var e = enemy.originalSpeed = 1;
var x = enemy.x = 500;
var y = enemy.y = 500;
enemy.moveUp();
assert.equal(enemy.x, x, "Move Up Failure");
assert.equal(enemy.y, y-e, "Move Up Failure");
delete e, x, y;
console.log("Ending Up Tests");

// top left
console.log("Starting Left Tests");
enemy.row = 0;
enemy.col = 1;
enemy.moveTo(0, 0); // move up 
assert.equal(enemy.direction, direction.LEFT, "Move Left Failure");

var e = enemy.originalSpeed = 1;
var x = enemy.x = 500;
var y = enemy.y = 500;
enemy.moveLeft();
assert.equal(enemy.x, x-e, "Move Left Failure");
assert.equal(enemy.y, y, "Move Left Failure");
delete e, x, y;
console.log("Ending Left Tests");

// stopAndAttack tests
console.log("Starting Stop Tests");
var e = enemy.originalSpeed = 1;
var x = enemy.x = 500;
var y = enemy.y = 500;
enemy.stopAndAttack();
assert.equal(enemy.x, x+e, "Move Right Failure");
assert.equal(enemy.y, y, "Move Right Failure");
delete e, x, y;

enemy.stopAndAttack(true);
assert.equal(enemy.direction, direction.STOP, "STOP Failure");
assert.equal(enemy.enemy, true, "Enemy Failure");
console.log("Ending Stop Tests");
