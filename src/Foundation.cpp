#include "Foundation.h"

/**
 * The constructor for the Foundation class.
 */
Foundation::Foundation(int numStacks) : Pile(numStacks) {

}

Foundation::Foundation() : Foundation::Foundation(4) {}

/**
 * removes top card from the foundation
 * @param suit the column (ie suit) from which the top card needs to be removed
 * @return the removed card, so it can be placed somewhere else
 */
Card* Foundation::removeCard(int suit) {
    return stacks[suit-1]->removeCard();
}

/**
 * adds card to the foundation
 * @param card the card to be added
 * @param suit the column (ie suit) the card needs to be added to
 * @return 'true' if it succeeded, 'false' if the card is unable to be placed there
 */
bool Foundation::addCard(Card* card) {
    // card type needs to be the same of the stack it is being placed on, and;
    // the card Type needs to be one above the value of the card currently on top
    int suit = card->getSuit();
    if (card->getSuit() == suit && card->getType() == 1+ this->getStack(suit-1)->getTopType()) {
        getStack(suit-1)->addCard(card); // perform that addition
        return true; // success
    } else {
        return false; // failed
    }
}

/**
 * Returns true when all top cards are kings, false otherwise
 */
bool Foundation::isGameOver() {
	// Loop through each stack
	for (int i = 0; i < 4; i++) {
		// If at any point a non-king was found, return false
		if (this->getStack(i)->getTopType() != Card::KING) {
			return false;
		}
	}

	// If all four stacks have a king on top, return true
	return true;
}
