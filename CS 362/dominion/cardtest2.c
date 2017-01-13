/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for Great Hall
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"

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

	//set initial amount for great hall
	g.whoseTurn = 0;
	g.numActions = 1;
	g.handCount[0] = 1;
	g.hand[0][0] = great_hall;
	g.deckCount[0] = 1;
	g.deck[0][0] = province;
	g.discardCount[0] = 0;

	printf("Playing Great hall card.\n");
	playCard(0, 0, 0, 0, &g);		//play great hall card
	printf("Checking hand count...\n");
	myassert(g.handCount[0] == 1);		//check to see if the initialize worked;
	printf("Checking number of actions...\n");
	myassert(g.numActions == 1);				// see if number of actions decremented
	printf("Checking deck size...\n");
	myassert(g.deckCount[0] == 0);		// check to see if the deck size decremented
	printf("Checking hand cards...\n");
	myassert(g.hand[0][0] == province);
	printf("\nGreat Hall card test complete.\n");

	return 0;
}