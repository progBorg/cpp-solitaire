#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Solitaire.h"
using namespace std;

// ------------ Constructor ------------
// Create game and initialize foundation, tableau and reserve
Solitaire::Solitaire(vector<Card*> tableauCards, vector<Card*> reserveCards) :
		foundation(),
		tableau(tableauCards),
		reserve(reserveCards)
{

}

/**
 * Generate all cards and return them randomly shuffled
 */
vector<Card*> Solitaire::generateCards() {
	// Get all card values and suits
	int values[13] = {Card::ACE, Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN,
			Card::JACK, Card::QUEEN, Card::KING};
	int suits[4] = {Card::HEARTS, Card::SPADES, Card::DIAMONDS, Card::CLUBS};

	// Generate all cards
	vector<Card*> gameCards;
	gameCards.reserve(52); // Reserve space in advance
	for (int suit = 0; suit < 4; suit++) {
		for (int value = 0; value < 13; value++) {
			// Generate current card in place and add it to the vector
			Card tempCard(suits[suit], values[value]);
			Card* tempCardPointer = &tempCard;
			gameCards.push_back(tempCardPointer);
		}
	}

	// shuffle cards
	auto rng = default_random_engine {};
	shuffle(begin(gameCards), end(gameCards), rng);

	return gameCards;
}

// ------------ Commands ------------
/**
 * Run the game
 */
void Solitaire::run() {
	cout << "Welcome to Solitaire!" << endl;

	vector<string> moveOptions {
		"Get new card from Stock",
		"Move card from Waste to Tableau",
		"Move card from Waste to Foundation",
		"Move card from Tableau to Foundation",
		"Move card within Tableau"
	};

	bool winnerWinnerChickenDinner = false;
	while (!winnerWinnerChickenDinner) {
		printBoard();

		int choice = getUserInput(moveOptions);
		cout << "Your choice: " << choice << endl;
	}

	return;
}

/**
 * Prints the board to screen
 */
void Solitaire::printBoard() {
	Waste wasteStack = this->reserve.getWaste();
	Stock stockStack = this->reserve.getStock();

	// Print top row, the reserve and foundations
	//fprintf();

	// Print tableau

}

/**
 * Prints options to screen, let's user choose, and returns the index of the chosen option.
 */
int Solitaire::getUserInput(vector<string> options) {
	// Print options
	for (int i = 0; i < options.size(); i++) {
		cout << i+1 << ") " << options[i] << endl;
	}

	return 0;
}
