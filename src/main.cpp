#include <iostream>
#include "Solitaire.h"

int old_main() {
//    // testCard:
//    Card fred(Card::HEARTS, Card::KING);
//    std::cout << "Hi, here is an overview of your cards:" << std::endl;
//    std::cout << "Suit: " << fred.getSuit() << std::endl;
//    std::cout << "Type: " << fred.getType() << std::endl;
//    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;
//
//    fred.setVisibility(true);
//    std::cout << "\nAfter setting the visibility to true:" << std::endl;
//    std::cout << "Suit: " << fred.getSuit() << std::endl;
//    std::cout << "Type: " << fred.getType() << std::endl;
//    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;

//    // testReserve:
//    std::cout << std::endl;
//    Reserve reserve = Reserve();
//    for (int i = 0; i < 8; i++) {
//        std::cout << "getCard(): " << reserve.getCard() << std::endl;
//        std::cout << "takeCard().getCard(): " << (*reserve.takeCard()).getCard() << std::endl;
//        std::cout << "takeCard().getSuit(): " << (*reserve.takeCard()).getSuit() << std::endl;
//    }

	return 0;
}

int main() {
	// Dialog options
	std::vector<std::string> gameplayOptions {
		"Yes",
		"No"
	};

	// Repeat until the user doesn't want to replay again
	bool replayGame = true;
	while (replayGame) {
		// Generate cards
		std::vector<Card*> gameCards;
		gameCards = Solitaire::generateCards();
		//std::cout << "Number of generated cards: " << gameCards.size() << std::endl;

		// Divide cards
		std::vector<Card*> tableauCards(gameCards.begin(), gameCards.begin() + 28);
		std::vector<Card*> reserveCards(gameCards.begin() + 28, gameCards.end());

		// Initiate and run game
		Solitaire solitaireGame(tableauCards, reserveCards);
		solitaireGame.run();

		//TODO save highscore

		// Ask user for another game
		// Get user input
		std::cout << "Would you like to play a new round?" << std::endl;
		switch (solitaireGame.getUserInput(gameplayOptions)) {
			case 0:
				replayGame = true;
				break;
			case 1:
				replayGame = false;
				break;
		}
	}

	return 0;
}
