/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for Adventurer
*****************************/

#include "dominion.h"
#include "dominion_helpers.h"
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
	struct gameState g, gcopy;
	int status = -1;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy }; // Create cards variable 
	int choices[3] = { 0 };
	int pos = 0;
	int cards = 0;
	int prevCards = 0;
	int prevTreasure = 0;
	int treasure = 0;
	int i = 0;

	printf("Playing Adventurer card.\n");
	status = initializeGame(2, k, 4, &g);
	printf("\nChecking status of initalization...\n");
	myassert(status == 0);
	printf("Status of initalization Passed\n");

	memcpy(&gcopy, &g, sizeof(struct gameState));		//make a copy of the game state

	while (i < numHandCards(&gcopy))		//i must be set to 5 to get treasure to get incremented twice. setting to 0 will set treasure to 5
	{
		if (gcopy.hand[0][i] == copper || gcopy.hand[0][i] == silver || gcopy.hand[0][i] == gold)		//check to see if card is copper, silver or gold
		{
			prevCards++;
			prevTreasure++;
		}
		else
		{
			prevCards++;
		}
		i++;
	}

	status = cardEffect(adventurer, choices[0], choices[1], choices[2], &gcopy, pos, NULL);
	printf("Checking status of adventurer...\n");
	myassert(status == 0);
	printf("Status of cardEffect Passed...\n");

	i = 0;

	while(i < numHandCards(&gcopy))		//i must be set to 5 to get treasure to get incremented twice. setting to 0 will set treasure to 5
	{
		if (gcopy.hand[0][i] == copper || gcopy.hand[0][i] == silver || gcopy.hand[0][i] == gold)		//check to see if card is copper, silver or gold
		{
			cards++;
			treasure++;
		}
		else
		{
			cards++;
		}
		i++;
	}

	printf("Check if treasure is 2...\n");
	myassert(treasure - prevTreasure == 2);
	printf("Check if the deck counts is correct...\n");
	myassert(gcopy.deckCount[0] == g.deckCount[0] - cards);
	printf("Check if discard count is correct..\n");
	myassert(gcopy.discardCount[0] == cards - treasure);

	printf("Adventure card test complete.\n");

	return 0;
}