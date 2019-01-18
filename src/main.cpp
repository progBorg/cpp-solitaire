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
	// Generate cards
	vector<Card*> gameCards;
	gameCards = Solitaire::generateCards();
	cout << "Number of generated cards: " << gameCards.size() << endl;

	// Divide cards
	vector<Card*> tableauCards(gameCards.begin(), gameCards.begin() + 28);
	vector<Card*> reserveCards(gameCards.begin() + 28, gameCards.end());

	// Initiate and run game
	Solitaire solitaireGame(tableauCards, reserveCards);
	solitaireGame.run();

	return 0;
}
