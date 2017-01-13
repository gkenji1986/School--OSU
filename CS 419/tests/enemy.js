module.exports = function() {
    var enemy = {};
    var direction = {
		UP: 2,
		DOWN: 3,
		RIGHT: 5,
		LEFT: 7,
		STOP: 11
	};
	var game ={ height: 720 };

	enemy.damage = function (damage) {
        this.hp = this.hp - damage;
    };

	enemy.tick = function () {
		if (cjs.Ticker.getPaused() == true)
		{
			console.log("PAUSING ENEMIES");
			return;
		}
		if(([63, 64, 65].indexOf(this.y % (game.height / 5)) > -1) && ([63, 64, 65].indexOf(this.x % (game.width / 9)) > -1)) {
			switch(this.direction) {
				case direction.UP:
					this.moveUp();
					break;
				case direction.DOWN:
					this.moveDown();
					break;
				case direction.RIGHT:
					this.moveRight();
					break;
				case direction.LEFT:
					this.moveLeft();
					break;
				case direction.STOP:
					this.stopMovement();
					break;
			}	
		} else {
			switch(this.currentDirection) {
				case direction.UP:
					this.moveUp();
					break;
				case direction.DOWN:
					this.moveDown();
					break;
				case direction.RIGHT:
					this.moveRight();
					break;
				case direction.LEFT:
					this.moveLeft();
					break;
				case direction.STOP:
					this.stopMovement();
					break;
			}
		}
	}
	enemy.moveTo = function(col, row) {
		if(this.row > row) {
			this.direction = direction.UP;
		} else if(this.row < row) {
			this.direction = direction.DOWN;
		} else if(this.col > col) {
			this.direction = direction.LEFT;
		} else {
			this.direction = direction.RIGHT;
		}
	}
	enemy.moveUp = function() {
		if(this.y < 65) {
			this.y = this.y;
		} else {
			this.currentDirection = direction.UP;
			this.x = this.x;
			this.y -= this.originalSpeed;
			this.col = Math.floor(this.x / 128);
			this.row = Math.floor(this.y / 128);
		}
	}
	enemy.moveDown = function() {
		if(this.y > (game.height - 65)) {
			this.y = this.y;
		} else {
			this.currentDirection = direction.DOWN;
			this.x = this.x;
			this.y += this.originalSpeed;
			this.col = Math.floor(this.x / 128);
			this.row = Math.floor(this.y / 128);
		}
	}
	enemy.moveRight = function() {
		this.currentDirection = direction.RIGHT;
		this.x += this.originalSpeed;
		this.y = this.y;
		this.col = Math.floor(this.x / 128);
		this.row = Math.floor(this.y / 128);
	}
	enemy.moveLeft = function() {
		this.currentDirection = direction.LEFT;
		this.x -= this.originalSpeed;
		this.y = this.y;
		this.col = Math.floor(this.x / 128);
		this.row = Math.floor(this.y / 128);
	}
	enemy.stopMovement = function() {
		try {
			this.x = this.x;
			this.y = this.y;
			this.currentDirection = direction.STOP;
			this.enemy.damage(this.damageDeal);
		} catch(e) {
			this.moveRight();
		}
	}
	enemy.stopAndAttack = function(enemyBuilding) {
		try {
			if(!enemyBuilding) {
				throw 0;
			} else	{
				this.direction = direction.STOP;
				this.enemy = enemyBuilding;
			}
		} catch(e) {
			this.moveRight();
		}
	}
	return enemy;
};	