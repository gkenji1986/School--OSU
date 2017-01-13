(function (lib, img, cjs, ss) {

var p; // shortcut to reference prototypes
lib.webFontTxtInst = {}; 
var loadedTypekitCount = 0;
var loadedGoogleCount = 0;
var gFontsUpdateCacheList = [];
var tFontsUpdateCacheList = [];

// library properties:
lib.properties = {
	width: 1280,
	height: 768,
	fps: 24,
	color: "#FFFFFF",
	opacity: 1.00,
	webfonts: {},
	manifest: [
		{src:"img/_1Walk_000.png", id:"_1Walk_000"},
		{src:"img/_1Walk_001.png", id:"_1Walk_001"},
		{src:"img/_1Walk_002.png", id:"_1Walk_002"},
		{src:"img/_1Walk_003.png", id:"_1Walk_003"},
		{src:"img/_1Walk_004.png", id:"_1Walk_004"},
		{src:"img/_1Walk_005.png", id:"_1Walk_005"},
		{src:"img/_1Walk_006.png", id:"_1Walk_006"},
		{src:"img/_1Walk_007.png", id:"_1Walk_007"},
		{src:"img/_1Walk_008.png", id:"_1Walk_008"},
		{src:"img/_1Walk_009.png", id:"_1Walk_009"},
		{src:"img/_1Walk_010.png", id:"_1Walk_010"},
		{src:"img/_1Walk_011.png", id:"_1Walk_011"},
		{src:"img/_2Walk_000.png", id:"_2Walk_000"},
		{src:"img/_2Walk_001.png", id:"_2Walk_001"},
		{src:"img/_2Walk_002.png", id:"_2Walk_002"},
		{src:"img/_2Walk_003.png", id:"_2Walk_003"},
		{src:"img/_2Walk_004.png", id:"_2Walk_004"},
		{src:"img/_2Walk_005.png", id:"_2Walk_005"},
		{src:"img/_2Walk_006.png", id:"_2Walk_006"},
		{src:"img/_2Walk_007.png", id:"_2Walk_007"},
		{src:"img/_2Walk_008.png", id:"_2Walk_008"},
		{src:"img/_2Walk_009.png", id:"_2Walk_009"},
		{src:"img/_2Walk_010.png", id:"_2Walk_010"},
		{src:"img/_2Walk_011.png", id:"_2Walk_011"},
		{src:"img/_4Walk_000.png", id:"_4Walk_000"},
		{src:"img/_4Walk_001.png", id:"_4Walk_001"},
		{src:"img/_4Walk_002.png", id:"_4Walk_002"},
		{src:"img/_4Walk_003.png", id:"_4Walk_003"},
		{src:"img/_4Walk_004.png", id:"_4Walk_004"},
		{src:"img/_4Walk_005.png", id:"_4Walk_005"},
		{src:"img/_4Walk_006.png", id:"_4Walk_006"},
		{src:"img/_4Walk_007.png", id:"_4Walk_007"},
		{src:"img/_4Walk_008.png", id:"_4Walk_008"},
		{src:"img/_4Walk_009.png", id:"_4Walk_009"},
		{src:"img/_4Walk_010.png", id:"_4Walk_010"},
		{src:"img/_4Walk_011.png", id:"_4Walk_011"},
		{src:"img/_5Walk_000.png", id:"_5Walk_000"},
		{src:"img/_5Walk_001.png", id:"_5Walk_001"},
		{src:"img/_5Walk_002.png", id:"_5Walk_002"},
		{src:"img/_5Walk_003.png", id:"_5Walk_003"},
		{src:"img/_5Walk_004.png", id:"_5Walk_004"},
		{src:"img/_5Walk_005.png", id:"_5Walk_005"},
		{src:"img/_5Walk_006.png", id:"_5Walk_006"},
		{src:"img/_5Walk_007.png", id:"_5Walk_007"},
		{src:"img/_5Walk_008.png", id:"_5Walk_008"},
		{src:"img/_5Walk_009.png", id:"_5Walk_009"},
		{src:"img/_5Walk_010.png", id:"_5Walk_010"},
		{src:"img/_5Walk_011.png", id:"_5Walk_011"},
		{src:"img/Board.png", id:"Board"},
		{src:"img/CandyCane0.png", id:"CandyCane0"},
		{src:"img/CandyCane1.png", id:"CandyCane1"},
		{src:"img/CandyCane2.png", id:"CandyCane2"},
		{src:"img/CandyCane3.png", id:"CandyCane3"},
		{src:"img/CandyCane4.png", id:"CandyCane4"},
		{src:"img/CandyCane5.png", id:"CandyCane5"},
		{src:"img/CandyCane6.png", id:"CandyCane6"},
		{src:"img/CandyCane7.png", id:"CandyCane7"},
		{src:"img/CandyCane8.png", id:"CandyCane8"},
		{src:"img/CandyCane9.png", id:"CandyCane9"},
		{src:"img/ccBulletRotate0.png", id:"ccBulletRotate0"},
		{src:"img/ccBulletRotate1.png", id:"ccBulletRotate1"},
		{src:"img/ccBulletRotate2.png", id:"ccBulletRotate2"},
		{src:"img/ccBulletRotate3.png", id:"ccBulletRotate3"},
		{src:"img/ccBulletRotate4.png", id:"ccBulletRotate4"},
		{src:"img/ccBulletRotate5.png", id:"ccBulletRotate5"},
		{src:"img/ccBulletRotate6.png", id:"ccBulletRotate6"},
		{src:"img/CCTowerHud.png", id:"CCTowerHud"},
		{src:"img/DeerCaneHud.png", id:"DeerCaneHud"},
		{src:"img/DeerTower0.png", id:"DeerTower0"},
		{src:"img/DeerTower1.png", id:"DeerTower1"},
		{src:"img/DeerTower2.png", id:"DeerTower2"},
		{src:"img/DeerTower3.png", id:"DeerTower3"},
		{src:"img/DeerTower4.png", id:"DeerTower4"},
		{src:"img/DeerTower5.png", id:"DeerTower5"},
		{src:"img/DeerTower6.png", id:"DeerTower6"},
		{src:"img/DeerTower7.png", id:"DeerTower7"},
		{src:"img/DeerTower8.png", id:"DeerTower8"},
		{src:"img/EasyMode.png", id:"EasyMode"},
		{src:"img/FrostyCC0.png", id:"FrostyCC0"},
		{src:"img/FrostyCC1.png", id:"FrostyCC1"},
		{src:"img/FrostyCC2.png", id:"FrostyCC2"},
		{src:"img/FrostyCC3.png", id:"FrostyCC3"},
		{src:"img/FrostyCC4.png", id:"FrostyCC4"},
		{src:"img/FrostyCC5.png", id:"FrostyCC5"},
		{src:"img/FrostyCC6.png", id:"FrostyCC6"},
		{src:"img/FrostyCC7.png", id:"FrostyCC7"},
		{src:"img/FrostyCC8.png", id:"FrostyCC8"},
		{src:"img/FrostyTH0.png", id:"FrostyTH0"},
		{src:"img/FrostyTH1.png", id:"FrostyTH1"},
		{src:"img/FrostyTH2.png", id:"FrostyTH2"},
		{src:"img/FrostyTH3.png", id:"FrostyTH3"},
		{src:"img/FrostyTH4.png", id:"FrostyTH4"},
		{src:"img/FrostyTH5.png", id:"FrostyTH5"},
		{src:"img/FrostyTH6.png", id:"FrostyTH6"},
		{src:"img/FrostyTH7.png", id:"FrostyTH7"},
		{src:"img/FrostyTH8.png", id:"FrostyTH8"},
		{src:"img/FrostyWig0.png", id:"FrostyWig0"},
		{src:"img/FrostyWig1.png", id:"FrostyWig1"},
		{src:"img/FrostyWig2.png", id:"FrostyWig2"},
		{src:"img/FrostyWig3.png", id:"FrostyWig3"},
		{src:"img/FrostyWig4.png", id:"FrostyWig4"},
		{src:"img/FrostyWig5.png", id:"FrostyWig5"},
		{src:"img/FrostyWig6.png", id:"FrostyWig6"},
		{src:"img/FrostyWig7.png", id:"FrostyWig7"},
		{src:"img/FrostyWig8.png", id:"FrostyWig8"},
		{src:"img/gameover.png", id:"gameover"},
		{src:"img/HardMode.png", id:"HardMode"},
		{src:"img/ice0.png", id:"ice0"},
		{src:"img/ice1.png", id:"ice1"},
		{src:"img/ice2.png", id:"ice2"},
		{src:"img/ice3.png", id:"ice3"},
		{src:"img/ice4.png", id:"ice4"},
		{src:"img/ice5.png", id:"ice5"},
		{src:"img/ice6.png", id:"ice6"},
		{src:"img/loadButton.png", id:"loadButton"},
		{src:"img/mainBG.png", id:"mainBG"},
		{src:"img/mainMenu.png", id:"mainMenu"},
		{src:"img/mainMenuButton.png", id:"mainMenuButton"},
		{src:"img/muteButton.png", id:"muteButton"},
		{src:"img/ornament.png", id:"ornament"},
		{src:"img/pauseMenu.png", id:"pauseMenu"},
		{src:"img/present.png", id:"present"},
		{src:"img/quitButton.png", id:"quitButton"},
		{src:"img/resumeButton.png", id:"resumeButton"},
		{src:"img/Santa0.png", id:"Santa0"},
		{src:"img/Santa1.png", id:"Santa1"},
		{src:"img/Santa10.png", id:"Santa10"},
		{src:"img/Santa11.png", id:"Santa11"},
		{src:"img/Santa12.png", id:"Santa12"},
		{src:"img/Santa13.png", id:"Santa13"},
		{src:"img/Santa14.png", id:"Santa14"},
		{src:"img/Santa15.png", id:"Santa15"},
		{src:"img/Santa2.png", id:"Santa2"},
		{src:"img/Santa3.png", id:"Santa3"},
		{src:"img/Santa4.png", id:"Santa4"},
		{src:"img/Santa5.png", id:"Santa5"},
		{src:"img/Santa6.png", id:"Santa6"},
		{src:"img/Santa7.png", id:"Santa7"},
		{src:"img/Santa8.png", id:"Santa8"},
		{src:"img/Santa9.png", id:"Santa9"},
		{src:"img/SantaHUD.png", id:"SantaHUD"},
		{src:"img/saveButton.png", id:"saveButton"},
		{src:"img/settingButton.png", id:"settingButton"},
		{src:"img/SettingsHUD.png", id:"SettingsHUD"},
		{src:"img/snowball.png", id:"snowball"},
		{src:"img/SnowyBackground.jpg", id:"SnowyBackground"},
		{src:"img/Walk_000.png", id:"Walk_000"},
		{src:"img/Walk_001.png", id:"Walk_001"},
		{src:"img/Walk_002.png", id:"Walk_002"},
		{src:"img/Walk_003.png", id:"Walk_003"},
		{src:"img/Walk_004.png", id:"Walk_004"},
		{src:"img/Walk_005.png", id:"Walk_005"},
		{src:"img/Walk_006.png", id:"Walk_006"},
		{src:"img/Walk_007.png", id:"Walk_007"},
		{src:"img/Walk_008.png", id:"Walk_008"},
		{src:"img/Walk_009.png", id:"Walk_009"},
		{src:"img/Walk_010.png", id:"Walk_010"},
		{src:"img/Walk_011.png", id:"Walk_011"},
		{src:"img/Yeti_Attack0.png", id:"Yeti_Attack0"},
		{src:"img/Yeti_Attack1.png", id:"Yeti_Attack1"},
		{src:"img/Yeti_Attack2.png", id:"Yeti_Attack2"},
		{src:"img/Yeti_Attack3.png", id:"Yeti_Attack3"},
		{src:"img/Yeti_Attack4.png", id:"Yeti_Attack4"},
		{src:"img/Yeti_Attack5.png", id:"Yeti_Attack5"},
		{src:"img/Yeti_Attack6.png", id:"Yeti_Attack6"},
		{src:"img/Yeti_Attack7.png", id:"Yeti_Attack7"},
		{src:"img/Yeti_Attack8.png", id:"Yeti_Attack8"},
		{src:"img/YetiCCHUD.png", id:"YetiCCHUD"},
		{src:"img/YetiGrey_Attack0.png", id:"YetiGrey_Attack0"},
		{src:"img/YetiGrey_Attack1.png", id:"YetiGrey_Attack1"},
		{src:"img/YetiGrey_Attack2.png", id:"YetiGrey_Attack2"},
		{src:"img/YetiGrey_Attack3.png", id:"YetiGrey_Attack3"},
		{src:"img/YetiGrey_Attack4.png", id:"YetiGrey_Attack4"},
		{src:"img/YetiGrey_Attack5.png", id:"YetiGrey_Attack5"},
		{src:"img/YetiGrey_Attack6.png", id:"YetiGrey_Attack6"},
		{src:"img/YetiGrey_Attack7.png", id:"YetiGrey_Attack7"},
		{src:"img/YetiGrey_Attack8.png", id:"YetiGrey_Attack8"},
		{ src: "img/YetiGreyHUD.png", id: "YetiGreyHUD" },
        { src: "img/star_wars_background.jpg", id: "star_wars_background" }
	]
};



lib.ssMetadata = [];



lib.updateListCache = function (cacheList) {		
	for(var i = 0; i < cacheList.length; i++) {		
		if(cacheList[i].cacheCanvas)		
			cacheList[i].updateCache();		
	}		
};		

lib.addElementsToCache = function (textInst, cacheList) {		
	var cur = textInst;		
	while(cur != exportRoot) {		
		if(cacheList.indexOf(cur) != -1)		
			break;		
		cur = cur.parent;		
	}		
	if(cur != exportRoot) {	//we have found an element in the list		
		var cur2 = textInst;		
		var index = cacheList.indexOf(cur);		
		while(cur2 != cur) { //insert all it's children just before it		
			cacheList.splice(index, 0, cur2);		
			cur2 = cur2.parent;		
			index++;		
		}		
	}		
	else {	//append element and it's parents in the array		
		cur = textInst;		
		while(cur != exportRoot) {		
			cacheList.push(cur);		
			cur = cur.parent;		
		}		
	}		
};		

lib.gfontAvailable = function(family, totalGoogleCount) {		
	lib.properties.webfonts[family] = true;		
	var txtInst = lib.webFontTxtInst && lib.webFontTxtInst[family] || [];		
	for(var f = 0; f < txtInst.length; ++f)		
		lib.addElementsToCache(txtInst[f], gFontsUpdateCacheList);		

	loadedGoogleCount++;		
	if(loadedGoogleCount == totalGoogleCount) {		
		lib.updateListCache(gFontsUpdateCacheList);		
	}		
};		

lib.tfontAvailable = function(family, totalTypekitCount) {		
	lib.properties.webfonts[family] = true;		
	var txtInst = lib.webFontTxtInst && lib.webFontTxtInst[family] || [];		
	for(var f = 0; f < txtInst.length; ++f)		
		lib.addElementsToCache(txtInst[f], tFontsUpdateCacheList);		

	loadedTypekitCount++;		
	if(loadedTypekitCount == totalTypekitCount) {		
		lib.updateListCache(tFontsUpdateCacheList);		
	}		
};
// symbols:



(lib._1Walk_000 = function() {
	this.initialize(img._1Walk_000);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_001 = function() {
	this.initialize(img._1Walk_001);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_002 = function() {
	this.initialize(img._1Walk_002);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_003 = function() {
	this.initialize(img._1Walk_003);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_004 = function() {
	this.initialize(img._1Walk_004);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_005 = function() {
	this.initialize(img._1Walk_005);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_006 = function() {
	this.initialize(img._1Walk_006);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_007 = function() {
	this.initialize(img._1Walk_007);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_008 = function() {
	this.initialize(img._1Walk_008);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_009 = function() {
	this.initialize(img._1Walk_009);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_010 = function() {
	this.initialize(img._1Walk_010);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._1Walk_011 = function() {
	this.initialize(img._1Walk_011);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_000 = function() {
	this.initialize(img._2Walk_000);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_001 = function() {
	this.initialize(img._2Walk_001);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_002 = function() {
	this.initialize(img._2Walk_002);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_003 = function() {
	this.initialize(img._2Walk_003);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_004 = function() {
	this.initialize(img._2Walk_004);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_005 = function() {
	this.initialize(img._2Walk_005);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_006 = function() {
	this.initialize(img._2Walk_006);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_007 = function() {
	this.initialize(img._2Walk_007);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_008 = function() {
	this.initialize(img._2Walk_008);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_009 = function() {
	this.initialize(img._2Walk_009);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_010 = function() {
	this.initialize(img._2Walk_010);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._2Walk_011 = function() {
	this.initialize(img._2Walk_011);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_000 = function() {
	this.initialize(img._4Walk_000);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_001 = function() {
	this.initialize(img._4Walk_001);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_002 = function() {
	this.initialize(img._4Walk_002);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_003 = function() {
	this.initialize(img._4Walk_003);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_004 = function() {
	this.initialize(img._4Walk_004);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_005 = function() {
	this.initialize(img._4Walk_005);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_006 = function() {
	this.initialize(img._4Walk_006);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_007 = function() {
	this.initialize(img._4Walk_007);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_008 = function() {
	this.initialize(img._4Walk_008);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_009 = function() {
	this.initialize(img._4Walk_009);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_010 = function() {
	this.initialize(img._4Walk_010);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._4Walk_011 = function() {
	this.initialize(img._4Walk_011);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_000 = function() {
	this.initialize(img._5Walk_000);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_001 = function() {
	this.initialize(img._5Walk_001);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_002 = function() {
	this.initialize(img._5Walk_002);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_003 = function() {
	this.initialize(img._5Walk_003);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_004 = function() {
	this.initialize(img._5Walk_004);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_005 = function() {
	this.initialize(img._5Walk_005);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_006 = function() {
	this.initialize(img._5Walk_006);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_007 = function() {
	this.initialize(img._5Walk_007);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_008 = function() {
	this.initialize(img._5Walk_008);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_009 = function() {
	this.initialize(img._5Walk_009);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_010 = function() {
	this.initialize(img._5Walk_010);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib._5Walk_011 = function() {
	this.initialize(img._5Walk_011);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Board = function() {
	this.initialize(img.Board);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,1280,768);


(lib.CandyCane0 = function() {
	this.initialize(img.CandyCane0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane1 = function() {
	this.initialize(img.CandyCane1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane2 = function() {
	this.initialize(img.CandyCane2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane3 = function() {
	this.initialize(img.CandyCane3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane4 = function() {
	this.initialize(img.CandyCane4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane5 = function() {
	this.initialize(img.CandyCane5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane6 = function() {
	this.initialize(img.CandyCane6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane7 = function() {
	this.initialize(img.CandyCane7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane8 = function() {
	this.initialize(img.CandyCane8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.CandyCane9 = function() {
	this.initialize(img.CandyCane9);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,115,253);


(lib.ccBulletRotate0 = function() {
	this.initialize(img.ccBulletRotate0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate1 = function() {
	this.initialize(img.ccBulletRotate1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate2 = function() {
	this.initialize(img.ccBulletRotate2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate3 = function() {
	this.initialize(img.ccBulletRotate3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate4 = function() {
	this.initialize(img.ccBulletRotate4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate5 = function() {
	this.initialize(img.ccBulletRotate5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.ccBulletRotate6 = function() {
	this.initialize(img.ccBulletRotate6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,61);


(lib.CCTowerHud = function() {
	this.initialize(img.CCTowerHud);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,100);


(lib.DeerCaneHud = function() {
	this.initialize(img.DeerCaneHud);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,86);


(lib.DeerTower0 = function() {
	this.initialize(img.DeerTower0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower1 = function() {
	this.initialize(img.DeerTower1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower2 = function() {
	this.initialize(img.DeerTower2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower3 = function() {
	this.initialize(img.DeerTower3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower4 = function() {
	this.initialize(img.DeerTower4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower5 = function() {
	this.initialize(img.DeerTower5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower6 = function() {
	this.initialize(img.DeerTower6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower7 = function() {
	this.initialize(img.DeerTower7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.DeerTower8 = function() {
	this.initialize(img.DeerTower8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,78,128);


(lib.EasyMode = function() {
	this.initialize(img.EasyMode);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.FrostyCC0 = function() {
	this.initialize(img.FrostyCC0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC1 = function() {
	this.initialize(img.FrostyCC1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC2 = function() {
	this.initialize(img.FrostyCC2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC3 = function() {
	this.initialize(img.FrostyCC3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC4 = function() {
	this.initialize(img.FrostyCC4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC5 = function() {
	this.initialize(img.FrostyCC5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC6 = function() {
	this.initialize(img.FrostyCC6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC7 = function() {
	this.initialize(img.FrostyCC7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyCC8 = function() {
	this.initialize(img.FrostyCC8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,90,128);


(lib.FrostyTH0 = function() {
	this.initialize(img.FrostyTH0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH1 = function() {
	this.initialize(img.FrostyTH1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH2 = function() {
	this.initialize(img.FrostyTH2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH3 = function() {
	this.initialize(img.FrostyTH3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH4 = function() {
	this.initialize(img.FrostyTH4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH5 = function() {
	this.initialize(img.FrostyTH5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH6 = function() {
	this.initialize(img.FrostyTH6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH7 = function() {
	this.initialize(img.FrostyTH7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyTH8 = function() {
	this.initialize(img.FrostyTH8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,91,128);


(lib.FrostyWig0 = function() {
	this.initialize(img.FrostyWig0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig1 = function() {
	this.initialize(img.FrostyWig1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig2 = function() {
	this.initialize(img.FrostyWig2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig3 = function() {
	this.initialize(img.FrostyWig3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig4 = function() {
	this.initialize(img.FrostyWig4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig5 = function() {
	this.initialize(img.FrostyWig5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig6 = function() {
	this.initialize(img.FrostyWig6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig7 = function() {
	this.initialize(img.FrostyWig7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.FrostyWig8 = function() {
	this.initialize(img.FrostyWig8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,117,128);


(lib.gameover = function() {
	this.initialize(img.gameover);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,794,1104);


(lib.HardMode = function() {
	this.initialize(img.HardMode);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.ice0 = function() {
	this.initialize(img.ice0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice1 = function() {
	this.initialize(img.ice1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice2 = function() {
	this.initialize(img.ice2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice3 = function() {
	this.initialize(img.ice3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice4 = function() {
	this.initialize(img.ice4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice5 = function() {
	this.initialize(img.ice5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.ice6 = function() {
	this.initialize(img.ice6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,63,63);


(lib.loadButton = function() {
	this.initialize(img.loadButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.mainBG = function() {
	this.initialize(img.mainBG);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,1280,768);


(lib.mainMenu = function() {
	this.initialize(img.mainMenu);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,794,1104);


(lib.mainMenuButton = function() {
	this.initialize(img.mainMenuButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.muteButton = function() {
	this.initialize(img.muteButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,301,131);


(lib.ornament = function() {
	this.initialize(img.ornament);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,56,64);


(lib.pauseMenu = function() {
	this.initialize(img.pauseMenu);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,794,1104);


(lib.present = function() {
	this.initialize(img.present);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,64,48);


(lib.quitButton = function() {
	this.initialize(img.quitButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.resumeButton = function() {
	this.initialize(img.resumeButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.Santa0 = function() {
	this.initialize(img.Santa0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa1 = function() {
	this.initialize(img.Santa1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa10 = function() {
	this.initialize(img.Santa10);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa11 = function() {
	this.initialize(img.Santa11);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa12 = function() {
	this.initialize(img.Santa12);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa13 = function() {
	this.initialize(img.Santa13);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa14 = function() {
	this.initialize(img.Santa14);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa15 = function() {
	this.initialize(img.Santa15);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa2 = function() {
	this.initialize(img.Santa2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa3 = function() {
	this.initialize(img.Santa3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa4 = function() {
	this.initialize(img.Santa4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa5 = function() {
	this.initialize(img.Santa5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa6 = function() {
	this.initialize(img.Santa6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa7 = function() {
	this.initialize(img.Santa7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa8 = function() {
	this.initialize(img.Santa8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.Santa9 = function() {
	this.initialize(img.Santa9);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,150,150);


(lib.SantaHUD = function() {
	this.initialize(img.SantaHUD);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,93,87);


(lib.saveButton = function() {
	this.initialize(img.saveButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.settingButton = function() {
	this.initialize(img.settingButton);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,500,140);


(lib.SettingsHUD = function() {
	this.initialize(img.SettingsHUD);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,85,72);


(lib.snowball = function() {
	this.initialize(img.snowball);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,64,64);


(lib.SnowyBackground = function() {
	this.initialize(img.SnowyBackground);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,1024,576);


(lib.StarWarsBackground = function () {
    this.initialize(img.star_wars_background);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0, 0, 1024, 576);

(lib.Walk_000 = function() {
	this.initialize(img.Walk_000);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_001 = function() {
	this.initialize(img.Walk_001);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_002 = function() {
	this.initialize(img.Walk_002);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_003 = function() {
	this.initialize(img.Walk_003);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_004 = function() {
	this.initialize(img.Walk_004);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_005 = function() {
	this.initialize(img.Walk_005);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_006 = function() {
	this.initialize(img.Walk_006);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_007 = function() {
	this.initialize(img.Walk_007);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_008 = function() {
	this.initialize(img.Walk_008);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_009 = function() {
	this.initialize(img.Walk_009);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_010 = function() {
	this.initialize(img.Walk_010);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Walk_011 = function() {
	this.initialize(img.Walk_011);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,600,600);


(lib.Yeti_Attack0 = function() {
	this.initialize(img.Yeti_Attack0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack1 = function() {
	this.initialize(img.Yeti_Attack1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack2 = function() {
	this.initialize(img.Yeti_Attack2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack3 = function() {
	this.initialize(img.Yeti_Attack3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack4 = function() {
	this.initialize(img.Yeti_Attack4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack5 = function() {
	this.initialize(img.Yeti_Attack5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack6 = function() {
	this.initialize(img.Yeti_Attack6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack7 = function() {
	this.initialize(img.Yeti_Attack7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.Yeti_Attack8 = function() {
	this.initialize(img.Yeti_Attack8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,116,128);


(lib.YetiCCHUD = function() {
	this.initialize(img.YetiCCHUD);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,88,98);


(lib.YetiGrey_Attack0 = function() {
	this.initialize(img.YetiGrey_Attack0);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack1 = function() {
	this.initialize(img.YetiGrey_Attack1);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack2 = function() {
	this.initialize(img.YetiGrey_Attack2);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack3 = function() {
	this.initialize(img.YetiGrey_Attack3);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack4 = function() {
	this.initialize(img.YetiGrey_Attack4);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack5 = function() {
	this.initialize(img.YetiGrey_Attack5);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack6 = function() {
	this.initialize(img.YetiGrey_Attack6);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack7 = function() {
	this.initialize(img.YetiGrey_Attack7);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGrey_Attack8 = function() {
	this.initialize(img.YetiGrey_Attack8);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,118,128);


(lib.YetiGreyHUD = function() {
	this.initialize(img.YetiGreyHUD);
}).prototype = p = new cjs.Bitmap();
p.nominalBounds = new cjs.Rectangle(0,0,82,96);


(lib.Zombie5 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib._5Walk_000();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_1 = new lib._5Walk_001();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_2 = new lib._5Walk_002();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_3 = new lib._5Walk_003();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_4 = new lib._5Walk_004();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_5 = new lib._5Walk_005();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_6 = new lib._5Walk_006();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_7 = new lib._5Walk_007();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_8 = new lib._5Walk_008();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_9 = new lib._5Walk_009();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_10 = new lib._5Walk_010();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_11 = new lib._5Walk_011();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.213,0.213,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.Zombie4 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib._4Walk_000();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_1 = new lib._4Walk_001();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_2 = new lib._4Walk_002();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_3 = new lib._4Walk_003();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_4 = new lib._4Walk_004();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_5 = new lib._4Walk_005();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_6 = new lib._4Walk_006();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_7 = new lib._4Walk_007();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_8 = new lib._4Walk_008();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_9 = new lib._4Walk_009();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_10 = new lib._4Walk_010();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_11 = new lib._4Walk_011();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.213,0.213,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.Zombie3 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib._2Walk_000();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_1 = new lib._2Walk_001();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_2 = new lib._2Walk_002();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_3 = new lib._2Walk_003();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_4 = new lib._2Walk_004();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_5 = new lib._2Walk_005();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_6 = new lib._2Walk_006();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_7 = new lib._2Walk_007();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_8 = new lib._2Walk_008();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_9 = new lib._2Walk_009();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_10 = new lib._2Walk_010();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_11 = new lib._2Walk_011();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.213,0.213,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.Zombie2 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib._1Walk_000();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_1 = new lib._1Walk_001();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_2 = new lib._1Walk_002();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_3 = new lib._1Walk_003();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_4 = new lib._1Walk_004();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_5 = new lib._1Walk_005();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_6 = new lib._1Walk_006();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_7 = new lib._1Walk_007();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_8 = new lib._1Walk_008();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_9 = new lib._1Walk_009();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_10 = new lib._1Walk_010();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_11 = new lib._1Walk_011();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.213,0.213,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.Zombie1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.Walk_000();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_1 = new lib.Walk_001();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_2 = new lib.Walk_002();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_3 = new lib.Walk_003();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_4 = new lib.Walk_004();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_5 = new lib.Walk_005();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_6 = new lib.Walk_006();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_7 = new lib.Walk_007();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_8 = new lib.Walk_008();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_9 = new lib.Walk_009();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_10 = new lib.Walk_010();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.213,0.213,0,0,180);

	this.instance_11 = new lib.Walk_011();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.213,0.213,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.YetiGreyHUD_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.YetiGreyHUD();
	this.instance.parent = this;
	this.instance.setTransform(-41,-48);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-41,-48,82,96);


(lib.YetiGrey = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.YetiGrey_Attack0();
	this.instance.parent = this;
	this.instance.setTransform(59,-64,1,1,0,0,180);

	this.instance_1 = new lib.YetiGrey_Attack1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(59,-64,1,1,0,0,180);

	this.instance_2 = new lib.YetiGrey_Attack2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(59,-64,1,1,0,0,180);

	this.instance_3 = new lib.YetiGrey_Attack3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(59,-64,1,1,0,0,180);

	this.instance_4 = new lib.YetiGrey_Attack4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(59,-64,1,1,0,0,180);

	this.instance_5 = new lib.YetiGrey_Attack5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(59,-64,1,1,0,0,180);

	this.instance_6 = new lib.YetiGrey_Attack6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(59,-64,1,1,0,0,180);

	this.instance_7 = new lib.YetiGrey_Attack7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(59,-64,1,1,0,0,180);

	this.instance_8 = new lib.YetiGrey_Attack8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(59,-64,1,1,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-59,-64,118,128);


(lib.YetiCCHUD_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.YetiCCHUD();
	this.instance.parent = this;
	this.instance.setTransform(-44,-49);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-44,-49,88,98);


(lib.YetiCC = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.Yeti_Attack0();
	this.instance.parent = this;
	this.instance.setTransform(58,-64,1,1,0,0,180);

	this.instance_1 = new lib.Yeti_Attack1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(58,-64,1,1,0,0,180);

	this.instance_2 = new lib.Yeti_Attack2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(58,-64,1,1,0,0,180);

	this.instance_3 = new lib.Yeti_Attack3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(58,-64,1,1,0,0,180);

	this.instance_4 = new lib.Yeti_Attack4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(58,-64,1,1,0,0,180);

	this.instance_5 = new lib.Yeti_Attack5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(58,-64,1,1,0,0,180);

	this.instance_6 = new lib.Yeti_Attack6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(58,-64,1,1,0,0,180);

	this.instance_7 = new lib.Yeti_Attack7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(58,-64,1,1,0,0,180);

	this.instance_8 = new lib.Yeti_Attack8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(58,-64,1,1,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-58,-64,116,128);


(lib.SnowyBackground_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.SnowyBackground();
	this.instance.parent = this;
	this.instance.setTransform(0,0,1.25,1.333);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,1280,768);


(lib.snowball_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.snowball();
	this.instance.parent = this;
	this.instance.setTransform(-32,-32);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-32,-32,64,64);


(lib.SettingsHUD_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.SettingsHUD();
	this.instance.parent = this;
	this.instance.setTransform(-42,-36);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-42,-36,85,72);


(lib.SettingsBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.settingButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.saveBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.saveButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.SantaHUD_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.SantaHUD();
	this.instance.parent = this;
	this.instance.setTransform(-46,-43);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-46,-43,93,87);


(lib.Santa = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.Santa0();
	this.instance.parent = this;
	this.instance.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_1 = new lib.Santa1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_2 = new lib.Santa2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_3 = new lib.Santa3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_4 = new lib.Santa4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_5 = new lib.Santa5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_6 = new lib.Santa6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_7 = new lib.Santa7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_8 = new lib.Santa8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_9 = new lib.Santa9();
	this.instance_9.parent = this;
	this.instance_9.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_10 = new lib.Santa10();
	this.instance_10.parent = this;
	this.instance_10.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_11 = new lib.Santa11();
	this.instance_11.parent = this;
	this.instance_11.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_12 = new lib.Santa12();
	this.instance_12.parent = this;
	this.instance_12.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_13 = new lib.Santa13();
	this.instance_13.parent = this;
	this.instance_13.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_14 = new lib.Santa14();
	this.instance_14.parent = this;
	this.instance_14.setTransform(64,-64,0.853,0.853,0,0,180);

	this.instance_15 = new lib.Santa15();
	this.instance_15.parent = this;
	this.instance_15.setTransform(64,-64,0.853,0.853,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).to({state:[{t:this.instance_10}]},1).to({state:[{t:this.instance_11}]},1).to({state:[{t:this.instance_12}]},1).to({state:[{t:this.instance_13}]},1).to({state:[{t:this.instance_14}]},1).to({state:[{t:this.instance_15}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-64,-64,128,128);


(lib.resumeBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.resumeButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.quitBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.quitButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.present_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.present();
	this.instance.parent = this;
	this.instance.setTransform(-32,-24);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-32,-24,64,48);


(lib.playBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.EasyMode();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.pauseMenu_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.pauseMenu();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.378,0.435);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,300,480);


(lib.ornament_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.ornament();
	this.instance.parent = this;
	this.instance.setTransform(-16,-16,0.571,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-16,-16,32,32);


(lib.muteBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.muteButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.864,0.977);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,260,128);


(lib.mainMenuBtn = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.mainMenuButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.mainMenu_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.mainMenu();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.378,0.435);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,300,480);


(lib.mainBG_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.mainBG();
	this.instance.parent = this;

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,1280,768);


(lib.loadButton_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.loadButton();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.iceBolt = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.ice0();
	this.instance.parent = this;
	this.instance.setTransform(-32,-32);

	this.instance_1 = new lib.ice1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(-32,-32);

	this.instance_2 = new lib.ice2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(-32,-32);

	this.instance_3 = new lib.ice3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(-32,-32);

	this.instance_4 = new lib.ice4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(-32,-32);

	this.instance_5 = new lib.ice5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(-32,-32);

	this.instance_6 = new lib.ice6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(-32,-32);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-32,-32,63,63);


(lib.HardMode_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.HardMode();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.29,0.336);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,145,47);


(lib.gameover_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.gameover();
	this.instance.parent = this;
	this.instance.setTransform(0,0,0.378,0.435);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,300,480);


(lib.DeerTowerHud = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.DeerCaneHud();
	this.instance.parent = this;
	this.instance.setTransform(-39,-43);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-39,-43,78,86);


(lib.DeerTower = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.DeerTower0();
	this.instance.parent = this;
	this.instance.setTransform(39,-64,1,1,0,0,180);

	this.instance_1 = new lib.DeerTower1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(39,-64,1,1,0,0,180);

	this.instance_2 = new lib.DeerTower2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(39,-64,1,1,0,0,180);

	this.instance_3 = new lib.DeerTower3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(39,-64,1,1,0,0,180);

	this.instance_4 = new lib.DeerTower4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(39,-64,1,1,0,0,180);

	this.instance_5 = new lib.DeerTower5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(39,-64,1,1,0,0,180);

	this.instance_6 = new lib.DeerTower6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(39,-64,1,1,0,0,180);

	this.instance_7 = new lib.DeerTower7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(39,-64,1,1,0,0,180);

	this.instance_8 = new lib.DeerTower8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(39,-64,1,1,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-39,-64,78,128);


(lib.CCTowerHud_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.CCTowerHud();
	this.instance.parent = this;

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,63,100);


(lib.CCTower1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.CandyCane0();
	this.instance.parent = this;
	this.instance.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_1 = new lib.CandyCane1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_2 = new lib.CandyCane2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_3 = new lib.CandyCane3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_4 = new lib.CandyCane4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_5 = new lib.CandyCane5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_6 = new lib.CandyCane6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_7 = new lib.CandyCane7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_8 = new lib.CandyCane8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(32,-64,0.557,0.506,0,0,180);

	this.instance_9 = new lib.CandyCane9();
	this.instance_9.parent = this;
	this.instance_9.setTransform(32,-64,0.557,0.506,0,0,180);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).to({state:[{t:this.instance_9}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-32,-64,64,128);


(lib.Bullet = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.ccBulletRotate0();
	this.instance.parent = this;
	this.instance.setTransform(-39,-30);

	this.instance_1 = new lib.ccBulletRotate1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(-39,-30);

	this.instance_2 = new lib.ccBulletRotate2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(-39,-30);

	this.instance_3 = new lib.ccBulletRotate3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(-39,-30);

	this.instance_4 = new lib.ccBulletRotate4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(-39,-30);

	this.instance_5 = new lib.ccBulletRotate5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(-39,-30);

	this.instance_6 = new lib.ccBulletRotate6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(-39,-30);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-39,-30,78,61);


(lib.Boss3 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.FrostyWig0();
	this.instance.parent = this;
	this.instance.setTransform(-58,-64);

	this.instance_1 = new lib.FrostyWig1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(-58,-64);

	this.instance_2 = new lib.FrostyWig2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(-58,-64);

	this.instance_3 = new lib.FrostyWig3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(-58,-64);

	this.instance_4 = new lib.FrostyWig4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(-58,-64);

	this.instance_5 = new lib.FrostyWig5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(-58,-64);

	this.instance_6 = new lib.FrostyWig6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(-58,-64);

	this.instance_7 = new lib.FrostyWig7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(-58,-64);

	this.instance_8 = new lib.FrostyWig8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(-58,-64);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-58,-64,117,128);


(lib.Boss2 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.FrostyCC0();
	this.instance.parent = this;
	this.instance.setTransform(-45,-64);

	this.instance_1 = new lib.FrostyCC1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(-45,-64);

	this.instance_2 = new lib.FrostyCC2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(-45,-64);

	this.instance_3 = new lib.FrostyCC3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(-45,-64);

	this.instance_4 = new lib.FrostyCC4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(-45,-64);

	this.instance_5 = new lib.FrostyCC5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(-45,-64);

	this.instance_6 = new lib.FrostyCC6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(-45,-64);

	this.instance_7 = new lib.FrostyCC7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(-45,-64);

	this.instance_8 = new lib.FrostyCC8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(-45,-64);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-45,-64,90,128);


(lib.Boss1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.FrostyTH0();
	this.instance.parent = this;
	this.instance.setTransform(-45,-64);

	this.instance_1 = new lib.FrostyTH1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(-45,-64);

	this.instance_2 = new lib.FrostyTH2();
	this.instance_2.parent = this;
	this.instance_2.setTransform(-45,-64);

	this.instance_3 = new lib.FrostyTH3();
	this.instance_3.parent = this;
	this.instance_3.setTransform(-45,-64);

	this.instance_4 = new lib.FrostyTH4();
	this.instance_4.parent = this;
	this.instance_4.setTransform(-45,-64);

	this.instance_5 = new lib.FrostyTH5();
	this.instance_5.parent = this;
	this.instance_5.setTransform(-45,-64);

	this.instance_6 = new lib.FrostyTH6();
	this.instance_6.parent = this;
	this.instance_6.setTransform(-45,-64);

	this.instance_7 = new lib.FrostyTH7();
	this.instance_7.parent = this;
	this.instance_7.setTransform(-45,-64);

	this.instance_8 = new lib.FrostyTH8();
	this.instance_8.parent = this;
	this.instance_8.setTransform(-45,-64);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance}]}).to({state:[{t:this.instance_1}]},1).to({state:[{t:this.instance_2}]},1).to({state:[{t:this.instance_3}]},1).to({state:[{t:this.instance_4}]},1).to({state:[{t:this.instance_5}]},1).to({state:[{t:this.instance_6}]},1).to({state:[{t:this.instance_7}]},1).to({state:[{t:this.instance_8}]},1).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-45,-64,91,128);


(lib.Board_1 = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.Board();
	this.instance.parent = this;

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(0,0,1280,768);


(lib.Background = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = null;


// stage content:
(lib.assets = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Layer 1
	this.instance = new lib.ornament_1();
	this.instance.parent = this;
	this.instance.setTransform(315.1,446.6);

	this.instance_1 = new lib.present_1();
	this.instance_1.parent = this;
	this.instance_1.setTransform(435.7,442.9);

	this.instance_2 = new lib.snowball_1();
	this.instance_2.parent = this;
	this.instance_2.setTransform(230.1,450.9);

	this.instance_3 = new lib.iceBolt();
	this.instance_3.parent = this;
	this.instance_3.setTransform(145,441.8,1,1,0,0,0,31.5,31.5);

	this.instance_4 = new lib.mainMenuBtn();
	this.instance_4.parent = this;
	this.instance_4.setTransform(1462.7,346,1,1,0,0,0,130,50);

	this.instance_5 = new lib.gameover_1();
	this.instance_5.parent = this;
	this.instance_5.setTransform(1405.3,417.3,1,1,0,0,0,150,240);

	this.instance_6 = new lib.SettingsBtn();
	this.instance_6.parent = this;
	this.instance_6.setTransform(1079.3,502.7,0.577,0.482,0,0,0,130.2,50);

	this.instance_7 = new lib.loadButton_1();
	this.instance_7.parent = this;
	this.instance_7.setTransform(1078.1,444.2,0.567,0.433,0,0,0,130.3,50.1);

	this.instance_8 = new lib.HardMode_1();
	this.instance_8.parent = this;
	this.instance_8.setTransform(1007.1,353.9,0.545,0.464);

	this.instance_9 = new lib.Boss3();
	this.instance_9.parent = this;
	this.instance_9.setTransform(338.3,241.3,1,1,0,0,0,0.5,0);

	this.instance_10 = new lib.Boss2();
	this.instance_10.parent = this;
	this.instance_10.setTransform(242.1,232);

	this.instance_11 = new lib.Boss1();
	this.instance_11.parent = this;
	this.instance_11.setTransform(151.6,232,1,1,0,0,0,0.5,0);

	this.instance_12 = new lib.SettingsHUD_1();
	this.instance_12.parent = this;
	this.instance_12.setTransform(543.9,317.9,1,1,0,0,0,0.5,0);

	this.instance_13 = new lib.SantaHUD_1();
	this.instance_13.parent = this;
	this.instance_13.setTransform(436.4,701.2,1,1,0,0,0,0.5,0.5);

	this.instance_14 = new lib.Santa();
	this.instance_14.parent = this;
	this.instance_14.setTransform(436.2,578.3);

	this.instance_15 = new lib.YetiGreyHUD_1();
	this.instance_15.parent = this;
	this.instance_15.setTransform(320.8,697.9);

	this.instance_16 = new lib.YetiCCHUD_1();
	this.instance_16.parent = this;
	this.instance_16.setTransform(235.8,708.7);

	this.instance_17 = new lib.YetiGrey();
	this.instance_17.parent = this;
	this.instance_17.setTransform(315.1,578.3);

	this.instance_18 = new lib.YetiCC();
	this.instance_18.parent = this;
	this.instance_18.setTransform(230.1,578.3);

	this.instance_19 = new lib.Zombie5();
	this.instance_19.parent = this;
	this.instance_19.setTransform(55.1,229.6);

	this.instance_20 = new lib.Zombie4();
	this.instance_20.parent = this;
	this.instance_20.setTransform(236.1,104);

	this.instance_21 = new lib.Bullet();
	this.instance_21.parent = this;
	this.instance_21.setTransform(49.6,442.8,1,1,0,0,0,0,0.5);

	this.instance_22 = new lib.DeerTower();
	this.instance_22.parent = this;
	this.instance_22.setTransform(197.1,634.5,1,1,0,0,0,39,64);

	this.instance_23 = new lib.DeerTowerHud();
	this.instance_23.parent = this;
	this.instance_23.setTransform(137.5,702.7);

	this.instance_24 = new lib.CCTowerHud_1();
	this.instance_24.parent = this;
	this.instance_24.setTransform(57.1,707.7,1,1,0,0,180,31.5,50);

	this.instance_25 = new lib.saveBtn();
	this.instance_25.parent = this;
	this.instance_25.setTransform(796.1,391.2,0.924,0.77,0,0,0,130.1,67.2);

	this.instance_26 = new lib.playBtn();
	this.instance_26.parent = this;
	this.instance_26.setTransform(1019.2,293.6,0.556,0.464);

	this.instance_27 = new lib.mainMenu_1();
	this.instance_27.parent = this;
	this.instance_27.setTransform(1129.1,517.3,1,1,0,0,0,200,340);

	this.instance_28 = new lib.quitBtn();
	this.instance_28.parent = this;
	this.instance_28.setTransform(781.9,447,0.814,0.824,0,0,0,130.2,64.4);

	this.instance_29 = new lib.muteBtn();
	this.instance_29.parent = this;
	this.instance_29.setTransform(691.4,506.1,0.808,0.43,0,0,0,130,64);

	this.instance_30 = new lib.resumeBtn();
	this.instance_30.parent = this;
	this.instance_30.setTransform(837.3,343.9,0.922,0.762,0,0,0,180,70);

	this.instance_31 = new lib.pauseMenu_1();
	this.instance_31.parent = this;
	this.instance_31.setTransform(793.9,517.6,1,1,0,0,0,200.3,340.3);

	this.instance_32 = new lib.CCTower1();
	this.instance_32.parent = this;
	this.instance_32.setTransform(66.5,578.3);

	this.instance_33 = new lib.Zombie3();
	this.instance_33.parent = this;
	this.instance_33.setTransform(184.6,136,1,1,0,0,0,32,32);

	this.instance_34 = new lib.Zombie2();
	this.instance_34.parent = this;
	this.instance_34.setTransform(343.8,104);

	this.instance_35 = new lib.Zombie1();
	this.instance_35.parent = this;
	this.instance_35.setTransform(362.3,404.4,1,1,0,0,0,300.4,300.4);

	this.instance_36 = new lib.Board_1();
	this.instance_36.parent = this;

	this.instance_37 = new lib.mainBG_1();
	this.instance_37.parent = this;
	this.instance_37.setTransform(-1.9,0,1,1,0,0,0,0.1,0);

	this.instance_38 = new lib.SnowyBackground_1();
	this.instance_38.parent = this;
	this.instance_38.setTransform(640,360,1,1,0,0,0,640,360);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance_38},{t:this.instance_37},{t:this.instance_36},{t:this.instance_35},{t:this.instance_34},{t:this.instance_33},{t:this.instance_32},{t:this.instance_31},{t:this.instance_30},{t:this.instance_29},{t:this.instance_28},{t:this.instance_27},{t:this.instance_26},{t:this.instance_25},{t:this.instance_24},{t:this.instance_23},{t:this.instance_22},{t:this.instance_21},{t:this.instance_20},{t:this.instance_19},{t:this.instance_18},{t:this.instance_17},{t:this.instance_16},{t:this.instance_15},{t:this.instance_14},{t:this.instance_13},{t:this.instance_12},{t:this.instance_11},{t:this.instance_10},{t:this.instance_9},{t:this.instance_8},{t:this.instance_7},{t:this.instance_6},{t:this.instance_5},{t:this.instance_4},{t:this.instance_3},{t:this.instance_2},{t:this.instance_1},{t:this.instance}]}).wait(1));

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(631.1,384,1564.2,768);

})(lib = lib||{}, images = images||{}, createjs = createjs||{}, ss = ss||{});
var lib, images, createjs, ss;