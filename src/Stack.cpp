#include "Stack.h"

/**
 * The constructor for the Stack class.
 */
Stack::Stack(int numCards) {
	for (int index = 0; index < numCards; index++) {
		Card card("Hearts", 5); // this will obviously have to be randomized
		addCard(card);
	}
}

// ------------ Queries ------------
/**
 * @return the current stack object
 */
Stack Stack::getStack() {
	return *this;
}
/**
 * @return the card object of the last card present in the current stack
 */
Card Stack::getTopCard() {
	return cards.back();
}
// ------------ Commands ------------
/**
 * @param card the card that needs to be added to the stack
 */
void Stack::addCard(Card card) {
	cards.push_back(card);
}
/**
 * Removes to last card from the stack.
 */
void Stack::removeCard() {
	cards.pop_back();
}
/**
 * Add a set of cards
 */
void Stack::addSet() {

}
/**
 * Remove a set of cards
 */
void Stack::removeSet() {

}
