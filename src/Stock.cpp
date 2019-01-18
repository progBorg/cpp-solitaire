#include "Stock.h"

/**
 * The constructor for the Stock class.
 */
Stock::Stock(int numStacks) : Pile(numStacks) {

}

Stock::Stock() : Stock::Stock(1) {}

/**
 * Removes to last card from the stock.
 */
Card* Stock::removeCard() {
    return this->getStack(0)->removeCard();
}

/**
 * Replace the set of cards (only used to reset stock)
 */
void Stock::addSet(std::vector<Card*> cards) {
    this->getStack(0)->addSet(cards);
}

/**
 * Reverse the order of the stack to ensure 'oldest' cards are back on top to be taken first.
 */
void Stock::reverse() {
    this->getStack(0)->reverse();
}
