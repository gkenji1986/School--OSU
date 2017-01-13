adventure card: In this portion of the code, the user will enter a case adventurer. They will enter a while loop until you 
	have drawn two treasure. In the while loop, a card from their discard pile will get shuffled into their deck if the players deck 
	is empty. Next a card is drawn and checks if the drawn card is a money card. If it is a money card, the treasure
	card drawn count will increment. If the drawn card is not a money card, the card will be stored in a tempory
	hand variable and the player's hand count is decremented and a temporary count variable is incremented.
	If the player gets two treasures, it will exit the while loop and enter another while loop to clean up and remove 
	cards that were drawn and need to be discarded. 

smithy card: This case will have the player draw three cards and then discard one card. 

discardCard: The function will check if the card should be played or if the card should be discarded. If the last card
	in the player's hand is played it will reduce teh number of card in the player's hand. If there is only one card in 
	the players hand then it will reduce the number of cards in their hand. If there are no cards then it will replace
	the discarded card with the last card in hand, set the last card to -1 and then reduce the number of cards in hand. 

drawCard: The function will check if the deck is empty. Next the discard pile will get shuffled back into the deck and
	the deck will get shuffled. A card will get drawn and keep count of the players hand count. The counter for the deck
	will get recorded, lowering the deck count and increasing the hand count. 