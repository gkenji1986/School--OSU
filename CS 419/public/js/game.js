var game = this.game || (this.game = {});
var createjs = createjs || {};
var zombie, ccTower, Santa, Elves, Reindeer, Frosty;
var pause = false;
var loadGame = false;
var hard_mode = false;
var saveGold = 0;

(function (game, cjs) {

    game.load = function () {
        // load bitmap assets before starts the game
        var loader = new createjs.LoadQueue(false);       
        loader.addEventListener("fileload", function (e) {
            if (e.item.type === "image") { images[e.item.id] = e.result; }  // assgin to images object for assets.js to use
        });
        loader.addEventListener("complete", game.menu);
        loader.loadManifest(lib.properties.manifest);
        game.sound();
    }

    game.menu = function () {
        cjs.EventDispatcher.initialize(game); // allow the game object to listen and dispatch custom events.
  
        game.canvas = document.getElementById('canvas');
        game.width = document.getElementById('canvas').width;
        game.height = document.getElementById('canvas').height;

        game.stage = new cjs.Stage(game.canvas);

        var bgLayer = game.bgLayer = new cjs.Container();
        var startBtn = game.startBtn = new cjs.Container();
		var hardBtn = game.hardBtn = new cjs.Container();
        var loadBtn = game.loadBtn = new cjs.Container();
        var mainMenu = game.mainMenu = new cjs.Container();

        bgLayer.addChild(new lib.mainBG);
        mainMenu.addChild(new lib.mainMenu_1)
        startBtn.addChild(new lib.playBtn);
		hardBtn.addChild(new lib.HardMode_1);
        loadBtn.addChild(new lib.loadButton_1);


        game.stage.addChild(bgLayer);
        game.stage.addChild(mainMenu);
        game.stage.addChild(startBtn);
		game.stage.addChild(hardBtn);
        game.stage.addChild(loadBtn);

        
		//ADD HUD PICTURES HERE
		var cc = document.getElementById("CCTower1");
        cc.innerHTML = "<img src='img/CCTowerHud.png'>";
        var rd = document.getElementById("CCTower2");
        rd.innerHTML = "<img src='img/DeerCaneHud.png'>";
		var ycc = document.getElementById("YetiTower1");
		ycc.innerHTML = "<img src='img/YetiCCHUD.png'>";
        var gy = document.getElementById("YetiTower2");
		gy.innerHTML = "<img src='img/YetiGreyHUD.png'>";
		var gy = document.getElementById("YetiTower2");
		gy.innerHTML = "<img src='img/YetiGreyHUD.png'>";
		var s = document.getElementById("Santa");
		s.innerHTML = "<img src='img/SantaHUD.png'>";
		var s = document.getElementById("Santa");
		s.innerHTML = "<img src='img/SantaHUD.png'>";
		var sg = document.getElementById("Settings");
		sg.innerHTML = "<img src='img/SettingsHUD.png'>";
		//SET MAIN MENU AND BUTTON LOCATIONS HERE
		mainMenu.x = 430;
        mainMenu.y = 100;
        startBtn.x = (game.width / 2) - 60;
        startBtn.y = game.height / 3 + 60;
        hardBtn.x = (game.width / 2) - 60;
		hardBtn.y = (game.height / 3) + 120;
		loadBtn.x = (game.width / 2) - 60;
        loadBtn.y = (game.height / 3) + 180;

        cjs.Ticker.addEventListener('tick', game.stage); // add game.stage to ticker make the stage.update call automatically.

        //Easy start button
        startBtn.addEventListener("click", function (event)
         {
            if (typeof user === "undefined")
            {
                game.checkUser();
                return;
            }
            startBtn.removeAllEventListeners();
			hardBtn.removeAllEventListeners();
            loadBtn.removeAllEventListeners();
            mainMenu.removeAllEventListeners();
            bgLayer.removeAllEventListeners();
            hard_mode = false;
            cjs.Sound.stop();
            game.playGameMusic();
            game.start(hard_mode);
        });

		hardBtn.addEventListener("click", function (event)
		{
            if (typeof user === "undefined")
            {
                game.checkUser();
                return;
            }
			startBtn.removeAllEventListeners();
			hardBtn.removeAllEventListeners();
            loadBtn.removeAllEventListeners();
            mainMenu.removeAllEventListeners();
            bgLayer.removeAllEventListeners();
            hard_mode = true;
            cjs.Sound.stop();
            game.playGameMusic();
            game.start(hard_mode);
		});

        //load button
        loadBtn.addEventListener("click", function (event)
        {
            if (typeof user === "undefined")
            {
                game.checkUser();
                return;
            }
            if(localStorage['saved.wave'])
                {
                    var score = document.getElementById('score').innerHTML;
                    game.waves.nextWave = localStorage['saved.wave'] *1;
                    game.gold = localStorage['saved.gold'];
                    game.score = parseInt(localStorage['saved.score']);
                    game.lives = localStorage['saved.lives'];
                    game.difficulty = parseInt(localStorage['saved.difficulty']);
                    loadGame = true;
                    startBtn.removeAllEventListeners();
                    hardBtn.removeAllEventListeners();
                    loadBtn.removeAllEventListeners();
                    mainMenu.removeAllEventListeners();
                    bgLayer.removeAllEventListeners();
                    game.playGameMusic();
                    game.start(hard_mode);
                }

        });


    };

    game.settings = function () {
         if (typeof user === "undefined")
            {
                game.checkUser();
                return;
            }
        if (cjs.Ticker.getPaused() == true)
        {
             startBtn.addEventListener("click", function (event) {
                startBtn.removeAllEventListeners();
                loadBtn.removeAllEventListeners();
                mainMenu.removeAllEventListeners();
				quitBtn.removeAllEventListeners();
                bgLayer.removeAllEventListeners();

                //
            });
			cjs.Ticker.setPaused(false);
        }
        else
        {
            //PAUSED THE GAME
            cjs.Sound.stop();
            cjs.Ticker.setPaused(true);
            var bgLayer = game.bgLayer = new cjs.Container();
            var startBtn = game.startBtn = new cjs.Container();
            var loadBtn = game.loadBtn = new cjs.Container();
            var mainMenu = game.mainMenu = new cjs.Container();
            var quitBtn = game.quitBtn = new cjs.Container();
            var saveBtn = game.saveBtn = new cjs.Container();
			
			bgLayer.addChild(new lib.mainBG);
            mainMenu.addChild(new lib.pauseMenu_1);
            startBtn.addChild(new lib.resumeBtn);
            loadBtn.addChild(new lib.loadButton_1);
			quitBtn.addChild(new lib.quitBtn);
			saveBtn.addChild(new lib.saveBtn);
			
            game.stage.addChild(bgLayer);
            game.stage.addChild(mainMenu);
            game.stage.addChild(startBtn);
            game.stage.addChild(loadBtn);
			game.stage.addChild(quitBtn);
			game.stage.addChild(saveBtn);
			
			mainMenu.x = 430;
			mainMenu.y = 100;
            startBtn.x = (game.width / 2) - 60;
			startBtn.y = game.height / 3 + 20;
			saveBtn.x = (game.width / 2) - 60;
			saveBtn.y = game.height / 3 + 80;
			loadBtn.x = (game.width / 2) - 60;
			loadBtn.y = (game.height / 3) + 140;
			quitBtn.x = (game.width / 2) - 60;
			quitBtn.y = (game.height / 3) + 200;
			
			//Start Button
			startBtn.addEventListener("click", function(event) { 
				game.stage.removeChild(startBtn);
				startBtn.removeAllEventListeners();
				game.stage.removeChild(saveBtn);
				saveBtn.removeAllEventListeners();
				game.stage.removeChild(quitBtn);
				quitBtn.removeAllEventListeners();
				game.stage.removeChild(loadBtn);
				loadBtn.removeAllEventListeners();
				game.stage.removeChild(mainMenu);
				mainMenu.removeAllEventListeners();
				game.stage.removeChild(bgLayer);
				bgLayer.removeAllEventListeners();
				cjs.Ticker.setPaused(false);
				game.playGameMusic();
			});
			//Load Button
			loadBtn.addEventListener("click", function (event) {
                if (typeof user === "undefined")
                {
                    game.checkUser();
                    return;
                }
                if(localStorage['saved.wave'])
                {
                    game.waves.nextWave = localStorage['saved.wave'] *1;
                    game.gold = localStorage['saved.gold'];
                    game.score = parseInt(localStorage['saved.score']);
                    game.lives = localStorage['saved.lives'];
                    game.difficulty = parseInt(localStorage['saved.difficulty']);

                }
                loadGame = true
				game.stage.removeAllChildren();
				game.stage.update();
				cjs.Ticker.setPaused(true);
				game.menu();
				
			});
			//Quit Button
			quitBtn.addEventListener("click", function (event) {

				game.stage.removeAllChildren();
				game.stage.update();
				cjs.Ticker.setPaused(true);
                loadGame = false;
				game.menu();
			});
			saveBtn.addEventListener("click", function (event) {
                if (typeof user === "undefined")
                {
                    game.checkUser();
                    return;
                }
                localStorage['saved.wave'] = game.waves.nextWave;
                localStorage['saved.gold'] = game.gold;
                localStorage['saved.score'] = game.score;
                localStorage['saved.lives'] = game.lives;
                localStorage['saved.difficulty'] = game.difficulty;


				document.getElementById("waveIndicator").style.visibility = "visible";
				document.getElementById("waveIndicator").innerHTML = "Game Saved";
				cjs.Ticker.setPaused(true);
				setTimeout(function()
				{
					document.getElementById("waveIndicator").innerHTML = "Game Saved";
					document.getElementById("waveIndicator").style.visibility = "hidden";
					game.stage.removeChild(startBtn);
					startBtn.removeAllEventListeners();
					game.stage.removeChild(saveBtn);
					saveBtn.removeAllEventListeners();
					game.stage.removeChild(quitBtn);
					quitBtn.removeAllEventListeners();
					game.stage.removeChild(loadBtn);
					loadBtn.removeAllEventListeners();
					game.stage.removeChild(mainMenu);
					mainMenu.removeAllEventListeners();
					game.stage.removeChild(bgLayer);
					bgLayer.removeAllEventListeners();
		
					cjs.Ticker.setPaused(false);
				} ,3000);
				
			});
			
		 }
    };

    game.start = function (game_mode) {
         if (typeof user === "undefined")
            {
                return;
            }
        cjs.EventDispatcher.initialize(game); // allow the game object to listen and dispatch custom events.

        game.canvas = document.getElementById('canvas');
        game.width = document.getElementById('canvas').width;
        game.height = document.getElementById('canvas').height;

        game.stage = new cjs.Stage(game.canvas);

        // game parameters
         if (loadGame == false)
        {
            game.lives = 10;
            game.gold = 500; // use to create building
            game.score = 0;
            game.waves.nextWave = 0;
        }

        if (game_mode == true)
        {
            game.difficulty = 2;

        }
        else
        {
            game.difficulty = 1;

        }
        

        //Placing this first, puts the grid behind the game frame
        var boardLayer = game.boardLayer = new game.Board();
        game.stage.addChild(boardLayer);
        // layers
        var bgLayer = game.bgLayer = new cjs.Container();
        bgLayer.addChild(new lib.Background);
        game.stage.addChild(bgLayer);
        var effectLayer = game.effectLayer = new cjs.Container();
        game.stage.addChild(effectLayer);
        cjs.Ticker.setFPS(30);
        cjs.Ticker.addEventListener('tick', game.stage); // add game.stage to ticker make the stage.update call automatically.
        cjs.Ticker.addEventListener('tick', game.tick); // gameloop
        cjs.Ticker.setPaused(false);
        game.waves.startWave();
		
    };

    game.gameOver = function () {
        game.postScore(game.score, user);
        cjs.Sound.stop();
        cjs.Ticker.setPaused(true);
		game.stage.removeAllChildren();
		game.stage.update();
		game.waves.nextWave = 0;
		var bgLayer = game.bgLayer = new cjs.Container();
		var startBtn = game.startBtn = new cjs.Container();
		var loadBtn = game.loadBtn = new cjs.Container();
		var mainMenu = game.mainMenu = new cjs.Container();
		bgLayer.addChild(new lib.mainBG);
		mainMenu.addChild(new lib.gameover_1);
		startBtn.addChild(new lib.mainMenuBtn);
		loadBtn.addChild(new lib.loadButton_1);

		game.stage.addChild(bgLayer);
		game.stage.addChild(mainMenu);
		game.stage.addChild(startBtn);
		game.stage.addChild(loadBtn);
		mainMenu.x = 430;
		mainMenu.y = 100;
		startBtn.x = (game.width / 2) - 60;
		startBtn.y = game.height / 3 + 60;
		loadBtn.x = (game.width / 2) - 60;
		loadBtn.y = (game.height / 3) + 120;

		startBtn.addEventListener("click", function (event) {
			game.stage.removeChild(startBtn);
			startBtn.removeAllEventListeners();
			game.stage.removeChild(loadBtn);
			loadBtn.removeAllEventListeners();
			game.stage.removeChild(mainMenu);
			mainMenu.removeAllEventListeners();
			game.stage.removeChild(bgLayer);
			bgLayer.removeAllEventListeners();
			
			game.waves.nextWave = 0;
            loadGame = false;
			game.menu();

		});
        loadBtn.addEventListener("click", function (event)
        {
            
            if(localStorage['saved.wave'])
                {
                    game.waves.nextWave = localStorage['saved.wave'] *1;
                    game.gold = localStorage['saved.gold'];
                    game.score = parseInt(localStorage['saved.score']);
                    game.lives = localStorage['saved.lives'];
                    game.difficulty = parseInt(localStorage['saved.difficulty']);
                    loadGame = true;
                    startBtn.removeAllEventListeners();
                    loadBtn.removeAllEventListeners();
                    mainMenu.removeAllEventListeners();
                    bgLayer.removeAllEventListeners();
                    game.playGameMusic();
                    game.start(hard_mode);
                }

        });
    };

    game.tick = function () {
        //cjs.Ticker.paused = true;
        if (cjs.Ticker.getPaused()) { return; } // run when not paused

        if(game.lives <= 0) {
            game.gameOver();
        }

        if (game.waves.nextWave > game.waves.data.length - 1)
        {
            game.gameOver();
        }
        // tick waves
        game.waves.tick();

        if (!game.waves.isActive && game.boardLayer.areEnemiesCleared())
        {
            
			document.getElementById("waveIndicator").style.visibility = "visible";
			document.getElementById("waveIndicator").innerHTML = "Wave Cleared";
			cjs.Ticker.setPaused(true);
			setTimeout(function()
			{
				document.getElementById("waveIndicator").innerHTML = "Wave Cleared";
				cjs.Ticker.setPaused(false);
			} ,3000);
			game.boardLayer.isAddingBuilding = false;
			game.boardLayer.removeAllBuildings();
			game.boardLayer.removeAllBullets();
			game.waves.waveCleared();

		}
    };

    game.sound = function () {
        var assetsPath = "sound/";

        manifest = [
            { id: "game_music", src: "Frosty_The_Snowman.ogg" },
            { id: "attack_sound", src: "Woosh.ogg" },
            { id: "hit", src: "hit.ogg" },
            { id: "starwars", src:"Star_Wars_Theme.ogg"}
        ];

        cjs.Sound.alternateExtensions = ['aif', 'webm'];
        preload = new cjs.LoadQueue(true, assetsPath);
        preload.installPlugin(cjs.Sound);
        preload.loadManifest(manifest);
    };

    game.playGameMusic = function () {
        var myInstance = cjs.Sound.play("game_music", { loop: -1 });
        myInstance.volume = myInstance.volume * 0.01;
    };

    game.postScore = function (score, user) {

        var data = {
            score: score,
            by: user
        }
        $.ajax({
            type: "POST",
            url: "https://santadefender.herokuapp.com/highscore/",/*
            url: "http://localhost:8080/highscore",*/
            data: data,
            success: function(data) {
                console.log("Posted Score: ", data.score);
            },
            error: function(xhr, msg) {
                console.error('AJAX error', xhr.status, msg);
            }
        });

    };

    game.checkUser = function()
    {
        document.getElementById("waveIndicator").style.visibility = "visible";
        document.getElementById("waveIndicator").innerHTML = "Please Log In To Play";
        setTimeout(function()
        {
            document.getElementById("waveIndicator").style.visibility = "hidden";
        } ,3000);
    };

    game.load();

}).call(this, game, createjs);