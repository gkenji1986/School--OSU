/***********************************
* Author: Grant Nakashima
* Due Date: 7/24/16
* Assignment: Assignment 4
* File: randomtestadventurer.c
************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include "math.h" 
#include <time.h> 

#define TEST_NUM 10000
#define PLAYER_NUMBER 2
#define PLAYER 0
#define OPPONENT 1
#define ACTION_NUMBER 1
#define CARD_NUM 2
#define CARD_NEXT 0
#define BUY_NUMBER 0

void randomizeGameState(struct gameState *game);
void randomCardTest(struct gameState *game, struct gameState *testGame, int shuffle, int discard);

int main() 
{
	int discard = 0;
	int shuffleCard = 0;
	int handpos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;

	int seed;
	struct gameState game;
	struct gameState testGame;
	int k[10] = { adventurer, steward, village, minion, smithy, great_hall, baron, salvager, cutpurse, council_room };
	
	int i, j;

	printf("Starting randomtestadventurer.c for: %s \n", "Adventurer");

	printf("Random Tests\n");

	for (i = 0; i < TEST_NUM; i++)
	{
		seed = rand();

		for (j = 0; j < sizeof(struct gameState); j++)	//initialize struct using random data
		{
			((char*)&game)[j] = floor(Random() * 256);
		}
		
		initializeGame(PLAYER_NUMBER, k, seed++, &game);		//initialize game

		randomizeGameState(&game);	//set random state

		memcpy(&testGame, &game, sizeof(struct gameState));				// make copy of game state

		cardEffect(adventurer, choice1, choice2, choice3, &testGame, handpos, &bonus);		//use adventurer card

		randomCardTest(&game, &testGame, shuffleCard, discard);		// check game state using tests
	}

	printf("Tests completed!\n");

	return 0;
}

void randomizeGameState(struct gameState *game)
{
	int i;

	
	game->handCount[PLAYER] = floor(Random() * 10);		//set counts for the player and opponent
	game->deckCount[PLAYER] = floor(Random() * 52);
	game->discardCount[PLAYER] = floor(Random() * 25);

	game->handCount[OPPONENT] = floor(Random() * 15);
	game->deckCount[OPPONENT] = floor(Random() * 52);

	for (i = 0; i < game->handCount[PLAYER]; i++)		//randomly select cards for hand pile
	{
		game->hand[PLAYER][i] = floor(Random() * (treasure_map + 1));
	}

	for (i = 0; i < game->discardCount[PLAYER]; i++)		//randomly select cards for discard pile
	{
		game->discard[PLAYER][i] = floor(Random() * (treasure_map + 1));
	}

	for (i = 0; i < game->deckCount[PLAYER]; i++)		//randomly select cards for deck 
	{
		game->deck[PLAYER][i] = floor(Random() * (treasure_map + 1));
	}
}

void randomCardTest(struct gameState *game, struct gameState *testGame, int shuffleCard, int discard)
{
	//Test adventurer card
	printf("***************************************************************\n");

	printf("Hand Count = %d, Expected Count= %d\n", testGame->handCount[PLAYER], game->handCount[PLAYER] + CARD_NUM - discard);
	if (testGame->handCount[PLAYER] == game->handCount[PLAYER] + CARD_NUM - discard)
	{
		printf("Adventurer: PASSED - handCount[PLAYER]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - handCount[PLAYER]\n");
	}
		
	printf("Deck Count = %d, Expected Count= %d\n", testGame->deckCount[PLAYER], game->deckCount[PLAYER] - CARD_NUM + shuffleCard);
	if (testGame->deckCount[PLAYER] == game->deckCount[PLAYER] - CARD_NUM + shuffleCard)
	{
		printf("Adventurer: PASSED - deckCount[PLAYER]\n");
	}
		
	else
	{
		printf("Adventurer: FAILED - deckCount[PLAYER]\n");
	}
		
	printf("Discard Count = %d, Expected Count= %d\n", testGame->discardCount[PLAYER], game->discardCount[PLAYER]);
	if (testGame->discardCount[PLAYER] == game->discardCount[PLAYER])
	{
		printf("Adventurer: PASSED - discardCount[PLAYER]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - discardCount[PLAYER]\n");
	}
		
	printf("Hand Count = %d, Expected Count= %d\n", testGame->handCount[OPPONENT], game->handCount[OPPONENT] + CARD_NEXT);
	if (testGame->handCount[OPPONENT] == game->handCount[OPPONENT] + CARD_NEXT)
	{
		printf("Adventurer: PASSED - handCount[OPPONENT]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - handCount[OPPONENT]\n");
	}
		
	printf("Deck Count = %d, Expected Count= %d\n", testGame->deckCount[OPPONENT], game->deckCount[OPPONENT] - CARD_NEXT);
	if (testGame->deckCount[OPPONENT] == game->deckCount[OPPONENT] - CARD_NEXT)
	{
		printf("Adventurer: PASSED - deckCount[OPPONENT]\n");
	}
	else
	{
		printf("Adventurer: FAILED - deckCount[OPPONENT]\n");
	}
		
	printf("Estate Count= %d, Expected Count= %d, Duchy Count= %d, Expected Count= %d, Province Count= %d, Expected Count= %d\n", testGame->supplyCount[estate], game->supplyCount[estate], testGame->supplyCount[duchy], game->supplyCount[duchy], testGame->supplyCount[province], game->supplyCount[province]);
	if (testGame->supplyCount[estate] == game->supplyCount[estate])
	{
		printf("Adventurer: PASSED - supplyCount[estate]\n");
	}
	else
	{
		printf("Adventurer: FAILED - supplyCount[estate]\n");
	}
		
	if (testGame->supplyCount[duchy] == game->supplyCount[duchy])
	{
		printf("Adventurer: PASSED - supplyCount[duchy]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - supplyCount[duchy]\n");
	}
		
	if (testGame->supplyCount[province] == game->supplyCount[province])
	{
		printf("Adventurer: PASSED - supplyCount[province]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - supplyCount[province]\n");
	}
		
	printf("Adventurer Count= %d, Expected Count= %d\n", testGame->supplyCount[adventurer], game->supplyCount[adventurer]);
	if (testGame->supplyCount[adventurer] == game->supplyCount[adventurer])
	{
		printf("Adventurer: PASSED - supplyCount[adventurer]\n");
	}	
	else
	{
		printf("Adventurer: FAILED - supplyCount[adventurer]\n");
	}
		
	printf("***************************************************************\n");
}