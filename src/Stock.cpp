#include "Stock.h"

Stock::Stock(int x, int y) : Pile(x, y) {

}

/**
 * Removes to last card from the stock.
 */
void Stock::removeCard() {
	cards.pop_back();
}

/**
 * Add a set of cards (only use to reset stock)
 */
void Stock::addSet() {

}
