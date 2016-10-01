//smithyCard(): Change the trashFlag from 0 to 1 in the discardCard() call. 

//adventurerCard(): In the last while loop's condition, change z-1>=0 to z-1>0. although tests in assignment 3 dont catch the bug, the way to find the bug is to 
//					discard all cards and see if the first card is discarded. One card should be remaining. 

//greathallCard(): Removed the ++ increment. 

//embargoCard(): Move increment operator inside the brackets rather to change the indices rather than the value at the index.

//cutpurseCard(): No bugs introduced. 


int adventurerCard(int currentPlayer, struct gameState* state)
{
	int drawntreasure = 0;
	int z = 0;
	int cardDrawn;
	int temphand[MAX_HAND];

	while (drawntreasure<2)
	{
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}

	while (z > 0)	//changed from >= to >
	{
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z]; // discard all cards in play that have been drawn
		z = z - 1;
	}

	return 0;
}

int smithyCard(int currentPlayer, struct gameState* state, int handPos)
{
	//+3 Cards
	for (int i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 1);		//changed flag from 0 to 1
	return 0;
}

int greathallCard(int currentPlayer, struct gameState* state, int handPos)
{
	//+1 Card
	drawCard(currentPlayer, state);

	state->numActions;		//removed ++ operator

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int embargoCard(int currentPlayer, struct gameState* state, int handPos)
{
	//+2 Coins
	state->coins = state->coins + 2;

	//see if selected pile is in play
	if (state->supplyCount[choice1] == -1)
	{
		return -1;
	}

	//add embargo token to selected supply pile
	state->embargoTokens[choice1++];		//moved ++ operator inside bracket

	//trash card
	discardCard(handPos, currentPlayer, state, 1);
}

int cutpurseCard(int currentPlayer, struct gameState* state, int handPos)
{

	updateCoins(currentPlayer, state, 2);
	for (i = 0; i < state->numPlayers; i++)
	{
		if (i != currentPlayer)
		{
			for (j = 0; j < state->handCount[i]; j++)
			{
				if (state->hand[i][j] == copper)
				{
					discardCard(j, i, state, 0);
					break;
				}
				if (j == state->handCount[i])
				{
					for (k = 0; k < state->handCount[i]; k++)
					{
						if (DEBUG)
							printf("Player %d reveals card number %d\n", i, state->hand[i][k]);
					}
					break;
				}
			}

		}

	}

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);

}
//end of dominion.c

