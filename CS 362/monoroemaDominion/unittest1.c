/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for isGameOver
*****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
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
	int i = 0;
	int k = 0;
	int j = 0;
	int status = -1;
	int c[10] = { adventurer, mine, smithy, great_hall, ambassador, cutpurse, salvager, steward, minion, village };

	printf("Game has begun\n");
	status = initializeGame(2, c, 5, &g);		//2 Players
	printf("\nChecking status of initalization...\n");
	myassert(status == 0);
	printf("Status of initalization Passed\n");

	printf("Checking isGameOver...\n");
	myassert(isGameOver(&g) == 0);		//Check if the game is over
	printf("isGameOver passed.\n");

	g.supplyCount[province] = 0;			//set province to zero so the game is over
	printf("Province count is now set to 0.\n");
	printf("Checking isGameOver...\n");
	myassert(isGameOver(&g) == 1);			//should return 1 since the game is over
	printf("isGameOver Passed.\n");

	g.supplyCount[province] = 12;		//reset province count

	printf("Checking isGameOver...\n");
	for (i = 0; i < 8; i++) 
	{
		for (j = i + 1; j < 9; j++)
		{
			for (k = j + 1; k < 10; k++) 
			{
				g.supplyCount[i] = 0;
				g.supplyCount[j] = 0;
				g.supplyCount[k] = 0;
				myassert(isGameOver(&g) == 1);
				g.supplyCount[i] = 10;
				g.supplyCount[j] = 10;
				g.supplyCount[k] = 10;
				//reset card count
			}
		}
	}
	printf("isGameOver test complete.\n\n");

	return 0;
}