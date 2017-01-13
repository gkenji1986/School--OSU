/******************
 * Name: Matt Monroe
 * Assignment 2
 * CS 362
 * ***************/

Changes to the following: 
	playAdventurer()->changes drawnTreasure < 2 to drawnTreasure < 3 (draws extra card)
	playSmithy()-> changes for loop from for (i=0, i<3, i++) to for (i=3, i>0,i--) (draws extra card)
	playCouncilRoom()-> changed if (i != currentPlayer) to if (i ==currentPlayer) (no card draw
for opposing players)
	playCutPurse()->changed if (state->hand[i][j] == copper) to if (state->hand[i][j] == silver) makes 
other players discard silver instead of copper
	playSalvager()->no changes  
	
