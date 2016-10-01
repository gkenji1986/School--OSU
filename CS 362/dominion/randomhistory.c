/***********************************
* Author: Grant Nakashima
* Due Date: 7/24/16
* Assignment: Assignment 4
* File: randomhistory.c
************************************/


Assignment 4 required us to implement a random tester for adventure card and any other card of our choice.I picked Great Hall.
I used the randomized method that was seen in the lectures for class.For the cards, I tested the different unit tests for the card.
For example, in my tests I looked at the hand count, deck count and played card count.The counts for each of these areas were randomized.
Other areas were randomized as well if it was possible.Once the game state was set and randomized, a copy of the game was made before playing
the Great Hall card.Once a copy of the game is made, it will get put into the cardEffect function to use the Great Hall card.Once the Great Hall
card is used, we will test the copied game state and compare it to the original game state to see the difference between the two states and see if
the card did perform as it was supposed to.

*****************************************
randomtestcard.c after 10, 000 iterations
*****************************************

File 'dominion.c'
Lines executed : 20.74% of 564
Branches executed : 22.78% of 417
Taken at least once : 14.15% of 417
Calls executed : 11.46% of 96
Creating 'dominion.c.gcov'

The test failed in two particular areas; the handCount and the numActions. The numActions fails like it is supposed to do but the the handCount should
not be failing. I do not know what could be the cause of this at the moment but the count for some reason is not incrementing. Overall the coverage for
the test though was decent. It covered  a little over 20% but there are many more areas that were not tested.

--------------------------------------------------------------
Hand Count = 1, Expected Count = 2
Great Hall : FAILED - handCount[PLAYER]
Deck Count = 9, Expected Count = 9
Great Hall : PASSED - deckCount[PLAYER]
Hand Count = 7, Expected Count = 7
Great Hall : PASSED - handCount[OPPONENT]
Deck Count = 15, Expected Count = 15
Great Hall : PASSED - deckCount[opponent]
Estate Count = 8, Expected Count = 8, Duchy Count = 8, Expected Count = 8, Province Count = 8, Expected Count = 8
Great Hall : PASSED - supplyCount[estate]
Great Hall : PASSED - supplyCount[duchy]
Great Hall : PASSED - supplyCount[province]
Adventurer Count = 10, Expected Count = 10
Great Hall : PASSED - supplyCount[adventurer]
numActions = 1, expected = 2
Great Hall : FAILED - numActions
--------------------------------------------------------------


************************************************
randomtestadventurer.c after 10, 000 iterations
************************************************
File 'dominion.c'
Lines executed : 26.60% of 564
Branches executed : 26.62% of 417
Taken at least once : 18.94% of 417
Calls executed : 15.63% of 96
Creating 'dominion.c.gcov'

--------------------------------------------------------
Hand Count = 9, Expected Count= 10
Adventurer: FAILED - handCount[PLAYER]
Deck Count = 0, Expected Count= 20
Adventurer: FAILED - deckCount[PLAYER]
Discard Count = 33, Expected Count= 13
Adventurer: FAILED - discardCount[PLAYER]
Hand Count = 5, Expected Count= 5
Adventurer: PASSED - handCount[OPPONENT]
Deck Count = 20, Expected Count= 20
Adventurer: PASSED - deckCount[OPPONENT]
Estate Count= 8, Expected Count= 8, Duchy Count= 8, Expected Count= 8, Province Count= 8, Expected Count= 8
Adventurer: PASSED - supplyCount[estate]
Adventurer: PASSED - supplyCount[duchy]
Adventurer: PASSED - supplyCount[province]
Adventurer Count= 10, Expected Count= 10
Adventurer: PASSED - supplyCount[adventurer]
--------------------------------------------------------
--------------------------------------------------------
Hand Count = 4, Expected Count= 4
Adventurer: PASSED - handCount[PLAYER]
Deck Count = 25, Expected Count= 38
Adventurer: FAILED - deckCount[PLAYER]
Discard Count = 35, Expected Count= 23
Adventurer: FAILED - discardCount[PLAYER]
Hand Count = 2, Expected Count= 2
Adventurer: PASSED - handCount[OPPONENT]
Deck Count = 40, Expected Count= 40
Adventurer: PASSED - deckCount[OPPONENT]
Estate Count= 8, Expected Count= 8, Duchy Count= 8, Expected Count= 8, Province Count= 8, Expected Count= 8
Adventurer: PASSED - supplyCount[estate]
Adventurer: PASSED - supplyCount[duchy]
Adventurer: PASSED - supplyCount[province]
Adventurer Count= 10, Expected Count= 10
Adventurer: PASSED - supplyCount[adventurer]
--------------------------------------------------------

The random test for adventurer had decent coverage as well. It covered more than randomtestcard.c at a little over
26%. The main areas the tests would fail were the handCount, discardCount and deckCount(s). I did not implement a counter 
for the number of time it would fail but I appears one, two or all three would fail in any combination more often than
pass. The reasoning for this is probably due to using a similar process to test the card as I did for Great Hall. 
