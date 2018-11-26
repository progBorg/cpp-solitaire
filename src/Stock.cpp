#include "Stock.h"

/**
 * The constructor for the Stock class.
 */
Stock::Stock(int x, int y) : Pile(x, y) {
    this->stack = Stack(1);
}

/**
 * Removes to last card from the stock.
 */
Card* Stock::removeCard() {
    return this->stack.removeCard();
}

/**
 * Replace a set of cards (only used to reset stock)
 */
void Stock::addSet(Stack stack) {
    this->stack = stack;
}
