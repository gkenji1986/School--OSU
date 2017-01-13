var game = this.game || (this.game = {});
var createjs = createjs || {};
var waveIndicator = document.getElementById("waveIndicator")
// controlling waves
; (function (game, cjs) {

    game.waves = {};
    game.waves.nextWave = 0;
    game.waves.waveNum = 1;
    game.waves.isActive = false;

    game.waves.enemySummonOrders = ['Zombie1', 'Grinch', 'Critters', 'MsClaus'];
    game.waves.data = [
      {
          'Zombie1': 1,
          frequency: 10
      },
      {
          'Zombie1': 5,
          frequency: 100
      },
      {
          'Zombie1': 10,
          frequency: 100
      },
      {
          'Zombie1': 3,
          'Grinch': 3,
          frequency: 100
      },
      {
          'Zombie1': 3,
          'Grinch': 3,
          'Critters': 2,
          frequency: 100
      },
      {
          'Zombie1': 3,
          'Grinch': 4,
          'Critters': 3,
          frequency: 100
      },
      {
          'Zombie1': 4,
          'Grinch': 4,
          'Critters': 4,
          frequency: 100
      },
      {
          'Zombie1': 5,
          'Grinch': 5,
          'Critters': 5,
          "MsClaus" : 1,
          frequency: 100
      },
      {
          'Zombie1': 5,
          'Grinch': 5,
          'Critters': 5,
          "MsClaus": 1,
          frequency: 100
      },
      {
          'Zombie1': 6,
          'Grinch': 6,
          'Critters': 5,
          "MsClaus": 2,
          frequency: 100
      },
      {
          'Zombie1': 10,
          'Grinch': 10,
          'Critters': 10,
          "MsClaus": 3,
          frequency: 135
      },
      {
          'Zombie1': 12,
          'Grinch': 10,
          'Critters': 11,
          "MsClaus": 4,
          frequency: 135
      },
      {
          'Zombie1': 20,
          'Grinch': 11,
          'Critters': 15,
          "MsClaus": 3,
          frequency: 135
      },
      {
          'Zombie1': 20,
          'Grinch': 20,
          'Critters': 20,
          "MsClaus": 4,
          frequency: 125
      },
      {
          "MsClaus": 20,
          frequency: 150
      }
    ];

    game.waves.startWave = function () {

        if (this.nextWave <= this.data.length - 1)
        {
            document.getElementById("waveIndicator").style.visibility = "visible";
            document.getElementById("waveIndicator").innerHTML = "Wave: " + ((this.nextWave) + 1) + " Incoming!";
            cjs.Ticker.setPaused(true);
            setTimeout(function () {
                document.getElementById("waveIndicator").style.visibility = "hidden";
                cjs.Ticker.setPaused(false);
            }
            , 3000);

            this.currentWave = this.data[this.nextWave];
            this.isActive = true;

            this.enemiesSummoned = 0;
        }
              
    };

    game.waves.waveCleared = function () {
		
        this.nextWave += 1;

        if (this.nextWave <= this.data.length - 1)
        {
            this.startWave();
        }
        else
        {
            this.stopWave();
            game.waves.start = true;
        }
    };

    game.waves.stopWave = function () {
        document.getElementById("waveIndicator").style.visibility = "visible";
        document.getElementById("waveIndicator").innerHTML = "ALL WAVES COMPLETE";
        document.getElementById("waveIndicator").style.visibility = "hidden";
    }
    game.waves.tick = function () {
        if (!this.isActive) { return; } 

        if (cjs.Ticker.getTicks() % this.currentWave.frequency === 0)
        {
        
            var accumunateTargetCount = 0;

            var len = this.enemySummonOrders.length;
            for (var i = 0; i < len; i++)
            {
                var enemyType = this.enemySummonOrders[i];
                var targetCount = this.currentWave[enemyType] || 0;
                accumunateTargetCount += targetCount;

                if (this.enemiesSummoned < accumunateTargetCount)
                {
                    break;
                }
            }

            if (this.enemiesSummoned >= accumunateTargetCount)
            {
                this.isActive = false;
            }
            else
            {
                  // summon the enemy
                game.boardLayer.addEnemy(enemyType);
                this.enemiesSummoned += 1;
            }
        }
    };

}).call(this, game, createjs);