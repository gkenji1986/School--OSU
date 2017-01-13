//makes table
function tableMaker()
{
	//get reference for body
	var htmlBody = document.getElementsByTagName("body")[0];

	// make table and table body elements
	var tbl = document.createElement("table");
	var tblCell = document.createElement("tbody");
	
	
	tbl.appendChild(tblCell);
	htmlBody.appendChild(tbl);
	//make 4x4 table
	for(var i = 0;i < 4; i++)
	{
		var row = document.createElement("tr");
		
		if(i ==0)
		{
			var row = document.createElement("tr");
			for(k = 1; k < 5; k++)
			{
				var tblHead = document.createElement("th");
				var textInHeader = document.createTextNode("Header" + k);
				tblHead.appendChild(textInHeader);
				row.appendChild(tblHead);
			}
		}
		//make rows
		if (i > 0)
		{
			
			for(var j = 0; j < 4; j++)
			{
				// create nodes with text label inside cell
				var cell = document.createElement("td");
				var num = j+1;
				var textInCell = document.createTextNode(num + "," + i);
		
				cell.appendChild(textInCell);
				row.appendChild(cell);
			}
		}
		//add rows
		tblCell.appendChild(row);
	}
	tbl.appendChild(tblCell);
	htmlBody.appendChild(tbl);
	tbl.setAttribute("border", "2");
	
	//highlight the first cell
	highlightCell(0);
	//make buttons
	createButton();
}

//makes cell bold
function highlightCell(currentLocation)
{
	var newCell = document.getElementsByTagName("table")[1];
	var selectedNewCell = newCell.getElementsByTagName("td");
	var highlightSelectedNewCell = selectedNewCell[currentLocation];
	highlightSelectedNewCell.style.border = "solid 5px";
}

//removes bold from cell
function removeHighlight (currentLocation)
{
	var previousCell = document.getElementsByTagName("table")[1];
	var selectedpreviousCell = previousCell.getElementsByTagName("td");
	var highlightSelectedpreviousCell = selectedpreviousCell[currentLocation];
	highlightSelectedpreviousCell.style.border = "solid 1px";
}

// makes background yellow
function markButtonClick(currentLocation)
{
	var nextCell = document.getElementsByTagName("table")[1];
	var selectednextCell = nextCell.getElementsByTagName("td");
	var highlightSelectednextCell = selectednextCell[currentLocation.value];
	highlightSelectednextCell.style.backgroundColor = "yellow";
}

//updates where the cell will become bold next
function updateLocation(event,currentLocation)
{
	if(event == "up")
	{
		currentLocation.value -= 4;
	}
	
	if(event == "down")
	{
		currentLocation.value += 4;
	}
	
	if(event == "left")
	{
		currentLocation.value -= 1;
	}
	
	if(event == "right")
	{
		currentLocation.value += 1;
	}
}

//changes cell based on which direction button is clicked
function directionButtonClick(event, currentLocation)
{
	if(event == "up" && currentLocation.value > 3)
	{
		var locationNum = currentLocation.value; 
		//return cell to original border
		removeHighlight (locationNum);
		
		//mark new cell
		updateLocation(event, currentLocation);
		locationNum = currentLocation.value; 
		highlightCell(locationNum);
	}
	
	if(event == "down" && currentLocation.value < 8)
	{
		 
		var locationNum = currentLocation.value; 
		//return cell to original border
		removeHighlight (locationNum);
		
		//mark new cell
		updateLocation(event, currentLocation);
		locationNum = currentLocation.value;
		highlightCell(locationNum);
	}
	
	if(event == "left" && currentLocation.value != 0 && currentLocation.value != 4 &&currentLocation.value != 8)
	{
		var locationNum = currentLocation.value; 
		//return cell to original border
		removeHighlight (locationNum);
		
		//mark new cell
		updateLocation(event, currentLocation);
		locationNum = currentLocation.value;
		highlightCell(locationNum);
	}
	
	if(event == "right" && currentLocation.value != 3 && currentLocation.value != 7 &&currentLocation.value != 11)
	{
		var locationNum = currentLocation.value; 
		//return cell to original border
		removeHighlight (locationNum);
		
		//mark new cell
		updateLocation(event, currentLocation);
		locationNum = currentLocation.value;
		highlightCell(locationNum);
	}
}

//creates buttons
function createButton()
{
	//make button for up
	var button_up = document.createElement('input');
	button_up.setAttribute("click", "directionButtonClick())");
	button_up.setAttribute("type", "button");
	button_up.setAttribute("value", "Up");
	button_up.setAttribute("id", "b_up");
	button_up.style.marginLeft = "20px";
	button_up.style.marginTop = "20px";
	document.body.appendChild(button_up);
	
	//make button for down
	var button_down = document.createElement("input");
	button_down.setAttribute("click", "directionButtonClick()");
	button_down.setAttribute("type", "button");
	button_down.setAttribute("value", "Down");
	button_down.setAttribute("id", "b_down");
	button_down.style.marginLeft = "20px";
	button_down.style.marginTop = "20px";
	document.body.appendChild(button_down);
	
	//make button for left
	var button_left = document.createElement("input");
	button_left.setAttribute("click", "directionButtonClick()");
	button_left.setAttribute("type", "button");
	button_left.setAttribute("value", "Left");
	button_left.setAttribute("id", "b_left");
	button_left.style.marginLeft = "20px";
	button_left.style.marginTop = "20px";
	document.body.appendChild(button_left);
	
	//make button for right
	var button_right = document.createElement("input");
	button_right.setAttribute("click", "directionButtonClick()");
	button_right.setAttribute("type", "button");
	button_right.setAttribute("value", "Right");
	button_right.setAttribute("id", "b_right");
	button_right.style.marginLeft = "20px";
	button_right.style.marginTop = "20px";
	document.body.appendChild(button_right);
	
	//create button for yellow background
	var button_mark = document.createElement("input");
	button_mark.setAttribute("click", "markButtonClick()");
	button_mark.setAttribute("type", "button");
	button_mark.setAttribute("value", "Mark");
	button_mark.setAttribute("id", "b_mark");
	button_mark.style.marginLeft = "20px";
	button_mark.style.marginTop = "20px";
	document.body.appendChild(button_mark);
}
//set location for first bold cell
var currentLocation = {value: 0};

//make table and buttons
tableMaker();
	
//events for clicks	
document.getElementById("b_up").onclick = function(){directionButtonClick("up", currentLocation)};
document.getElementById("b_down").onclick = function(){directionButtonClick("down", currentLocation)};
document.getElementById("b_left").onclick = function(){directionButtonClick("left", currentLocation)};
document.getElementById("b_right").onclick = function(){directionButtonClick("right", currentLocation)};
document.getElementById("b_mark").onclick = function(){markButtonClick(currentLocation)};

