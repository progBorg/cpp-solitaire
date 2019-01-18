#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "Solitaire.h"

// ------------ Constructor ------------
// Create game and initialize foundation, tableau and reserve
Solitaire::Solitaire(std::vector<Card*> tableauCards, std::vector<Card*> reserveCards) :
		foundation(),
		tableau(tableauCards),
		reserve(reserveCards)
{

}

/**
 * Generate all cards and return them randomly shuffled
 */
std::vector<Card*> Solitaire::generateCards() {
	// Get all card values and suits
	int values[13] = {Card::ACE, Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN,
			Card::JACK, Card::QUEEN, Card::KING};
	int suits[4] = {Card::HEARTS, Card::SPADES, Card::DIAMONDS, Card::CLUBS};

	// Generate all cards
	std::vector<Card*> gameCards;
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
	auto rng = std::default_random_engine {};
	shuffle(std::begin(gameCards), std::end(gameCards), rng);

	return gameCards;
}

// ------------ Commands ------------
/**
 * Run the game
 */
void Solitaire::run() {
	std::cout << "Welcome to Solitaire!" << std::endl;

	std::vector<std::string> moveOptions {
		"Get new card from Stock",
		"Move card from Waste to Tableau",
		"Move card from Waste to Foundation",
		"Move card from Tableau to Foundation",
		"Move cards within Tableau"
	};

	bool winnerWinnerChickenDinner = false;
	while (!winnerWinnerChickenDinner) {
		printBoard();

		// Get user move
		std::cout << "What would you like to do?" << std::endl;
		int choice = getUserInput(moveOptions);

		// Parse user move
		switch (choice) {
			case 0: // card from stock
				cardFromStock();
				break;
			case 1: // waste to tableau
				wasteToTableau();
				break;
			case 2: // waste to foundation
				wasteToFoundation();
				break;
			case 3: // tableau to foundation
				tableauToFoundation();
				break;
			case 4: // move within tableau
				tableauMove();
				break;
			default:
				std::cout << "A user input error has occured, exiting..." << std::endl;
				return;
				break;
		}

		winnerWinnerChickenDinner = foundation.isGameOver();
	}

	std::cout << "Congratulations, you've won!" << std::endl;

	return;
}

/**
 * Prints the board to screen
 */
void Solitaire::printBoard() {
	Waste wasteStack = this->reserve.getWaste();
	Stock stockStack = this->reserve.getStock();

	// ------------ Stock ------------
	std::cout << "Number of cards available in the stock: "
		<< stockStack.getPile().getStack(0)->getCards().size() << std::endl;

	// ------------ Waste ------------
	std::vector<Card*> uselessCards = generateCards();
	wasteStack.addCard(uselessCards[0]); // add a random card, to test functionality
	std::cout << "\nThe waste:" << std::endl;
	std::vector<Card *> wasteCards = wasteStack.getStack(0)->getCards();
	if (wasteCards.empty()) {
		std::cout << "The waste is empty." << std::endl;
	} else {
		for (int index = 0; index < wasteCards.size(); index++) {
			std::cout << wasteCards[index]->getCard() << std::endl;
		}
	}

	// ------------ Foundation ------------
	std::cout << "\nThe foundation:" << std::endl;

	// save all the cards in a matrix
	auto matrix = new std::vector<Card *>;
	for (int column = 0; column < 4; column++) {
		matrix[column] = this->foundation.getStack(column)->getCards();
	}

	// print every element of the matrix
	for (int index = 0; index < 13; index++) {
		for (int column = 0; column < 4; column++) {
//				std::cout << matrix[index][column]->getCard();

			// preventing nullpointer issues:
			Card * value = matrix[index][column];
			int result;
			(value == nullptr) ? (result = 0) : (result = value->getCard());
			std::cout << result;
		}
		std::cout << std::endl;
	}

	// ------------ Tableau ------------
	std::cout << "\nThe tableau:" << std::endl;
	std::cout << this->tableau.getStack(0)->getCards().size() << std::endl;
	std::cout << this->tableau.getStack(1)->getCards().size() << std::endl;

}

/**
 * Prints options to screen, let's user choose, and returns the index of the chosen option.
 */
int Solitaire::getUserInput(std::vector<std::string> options) {
	std::cout << "Please select one of the options below:" << std::endl;
	// Print options
	for (int i = 0; i < options.size(); i++) {
		std::cout << i+1 << ") " << options[i] << std::endl;
	}

	int choice;
	bool correctInput = false;
	while (!correctInput) {
		std::cin >> choice; // user choice
		if (1 <= choice && choice <= options.size()) {
			correctInput = true; // check if input is in selectable range
		} else {
			std::cout << "That is not a valid choice. Please try again." << std::endl;
		}
	}

	return choice - 1;
}

/**
 * Game move methods
 */
void Solitaire::cardFromStock() {
	switch (this->reserve.getCard()) {
		case 0:
			// Nothing out of the ordinary
			break;
		case -1:
			// Waste and stock are both empty
			std::cout << "Can't get a new card, waste and stock are empty." << std::endl;
			break;
	}
	return;
}
void Solitaire::wasteToTableau() {
	std::vector<std::string> tableauColumnOptions {
		"Column 1",
		"Column 2",
		"Column 3",
		"Column 4",
		"Column 5",
		"Column 6",
		"Column 7"
	};

	// Get user input
	std::cout << "What column to move the card to?" << std::endl;
	int tableauColumn = getUserInput(tableauColumnOptions);

	// Get card from waste
	Card* tempCard = reserve.takeCard();
	if (tempCard == nullptr) {
		std::cout << "Waste is empty." << std::endl;
		return;
	}

	// If move failed
	if (! tableau.addCard(tableauColumn, tempCard)) {
		std::cout << "Move not possible." << std::endl;
	}
}

void Solitaire::wasteToFoundation() {
	// Get card from waste
	Card* tempCard = reserve.takeCard();
	if (tempCard == nullptr) {
		std::cout << "Waste is empty." << std::endl;
		return;
	}

	// If move failed
	if (! foundation.addCard(tempCard)) {
		std::cout << "Move not possible." << std::endl;
	}

	return;
}

void Solitaire::tableauToFoundation() {
	std::vector<std::string> tableauColumnOptions {
		"Column 1",
		"Column 2",
		"Column 3",
		"Column 4",
		"Column 5",
		"Column 6",
		"Column 7"
	};

	// Get user input
	std::cout << "What column top-card to move to the foundations?" << std::endl;
	int tableauColumn = getUserInput(tableauColumnOptions);

	// Back up tableau stack
	std::vector<Card*> backupStack = this->tableau.getStack(tableauColumn)->getCards();

	// Get card
	Card* tempCard = this->tableau.getStack(tableauColumn)->removeCard();
	if (tempCard == nullptr) {
		std::cout << "Waste is empty." << std::endl;
		return;
	}

	// Move tempCard onto foundation
	// If move failed
	if (! foundation.addCard(tempCard)) {
		std::cout << "Move not possible." << std::endl;
		// Put card back
		this->tableau.addSet(tableauColumn, backupStack);
	}

}

void Solitaire::tableauMove() {
	std::vector<std::string> tableauColumnOptions {
		"Column 1",
		"Column 2",
		"Column 3",
		"Column 4",
		"Column 5",
		"Column 6",
		"Column 7"
	};

	// Get user input
	std::cout << "What column to move the card(s) to?" << std::endl;
	int toColumn = getUserInput(tableauColumnOptions);

}
