#include <iostream>

#include "klondike.h"

int main() {
    // testCard:
    Card fred(Card::HEARTS, Card::KING);
    std::cout << "Hi, here is an overview of your cards:" << std::endl;
    std::cout << "Suit: " << fred.getSuit() << std::endl;
    std::cout << "Type: " << fred.getType() << std::endl;
    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;

    fred.setVisibility(true);
    std::cout << "\nAfter setting the visibility to true:" << std::endl;
    std::cout << "Suit: " << fred.getSuit() << std::endl;
    std::cout << "Type: " << fred.getType() << std::endl;
    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;

    // testReserve:
    std::cout << std::endl;
    Reserve reserve = Reserve();
    for (int i = 0; i < 8; i++) {
        std::cout << "getCard(): " << reserve.getCard() << std::endl;
        std::cout << "takeCard().getCard(): " << (*reserve.takeCard()).getCard() << std::endl;
        std::cout << "takeCard().getSuit(): " << (*reserve.takeCard()).getSuit() << std::endl;
    }
    return 0;
}
