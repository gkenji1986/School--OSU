******************
*nakashigDominion*
******************
Bug found by teammate monoroema

Bug 1 in Smithy Implementation

In this function instead of discarding the played smithy
card to his discard pile he is traching it, you can see
below the "playedCardCount" did not increment when
expected.

*    testing Smithy      *
Testing that testPlayer[0] handCount has increased by 2....^M
handCount = 3, Expected = 3 ^ M
Testing that testPlayer[0] playedCardCount has increased by 1....^M
playedCardCount = 0, Expected = 1 ^ M
Testing that testPlayer[1] handCount has increased by 2....^M
handCount = 3, Expected = 3 ^ M


*****
*fix*
*****

change the flag number in the function from 1 to 0

discardCard(handPos, currentPlayer, state, 1);		

to

discardCard(handPos, currentPlayer, state, 0);		//fixed bug

Bug 2 in Adventurer Card

In this function it appears the cards are not being discarded correctly
We would expect that some cards would be discarded.I would say that
the temporary hand isn't being discarded correctly. 
******************************
*  Testing Adventurer  *
Testing that testPlayer[0] handCount has increased by 2...^M
handCount = 3, Expected = 3 ^ M
Testing that testPlayer[0] hand contains two treasure cards..^M
Number of treasure cards = 2, Expected = 2 ^ M
Testing that testPlayer[0]'s deckCount has decreased..^M
Post deckCount = 3, Previous deckCount = 5 ^ M
Testing that testPlayer[1] hand contains two treasure cards..^M
Number of treasure cards = 2, Expected = 2 ^ M
Testing that testPlayer[1]'s deckCount has decreased..^M
Post deckCount = 3, Previous deckCount = 5 ^ M
Testing that testPlayer[1]'s discard pile has increased..^M
Post discardCount = 0, Previous discardCount = 0 ^

*****
*fix*
*****

change the > in the while loop to >=

while (z - 1 > 0) {
	state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
	z = z - 1;
}

to 

while (z - 1 >= 0) {
	state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
	z = z - 1;
}


Bug Report Teammate #2
Bug Id : #3
== == == == == == == == == == == == == == ==

Title: Smithy Card does not discard correctly.
	Class : "Serious Bug"
	Date : 7 / 29 / 2016
	Reported By : Eugene Turgil
	Email : turgile@oregonstate.edu

	Is it reproducible : Yes

	Description
	== == == == == =
	The smithy card effect is to draw 3 cards and subsequently discard
	the smithy card into the played pile.

	Steps to Produce / Reproduce
	--------------------------
	Playing the smithy card.

	Expected Results
	----------------
	The expected result is that there would only be 1 card in the played pile,
	since only the smithy card is played.

	Actual Results
	--------------
	The actual result yields 0 cards in the played pile which narrows down where the
	bug might exist.

	START SMITHY CARD TEST
	numPlayers = 2
	handCount = 5, requiredHandcount = 5, player = 0, correctHandcount = assertion passed
	playCount = 0, requiredPlayCount = 0, player = 0, correctHandcount = assertion passed
	deckCount = 5, requiredDeckCount = 5, player = 0, correctHandcount = assertion passed
	handCount = 7, requiredHandcount = 7, player = 0, correctHandcount = assertion passed
	playCount = 0, requiredPlayCount = 1, player = 0, correctHandcount = assertion failed
	deckCount = 2, requiredDeckCount = 2, player = 0, correctHandcount = assertion passed
	handCount = 5, requiredHandcount = 5, player = 1, correctHandcount = assertion passed
	playCount = 0, requiredPlayCount = 0, player = 1, correctHandcount = assertion passed
	deckCount = 5, requiredDeckCount = 5, player = 1, correctHandcount = assertion passed
	handCount = 7, requiredHandcount = 7, player = 1, correctHandcount = assertion passed
	playCount = 0, requiredPlayCount = 1, player = 1, correctHandcount = assertion failed
	deckCount = 2, requiredDeckCount = 2, player = 1, correctHandcount = assertion passed
	END SMITHY CARD TEST

*****
*fix*
*****

change the flag number in the function from 1 to 0

discardCard(handPos, currentPlayer, state, 1);		

to

discardCard(handPos, currentPlayer, state, 0);		//fixed bug
	
	Bug Report Teammate #2
	Bug Id : #3
	== == == == == == == == == == == == == == ==

	Title: Great Hall Card does not yield correct actions.
	Class : "Serious Bug"
	Date : 7 / 29 / 2016
	Reported By : Eugene Turgil
	Email : turgile@oregonstate.edu

	Is it reproducible : Yes

	Description
	== == == == == =
	The great hall card effect is to draw an extra card,
	and give you an extra action.

	Steps to Produce / Reproduce
	--------------------------
	Playing the card causes the error.

	Expected Results
	----------------
	The expected result is that there would be 2 actions after the effect.

	Actual Results
	--------------
	The actual result yields 1 action after the card is played.

	START GREAT HALL TEST
	numPlayers = 2
	handCount = 5, requiredHandcount = 5, player = 0, correctHandcount = assertion passed
	actionCount = 1, requiredActionCount = 1, player = 0, correctActionCount = assertion passed
	handCount = 5, requiredHandcount = 5, player = 0, correctHandcount = assertion passed
	actionCount = 1, requiredActionCount = 2, player = 0, correctActionCount = assertion failed
	handCount = 5, requiredHandcount = 5, player = 1, correctHandcount = assertion passed
	actionCount = 1, requiredActionCount = 1, player = 1, correctActionCount = assertion passed
	handCount = 5, requiredHandcount = 5, player = 1, correctHandcount = assertion passed
	actionCount = 1, requiredActionCount = 2, player = 1, correctActionCount = assertion failed
	END GREAT HALL TEST

*****
*fix*
*****

//+1 Card
	drawCard(currentPlayer, state);

	state->numActions;		

							//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;

	to

//+1 Card
	drawCard(currentPlayer, state);

	state->numActions++;		//added ++ operator

							//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}