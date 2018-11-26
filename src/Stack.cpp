#include "Stack.h"

/**
 * The constructor for the Stack class.
 */
Stack::Stack(int numCards) {
    for (int index = 0; index < numCards; index++) {
        Card card("Hearts", 5); // this will obviously have to be randomized
        Card* cardPtr = &card;
        addCard(cardPtr);
    }
}

// ------------ Queries ------------
/**
* @return 'true' if there are no more cards present in the stack, 'false' otherwise
*/
bool Stack::isEmpty() {
    return this->cards.empty();
}
// ------------ Commands ------------
/**
 * @param card the card that needs to be added to the stack
 */
void Stack::addCard(Card* card) {
    this->cards.push_back(card);
}
/**
 * Removes to last card from the stack.
 */
Card* Stack::removeCard() {
    if (!this->cards.empty()) {
        Card *lastCard = cards.back();
        this->cards.pop_back();
        return lastCard;
    } else {
        return nullptr;
    }
}
/**
 * Remove all cards present in this stack object
 */
void Stack::removeSet() {
    this->cards.clear();
}