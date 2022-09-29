
#ifndef _RANGE_
#define _RANGE_

#include "Card.h"
#include <vector>

/**
	This function returns the integer value of the card.

	@params card the card to retrieve the value of. For instance, "8[Hearts]" will have a value of 8.
	@return the numerical value of the card.
*/
int cardValue(Card card);

/**
	This function returns a random card from the deck.

	@params deck the reference to the deck of cards that a random card will be chosen from. It is reference to change the number of cards in a deck.
	@return the random card chosen from the deck.
*/
Card dealCard(std::vector<Card>& deck);

/**
	This function displays the hand value and cards in hand.

	@params player_hand the cards that the player has in hand.
	@params totalValue the total value of the cards in hand
*/
void showHand(std::vector<Card> player_hand, int totalValue);

/**
	This function returns true if the user's hand value exceeds the max possible hand value

	@params max_value the maximum hand value allowed
	@params user_hand_value the value that the user has
	@return the boolean value of whether the user's hand exceeded the max allotted value
*/
bool exceeds(const int max_value, int user_hand_value);

/**
	This function returns true if the user's hand value is in between the lower bound value and the max value.
	
	@params lower_bound the target lower bound value
	@params max_value the maximum hand value allowed
	@return the boolean value of whether the user's hand exceeded the max allotted value
*/
bool inRange(int lower_bound, const int max_value, int hand_value);

#endif