Eugene Turgil
July 11, 2016
Assignment 3

Bugs: cardtest1 (Smithy)
	--Upon drawing the smithy card, although the instantaneous
	hand count should be 8, 5+3, the smithy card gets discarded afterward which leads to
	a offset of 1 error. The error is confirmed by counting the deck as well and is evident,
	that too many cards are being drawn.

Bugs: cardtest2 (Adventurer)
	--Similar to the smithy card, there is another offset by 1 error due to not accounting 
	for the discarded card.

Bugs: cardtest3 (Village)
	--None noted

Bugs: cardtest4 (Council Room)
	--It is noted that the the hand counts are incorrect for the players. Upon playing
	the card the other players in the game should have increased hand count,
	however that is not the case.
	
Bugs: unittest1 (drawCard)
	--None noted

Bugs: unittest2 (discardCard)
	--It is possible to discard more cards than there are cards available in the hand.

Bugs: unittest3 (updateCoins)
	--None noted

Bugs: unittest4 (shuffle)
	--1: There seems to be only 2 types of cards in play based on my shuffling
	--2: Even though the seed is not all that random, because there are only 2 types of cards
	it is hard to see the randomness in the shuffle algorithm.