#include "Stock.h"

/**
 * The constructor for the Stock class.
 */
Stock::Stock(int x, int y) : Pile(x, y) {
//    this->stack = Stack(1);
}

/**
 * Removes to last card from the stock.
 */
Card* Stock::removeCard() {
    return this->stack.removeCard();
}

/**
 * Replace the set of cards (only used to reset stock)
 */
void Stock::addSet(std::vector<Card*> cards) {
    this->stack.addSet(cards);
}

/**
 * Reverse the order of the stack to ensure 'oldest' cards are back on top to be taken first.
 */
void Stock::reverse() {
    this->stack.reverse();
}