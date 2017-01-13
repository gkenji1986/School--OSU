var game = this.game || (this.game={});
var createjs = createjs || {};

;(function(game, cjs){

  var addButtons = document.querySelectorAll('.add-button');

  // indicators
  var lives = document.getElementById('lives');
  var gold = document.getElementById('gold');
  var waves = document.getElementById('waves');
  var score = document.getElementById('score');

  for(var i=0, len=addButtons.length; i<len; i++) {
    var button = addButtons[i];
    button.onmousedown = function(e) {
      if (cjs.Ticker.getPaused()) { return; }
      var buildingType = this.dataset.type;

      // have enough energy
      var cost = game[buildingType].cost;

      if (cost && game.gold >= cost) {
          if (game.boardLayer.isAddingBuilding === false)
          {
              saveGold += (cost / 2)
			  game.gold -= cost;
			  var event = new cjs.Event('readyToPlaceBuilding');
              event.buildingType = buildingType;
              game.dispatchEvent(event);
          }
        
      } else { // no enough energy

      }

    }
  }

  function tick() {
    lives.textContent = game.lives;
    gold.textContent = game.gold;
    waves.textContent = game.waves.nextWave +1;
    score.textContent = game.score;
  }

  cjs.Ticker.addEventListener('tick', tick);


}).call(this, game, createjs);
