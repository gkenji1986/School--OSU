/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for Village card
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

int main(int argc, char** argv)
{
	struct gameState g;

	//initialize village card manually
	g.whoseTurn = 0;
	g.numActions = 1;
	g.handCount[0] = 1;
	g.hand[0][0] = village;
	g.discardCount[0] = 0;
	g.deckCount[0] = 1;
	g.deck[0][0] = province;

	printf("Playing Village card.\n");
	playCard(0, 0, 0, 0, &g);		//play the village card
	printf("Checking number of actions...\n");
	myassert(g.numActions == 2);		//check if number of actions incremented correctly
	printf("Checking deck count...\n");
	myassert(g.deckCount[0] == 0);	// check if deck count decremented correctly
	printf("Checking hand count...\n");
	myassert(g.handCount[0] == 1);	// check if hand count stayed the same
	printf("Checking cards in hand...\n");
	myassert(g.hand[0][0] == province);
	printf("\nVillage card test complete.\n");

	return 0;
}