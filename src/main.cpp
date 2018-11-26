#include <iostream>

#include "klondike.h"

int main() {
    const int ACE = 1;
    const int JACK = 11;
    const int QUEEN = 12;
    const int KING = 13;

    // testCard:
    Card fred("Hearts",KING);
    std::cout << "Hi, here is an overview of your cards:" << std::endl;
    std::cout << "Suit: " << fred.getSuit() << std::endl;
    std::cout << "Type: " << fred.getType() << std::endl;
    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;

    fred.setVisibility(true);
    std::cout << "\nAfter setting the visibility to true:" << std::endl;
    std::cout << "Suit: " << fred.getSuit() << std::endl;
    std::cout << "Type: " << fred.getType() << std::endl;
    std::cout << "Card is visible: " << std::boolalpha << fred.getVisibility() << std::endl;

//    // testStack:
//    Stack stack(2);
//    std::cout << "Stack card type through card: " << stack.getTopCard().getType() << std::endl;
//
//    // testPile:
//    Pile pile(5,2);
//    std::cout << "\nGet card type through pile and stack: " << pile.getStack(0).getTopCard().getType() << std::endl;
//
//    // testStock:
//    Stock stock(5, 2);
//    std::cout << "\nGet card type through Stock as well: " << stock.getPile().getStack(0).getTopCard().getType() << std::endl;
//    std::cout << "Shortcut using inheritance: " << stock.getStack(0).getTopCard().getType() << std::endl;
    return 0;
}
