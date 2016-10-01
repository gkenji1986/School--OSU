/****************************
* Grant Nakashima
* CS362-400
* 7/6/2016
* Assignment 3
* Unit test for buyCard
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

	printf("Testing buyCard function\n");

	//set the amount of buys, coins, discard count and whose turn
	g.whoseTurn = 0;
	g.discardCount[0] = 0;
	g.supplyCount[duchy] = 0;
	g.supplyCount[province] = 4;
	g.numBuys = 3;
	g.coins = 9999;

	printf("Checking buyCard function...\n");
	myassert(!buyCard(province, &g));		//check if buyCard works
	printf("buyCard for province Passed.\n\n");
	printf("Checking number of coins after purchase...\n");
	myassert(g.coins == (9991));		//check if number of coins decremented properly
	printf("Number of coins Passed.\n\n");
	printf("Checking number of buys after purchase...\n");
	myassert(g.numBuys == 2);		//check to see if number of buys decremented
	printf("Number of buys Passed.\n\n");
	printf("Checking number of provinces left after purchase...\n");
	myassert(g.supplyCount[province] == 3);		//check to see if the number of provinces decremented properly
	printf("Checking number of provinces left after purchase...\n");
	printf("Number of Provinces Passed.\n\n");
	printf("Checking number of discards left after purchase...\n");
	myassert(g.discardCount[0] == 1);			//check to see if discardCount incremented properly
	printf("Number of Discards Passed.\n\n");
	myassert(g.discard[0][0] == province);		//check to see if discarded card is province and not any other card

	printf("Checking if duchy can be purchased when 0...\n");
	myassert(buyCard(duchy, &g));			//check if buyCard will fail properly
	printf("Failure of Duchy purchase Passed\n");

	g.coins = 0;		//set number of coins to 0

	printf("Checking if province can be purchased when coins is set to 0...\n");
	myassert(buyCard(province, &g));		//check if buyCard will fail when user has no coins
	printf("Failure of Province purchase Passed\n");

	g.numBuys = 0;
	g.coins = 9999;
	printf("Checking if province can be purchased when number of buys is 0 and have sufficient coins...\n");
	myassert(buyCard(province, &g));		//check if buyCard will fail when user has no more buys turns left
	printf("Failure of Province purchase Passed\n\n");

	printf("buyCard test complete.\n\n");

	return 0;
}