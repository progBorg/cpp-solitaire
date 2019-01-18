#include <utility>
#include <algorithm>
#include "Stack.h"

/**
 * The constructor for the Stack class.
 */
Stack::Stack() {

}

// ------------ Queries ------------
/**
* @return 'true' if there are no more cards present in the stack, 'false' otherwise
*/
bool Stack::isEmpty() {
    return this->cards.empty();
}

std::vector<Card*> Stack::getCards() {
    return this->cards;
}

int Stack::getTopType() {
    return cards.empty() ? 0 : this->cards.back()->getType();
}

int Stack::getTopSuit() {
    return cards.empty() ? 0 : this->cards.back()->getSuit();
}

// ------------ Commands ------------

void Stack::appendSet(std::vector<Card*> cards) {
    this->cards.insert(this->cards.end(), cards.begin(), cards.end());
}

/**
 * Replaces the current cards vector (stack) by the input stack.
 * @param cards the vector of cards that replaces the current stack
 */
void Stack::addSet(std::vector<Card*> cards) {
    this->cards = move(cards);
}

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

/**
 * Inverse the order of cards in the vector.
 */
void Stack::reverse() {
    std::reverse(cards.begin(), cards.end());
}

std::vector<Card*> Stack::removeStartingFrom(int index) {
	// Create iterators
    std::vector<Card*>::const_iterator first = cards.begin() + index;
    std::vector<Card*>::const_iterator last = cards.end();

    // Remove cards
    std::vector<Card*> lastCards(first, last);
    cards.resize(index-1);

    return lastCards;
}
