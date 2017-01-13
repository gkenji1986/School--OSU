var game = this.game || (this.game={});
var createjs = createjs || {};

;(function(game, cjs){
  game.helper = game.helper || {};
  game.helper.create2DArray = function(cols, rows, initialValue) {
    var array = new Array();
    for(var i=0; i<cols; i++) {
      array[i] = new Array();
      for (var j=0; j<rows; j++) {
        array[i][j] = initialValue;
      }
    }
    return array;
  };

  
  // remove an item from an array.
	game.helper.removeItem = function(array, target) {
	  for(var i=0, len=array.length; i<len; i++) {
		if (array[i] === target) {
		  array.splice(i, 1); // remove that target
		  return true;
		}
	  }
	  return false;
	};
}).call(this, game, createjs);