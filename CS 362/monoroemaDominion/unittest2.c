/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for shuffle
*****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
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
	int c[10] = { adventurer, mine, smithy, great_hall, ambassador, cutpurse, salvager, steward, minion, village };
	int status = -1;

	printf("Game has begun.\n");
	printf("\nChecking status of initalization...\n");
	status = initializeGame(2, c, 100, &g);
	myassert(status == 0);
	printf("Status of initalization Passed\n");

	g.deckCount[1] = 0;		//set deck to 0
	
	printf("Checking shuffle function...\n");
	myassert((shuffle(1, &g)) == -1);

	g.deckCount[1] = 10;		//set deck to 10
	printf("Checking shuffle function...\n");
	myassert((shuffle(1, &g)) == 0);

	printf("Shuffle tests complete.\n\n");
	
	return 0;
}