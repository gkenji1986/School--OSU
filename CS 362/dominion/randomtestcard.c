/***********************************
* Author: Grant Nakashima
* Due Date: 7/24/16
* Assignment: Assignment 4
* File: randomtestcard.c
************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
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
#define CARD_NUMBER 1

void randomizeGameState(struct gameState *game, int *k);
void randomCardTest(struct gameState *game, struct gameState *testGame, int shuffleCard, int discard);

int main()
{
	int handpos = 0;
	//Setup card options
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int seed;
	struct gameState game;
	struct gameState testGame;
	int k[10] = { adventurer, baron, village, cutpurse, mine, great_hall, sea_hag, feast, smithy, council_room };
	int i, j;
	int discard = 1;
	int shuffleCard = 0;

	printf("Starting randdomtestcard.c for: %s \n", "Great Hall");

	printf("Random Tests\n");

	for (i = 0; i < TEST_NUM; i++)
	{
		seed = rand();

		for (j = 0; j < sizeof(struct gameState); j++)
		{
			((char*)&game)[j] = floor(Random() * 256);
		}
		
		initializeGame(PLAYER_NUMBER, k, seed++, &game);		// initialize a game state and player cards

		randomizeGameState(&game, k);		//set game state to random state

		memcpy(&testGame, &game, sizeof(struct gameState));		// copy the game state to a test case

		//cardEffect(great_hall, choice1, choice2, choice3, &testGame, handpos, &bonus);		//play great hall card

		greathallCard(PLAYER, &testGame, handpos);

		randomCardTest(&game, &testGame, shuffleCard, discard);		//run game state  tests
	}

	printf("Tests completed!\n");

	return 0;
}

void randomizeGameState(struct gameState *game, int *k)
{
	int i;
	int number;

	game->handCount[PLAYER] = floor(Random() * 10);
	game->deckCount[PLAYER] = floor(Random() * 52);
	game->discardCount[PLAYER] = floor(Random() * 25);

	game->handCount[OPPONENT] = floor(Random() * 15);
	game->deckCount[OPPONENT] = floor(Random() * 52);

	for (i = 0; i < game->handCount[PLAYER]; i++)		//randomly select cards for hand pile
	{
		number = floor(Random() * 10);
		game->hand[PLAYER][i] = k[number];
	}

	for (i = 0; i < game->discardCount[PLAYER]; i++)		//randomly select cards for discard pile
	{
		number = floor(Random() * 10);
		game->discard[PLAYER][i] = k[number];
	}

	for (i = 0; i < game->deckCount[PLAYER]; i++)		//randomly select cards for deck 
	{
		number = floor(Random() * 10);
		game->deck[PLAYER][i] = k[number];
	}
}

void randomCardTest(struct gameState *game, struct gameState *testGame, int shuffleCard, int discard)
{
	printf("***************************************************************\n");

	printf("Hand Count = %d, Expected Count= %d\n", testGame->handCount[PLAYER], game->handCount[PLAYER] + CARD_NUMBER - 1);

	if (testGame->handCount[PLAYER] == game->handCount[PLAYER] + CARD_NUMBER - 1)
	{
		printf("Great Hall: PASSED - handCount[PLAYER]\n");
	}

	else
	{
		printf("Great Hall: FAILED - handCount[PLAYER]\n");
	}

	printf("Deck Count = %d, Expected Count= %d\n", testGame->deckCount[PLAYER], game->deckCount[PLAYER] - CARD_NUMBER + shuffleCard);

	if (testGame->deckCount[PLAYER] == game->deckCount[PLAYER] - CARD_NUMBER + shuffleCard)
	{
		printf("Great Hall: PASSED - deckCount[PLAYER]\n");
	}
	else
	{
		printf("Great Hall: FAILED - deckCount[PLAYER]\n");
	}

	printf("Hand Count = %d, Expected Count= %d\n", testGame->handCount[OPPONENT], game->handCount[OPPONENT]);

	if (testGame->handCount[OPPONENT] == game->handCount[OPPONENT])
	{
		printf("Great Hall: PASSED - handCount[OPPONENT]\n");
	}
	else
	{
		printf("Great Hall: FAILED - handCount[OPPONENT]\n");
	}

	printf("Deck Count = %d, Expected Count= %d\n", testGame->deckCount[OPPONENT], game->deckCount[OPPONENT]);

	if (testGame->deckCount[OPPONENT] == game->deckCount[OPPONENT])
	{
		printf("Great Hall: PASSED - deckCount[opponent]\n");
	}
	else
	{
		printf("Great Hall: FAILED - deckCount[opponent]\n");
	}

	printf("Estate Count= %d, Expected Count= %d, Duchy Count= %d, Expected Count= %d, Province Count= %d, Expected Count= %d\n", testGame->supplyCount[estate], game->supplyCount[estate], testGame->supplyCount[duchy], game->supplyCount[duchy], testGame->supplyCount[province], game->supplyCount[province]);

	if (testGame->supplyCount[estate] == game->supplyCount[estate])
	{
		printf("Great Hall: PASSED - supplyCount[estate]\n");
	}
	else
	{
		printf("Great Hall: FAILED - supplyCount[estate]\n");
	}

	if (testGame->supplyCount[duchy] == game->supplyCount[duchy])
	{
		printf("Great Hall: PASSED - supplyCount[duchy]\n");
	}
	else
	{
		printf("Great Hall: FAILED - supplyCount[duchy]\n");
	}

	if (testGame->supplyCount[province] == game->supplyCount[province])
	{
		printf("Great Hall: PASSED - supplyCount[province]\n");
	}
	else
	{
		printf("Great Hall: FAILED - supplyCount[province]\n");
	}

	printf("Adventurer Count= %d, Expected Count= %d\n", testGame->supplyCount[adventurer], game->supplyCount[adventurer]);

	if (testGame->supplyCount[adventurer] == game->supplyCount[adventurer])
	{
		printf("Great Hall: PASSED - supplyCount[adventurer]\n");
	}
	else
	{
		printf("Great Hall: FAILED - supplyCount[adventurer]\n");
	}

	printf("numActions = %d, expected = %d\n", testGame->numActions, game->numActions + ACTION_NUMBER);

	if (testGame->numActions == game->numActions + ACTION_NUMBER)
	{
		printf("Great Hall: PASSED - numActions\n");
	}
	else
	{
		printf("Great Hall: FAILED - numActions\n");
	}

	printf("***************************************************************\n");
}
