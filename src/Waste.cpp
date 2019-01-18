#include "Waste.h"

Waste::Waste(int numStacks) : Pile(numStacks) {

}
Waste::Waste() : Waste::Waste(1) {}

// ------------ Queries ------------
/**
 * Check if the waste is empty.
 * @return 'true' if the waste stack is empty, 'false' otherwise
 */
bool Waste::isEmpty() {
    return this->getStack(0)->isEmpty();
}

// ------------ Commands ------------
/**
 * Add card to the stack object.
 * @param card the card to be added
 */
void Waste::addCard(Card* card) {
    this->getStack(0)->addCard(card);
}

/**
 * Removes top card from the stack object.
 * @return the card that was removed
 */
Card* Waste::removeCard() {
    return this->getStack(0)->removeCard();
}

/**
 * Remove all the cards from the waste stack, so it can be moved to the stock stack (used when there are no more cards available from the stock).
 * @return the current stack object
 */
Stack Waste::recycle() {
    Stack* currentStack = this->getStack(0);
    this->getStack(0)->removeSet();
    return *currentStack;
}

