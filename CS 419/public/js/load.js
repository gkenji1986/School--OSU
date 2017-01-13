var canvas, stage, exportRoot, i = 0;

function init() {
	canvas = document.getElementById("canvas");
	images = images||{};
	var loader = new createjs.LoadQueue(false);
	loader.addEventListener("fileload", handleFileLoad);
	loader.addEventListener("complete", handleComplete);
	loader.loadManifest(lib.properties.manifest);
	
}
function handleFileLoad(evt) {	
	if (evt.item.type == "image") { images[evt.item.id] = evt.result; }	
	i = i + 1;
    try {
        if (typeof user === "undefined")
        {
            document.getElementById("scroller").style.display = "block";
            document.getElementById("gameCanvas").style.display = "none";
            playOpening();
        }
        else
        {
            document.getElementById("scroller").remove();
            //document.getElementById("gameCanvas").style.display = "block";
            
            document.getElementById("percent").innerHTML = "Loading: " + ((i / 169) * 100).toPrecision(4) + "%";
        }
		
		//
	}
	catch(err) {
		console.log("Loading Completed");
	}
	
}
function handleComplete(evt) {

    var seconds = 25;
    
    if (typeof user === "undefined")
	{
        var debug = false;
	}
	else
	{
	    var debug = true;
	}
    if (debug) {
        document.getElementById("percent").remove();
		//document.getElementById("gameCanvas").style.display = "block";
	} else {
		setTimeout(function() {
		    document.getElementById("scroller").remove();
		    document.getElementById("percent").remove();
			document.getElementById("gameCanvas").style.display = "block";
		}, seconds*1000);
	}
}

function playOpening() {
    $(document).ready(function () {
        var audioElm = $('#opening').get(0);
        audioElm.play();
        audioElm.volume = 1;
    })
};
