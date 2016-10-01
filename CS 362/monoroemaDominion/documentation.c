/***********************************
 * Name: Matt Monroe
 * Assignment 2 
 * CS362
 * *********************************/

Adventurer - This card is an action. When you play it you will keep drawing from your deck until you have drawn
two treasure cards. If you run out of cards in your deck before you get your second treasure card the discard
pile will be shuffled and placed in as your deck. The two treasure cards will be placed in your deck, the rest
of the cards will be discarded. 
	Loop -> check if deck is empty, if it is, shuffle dicard pile, then drawCard(), else drawCard() 

Smithy - This card is an action. It is called through cardEffect(). After it is call it will drawCard() 3 times
from your deck. If your deck is empty it will shuffle the discard pile and then draw until 3 cards are in 
your deck. If the deck is not empty, it will give you three cards. When it is done, the smithy card will be
discarded using discardCard()
	
updateCoins() - This gets the number of coins in a player's hand, 1 for each copper, 2 for each silver,
and 3 for each gold. It will loop over the player's hand to get this info.

discardCard() - This method removes a card from the players hand. Depending on the card it can do two 
different things. 1. It will discard the card to player's discard pile, this will be usable later.
2. It will remove the card from the player's hand and trash it. This card is now unavailable.
