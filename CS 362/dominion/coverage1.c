Author: Grant Nakashima
Course: CS 362
Assignment: 3
File: coverage1.c
Summary:
The unit tests ranged from 17% to 26% lines covered. The coverage for the branches were about the same varying by a couple of percentages. These numbers are based
on the coverage of all of dominion.c . In order to get a better range of how much the test covers, we will have to run tests on the respective portion of code we 
are testing it against rather than all of the code in the program. 

################################

unittest1.c isGameOver() :
	Statement: The unit test checks if the call to isGameOver properly returns the correct result of a 0 or 1.
	Branch : The tests only checks if the game is over or not. No other branches were not covered in the test. 
	Boundary : There are other extreme conditions that need to get tested. We need to check what would happen if province was set to negative. 
	Implications : This test does a good job checking normal conditions the game may encounter but it does not have any extreme cases. 

	File 'dominion.c'
	Lines executed : 17.55% of 564
	Branches executed : 17.75% of 417
	Taken at least once : 14.63% of 417
	Calls executed : 7.29% of 96
	Creating 'dominion.c.gcov'

################################

unittest2.c shuffle() :
	Statement : The unit test checks if the call to shuffle properly returns the correct result of a 0 or -1.
	Branch : The test only checks if the deck is shuffled or not. Other branches were not covered in the test. 
	Boundary : There are other extreme conditions that need to get tested. We need to check what would happen if deckCount was set to negative.
	Implications : This test does a good job checking normal conditions the game may encounter but it does not have any extreme cases.

	File 'dominion.c'
	Lines executed : 17.91% of 564
	Branches executed : 17.75% of 417
	Taken at least once : 15.11% of 417
	Calls executed : 7.29% of 96
	Creating 'dominion.c.gcov'

################################

unittest3.c getCost() :
	Statement : The unit test checks if the call to getCost properly returns the correct cost of the card.
	Branch : There are some branches that were left out.I still need to test other cards as well as incorrect cost checks.
	Boundary : There are other extreme conditions that need to get tested. Incorrect cost checks need to get checked.
	Implications : This test coverage does well for coverage.I uses brute force to cover different instances where getCost will get used.

	File 'dominion.c'
	Lines executed : 22.87% of 564
	Branches executed : 24.46% of 417
	Taken at least once : 21.34% of 417
	Calls executed : 7.29% of 96
	Creating 'dominion.c.gcov'

################################

unittest4.c buyCard() :
	Statement : The unit test checks if the call to isGameOver buyCard executes when it is supposed to or not.
	Branch : Four branches were tested in this test: coins, number of buys, supply count and discard count. 
	Boundary : Some other extreme conditions need to get tested like if the coins or number of buys are set to -1 or if the supply count is set to -1.
	Implications : This tests does a decent job checking different situations the player may encounter during the game. 

	File 'dominion.c'
	Lines executed : 26.95% of 564
	Branches executed : 27.34% of 417
	Taken at least once : 23.50% of 417
	Calls executed : 12.50% of 96
	Creating 'dominion.c.gcov'

################################
Summary:
The range of the cards were different from the unit tests from above. The range for the cards were from 34% to 38%. The branch coverage varied from 35%
to 39%. 
################################

cardtest1.c smithy card:
	Statement: The test checks if smithy card was properly played or not. Effect: +3 cards
	Branch : There are no branching possibilities for this card.
	Boundary : No boundary tests were performed but some tests in the future could included added the card to a hand that has an large amount of cards in hand or no card.
	Implications : Tested one branch. Other tests will need to get implemented to trigger the change in the code. 


	Lines executed : 34.04% of 564
	Branches executed : 37.17% of 417
	Taken at least once : 26.38% of 417
	Calls executed : 20.83% of 96
	Creating 'dominion.c.gcov'


################################

cardtest2.c Great hall card:
	Statement: The test checks if the great hall card works properly or not. Effect: +1 card +1 action
	Branch: The function does exactly what the effect is supposed to do. It will perform the change and move on. Not all branches were tested. Only one branch was tested. 
	Boundary: No boundary tests were performed but some tests in the future could included added the card to a hand that has an large amount of cards in hand or no card.
	Implications: Future tests will need to get impletmented to see if there are other cases where the code will break if the number of actions isn't incremented.

	File 'dominion.c'
	Lines executed : 35.46% of 564
	Branches executed : 37.17% of 417
	Taken at least once : 26.86% of 417
	Calls executed : 23.96% of 96
	Creating 'dominion.c.gcov'

################################

cardtest3.c Adventure card:
	Statement: The unit test checks if the call to isGameOver properly returns the correct result of a 0 or 1. Effect: +2 treasure from pile
	Branch: There are no branching possibilities for this card.
	Boundary: No boundary tests were performed but some tests in the future could included added the card to a hand that has an large amount of cards in hand or no card. One test could be if 
			  there are no treasure cards left what would happen.
	Implications: The test will need to get adjusted to check extreme cases like the case where there are no more treasure cards. 

	File 'dominion.c'
	Lines executed : 37.77% of 564
	Branches executed : 39.09% of 417
	Taken at least once : 28.78% of 417
	Calls executed : 27.08% of 96
	Creating 'dominion.c.gcov'

################################

cardtest4.c Village Card:
	Statement: The village card adds a card and two actions. Since the card is set to do a specfic action, there are no other branches. Effect: +1 card, +2 actions
	Branch: The effect of the card is the branch for the card. 
	Boundary: No boundary tests were performed. It does not appear to have any boundary issues. 
	Implications: This test did not have any bugs detected because there were not changes applied to the village card. The village card was used instead of embargo because
				  I wanted to see if I could find any bugs in the original code and not the altered code. 

	File 'dominion.c'
	Lines executed : 38.48% of 564
	Branches executed : 39.09% of 417
	Taken at least once : 29.02% of 417
	Calls executed : 29.17% of 96
	Creating 'dominion.c.gcov'

