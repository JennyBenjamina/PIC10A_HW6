//Jenny Lee
//October 31, 2021

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Range.h"
#include "Card.h"

int main() {

	std::cout << "Cards 2-10 are worth their numeric value." << '\n';
	std::cout << "J, Q, K have a value of 11" << '\n';
	std::cout << "An A has a value of 12 as a spade and 1 for other suits." << '\n';
	std::cout << "Over 3 rounds, you will try to reach or exceed a target value, without going over 22!" << '\n';
	std::cout << "If you go over, you get -1 points; if you are within range, you get +1 points; otherwise you get 0 points." << '\n';
	std::cout << '\n'; //add another new line for readability

	std::vector<std::string> suits {"Spades", "Hearts", "Diamonds", "Clubs"};//define the vector that holds strings for suits 

	std::vector<std::string> faces {"A", "J", "Q", "K",
		"2", "3", "4", "5", "6", "7", "8", "9", "10"}; //define the vector that holds strings for faces
	

	int counter = 0; //counting the round number
	const int max_rounds = 3; //max number of rounds available
	const int max_value = 22; //max value before user will lose a point
	size_t lower_bound; //define a container for the lower bound that is randomly generated
	int total_points = 0; //define and declare total points for the user
	char deal_more_answer = 'y'; //define and declare a character that stops a loop

	while (counter < max_rounds) {//stop loop at max rounds
		std::string user_hand = ""; //define and declare the user's hand to display
		int total_value_user = 0; //define and declare the variable to hold the user's total hand value

		const int max = 22;//max number for lower bound
		const int min = 17;//min number for lower bound
		lower_bound = rand() % (max - min + 1) + min;//generate the lower bound number randomly

		std::vector<Card> cards{};//creating the deck using nested for loops
		for (size_t j = 0; j < suits.size(); ++j) { //first for loop goes through the various suits in a card
			for (size_t i = 0; i < faces.size(); ++i) { //second for loop goes through the various faces in a card
				Card temp_card(suits[j], faces[i]); //a temporary card to store the values 
				cards.push_back(temp_card); //pushing card in
			}
		}

		while (deal_more_answer == 'y') {
			bool user_status = false;

			std::cout << "Target lower bound: " << lower_bound << '\n';

			Card dealt_card = dealCard(cards); //user gets a card dealt from the deck
			std::cout << "Hand value is: ";
			total_value_user += cardValue(dealt_card); //sum the values of cards
			std::cout << total_value_user << '\n'; //display the total value of user's cards

			std::cout << "Hand is: ";
			user_hand += (' ' + dealt_card.card_as_string()); //concatenate the user's hand
			std::cout << user_hand << '\n';

			user_status = inRange(lower_bound, max_value, total_value_user);
			if (user_status) {
				const int point_value = 1; //define and declare point value
				std::cout << "You got " << point_value << " points." << '\n';
				total_points += point_value; //sum the total points for user
				break; //exit loop
			}

			user_status = exceeds(max_value, total_value_user); //check to see if the user's hand value exceeds the max value
			if (user_status) {
				const int point_value = -1; //define and declare point value
				std::cout << "You got " << point_value << " points." << '\n';
				total_points += point_value; //sum the total points for user
				break; //exit loop
			}

			std::cout << "Deal more? y/n ";
			std::cin >> deal_more_answer; //user can input y to keep going and n to stop this round
			
			if (deal_more_answer == 'n') {
				bool point = inRange(lower_bound, max_value, total_value_user); //check to see if user's hand is in bound
				if (!point) {
					const int point_value = 0; //the point received if user's hand is in bound
					std::cout << "You got " << point_value << " point." << '\n';
					total_points += point_value; //sum the total value for user
				}
				
			}
		}

		++counter;//increment the counter to control the while loop for rounds
		if (counter < max_rounds) {//check if counter has reached the max amount of rounds
			deal_more_answer = 'y'; //change deal_more_answer to 'y' to start another round
			std::cout << '\n'; //for readability add new line
		}
	}

	std::cout << '\n'; //add new line for readability
	std::cout << "Your total score is " << total_points << " points. " << '\n';
	
	return 0;
}