#include "Card.h"
#include "Range.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

/* Definitions of functions */
//returns the value of the card that is inputted
int cardValue(Card card) {
	std::string card_string = card.card_as_string(); //change the card that is passed in to a string
	const int ten_value = 10; //define and declare the value for 10
	const int j_q_k_value = 11;//define and declare the value for J, Q, K
	const int ace_spades = 12; //define and declare the value for ace of spades
	const int ace_value = 1;//define and declare the value for an ace

	if (card_string[0] == '1') { //check if card has a 1 in front to denote 10
		return ten_value;
	}
	else if ((card_string[0]) <= '9' && (card_string[0] >= '2')) { //check to see if the card's first value is between 2 and 9
		int temp;
		temp = card_string[0] - '0';
		return temp;
	}
	else if ((card_string[0] == 'J') || (card_string[0] == 'Q') || (card_string[0] == 'K')) {//check to see if card is a J, Q, or K
		return j_q_k_value;
	}
	else if (card_string[0] == 'A') {//check to see if card is an ace
		if (card_string[1] == 'S') {//check to see if card is an ace of spades
			return ace_spades;
		}
		else {
			return ace_value;
		}
	}

	return 0;

}

//this function returns a random card from the inputted deck
Card dealCard(std::vector<Card>& deck) {
	int temp = 0;//define and declare temp variable to be used to get the random card from deck
	std::srand(std::time(nullptr)); //seeding the srand for better randomization
	size_t num_of_cards = deck.size(); //get the size of deck
	temp = rand() % num_of_cards; //random number from the size of the deck
	
	Card player_card(deck[temp]); //this is the card that will be returned to player
	deck.erase(deck.begin() + temp); //this removes the card from the deck

	return player_card; //return the random card
}

//this function displays the player's hand and the total value of the cards in hand.
void showHand(std::vector<Card> player_hand, int total_value) {

	for (size_t i = 0; i < player_hand.size(); ++i) { //loop through the player's hands to display all their cards
		std::cout << player_hand[i].card_as_string() << " "; //loop through to display the player's cards one by one
	}

	std::cout << total_value; //print the total value of the player's cards
}

//this function returns true if the user's hand value exceeds the maximum value
bool exceeds(const int max_value, int user_hand_value) {
	if (user_hand_value > max_value) {//checking to see if user's hand value exceeds the max value
		return true;
	}
	return false;
}

//this function returns true if the user's hand value is in between the lower bound and max value
bool inRange(int lower_bound, const int max_value, int hand_value) {
	if ((hand_value >= lower_bound) && (hand_value <= max_value)) {//checking to see if hand value is in between the lower bound and max value
		return true;
	}
	return false;
}
