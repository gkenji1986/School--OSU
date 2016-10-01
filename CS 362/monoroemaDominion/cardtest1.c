/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for smithy effect 
*****************************/

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void myassert(int val)
{
	if (val)
	{
		printf("PASSED.\n");
	}

	else
	{
		printf("FAILED.\n");
	}

	return;
}

//Testing smithy card
int main(int argc, char** argv) 
{
	struct gameState g;
	int i;
	
	//initialize state
	g.numActions = 1;
	g.whoseTurn = 0;
	g.handCount[0] = 1;
	g.hand[0][0] = smithy;
	g.discardCount[0] = 0;
	g.deckCount[0] = 10;
	g.deck[0][0] = province;
	g.deck[0][1] = province;
	g.deck[0][2] = province;
	g.deck[0][3] = province;
	g.deck[0][4] = province;
	g.deck[0][5] = province;
	g.deck[0][6] = province;
	g.deck[0][7] = province;
	g.deck[0][8] = province;
	g.deck[0][9] = province;


	printf("Playing Smithy card.\n");
	playCard(0, 0, 0, 0, &g);		//play smithy card
	
	printf("Checking hand count...\n");
	printf("handcount: %d \n", g.handCount[0]);
	myassert(g.handCount[0] == 3);	//see if hand count stayed the same
	printf("Checking deck count...\n");
	myassert(g.deckCount[0] == 0);	//check if deck count decremented to 0 correctly
	printf("Checking hand cards...\n");
	myassert(g.hand[0][0] == province);
	printf("Checking hand cards...\n");
	myassert(g.hand[0][1] == province);
	printf("Checking hand cards...\n");
	myassert(g.hand[0][2] == province);
	printf("Checking action count...\n");
	myassert(g.numActions == 0);		// check if number of actions decremented correctly

	for (i = 0; i < g.handCount[0]; i++) 
	{
		if (g.hand[0][i] == smithy)		//check players hand to make sure the player doesnt have the smithy card anymore
		{
			printf("Error: Player should have no smithy cards in hand after playing card!\n");
		}
	}

	printf("Smithy card test complete...\n");

	return 0;
}
