#include "Tableau.h"
#include <iostream>

/**
 * The constructor for the Tableau class.
 */
Tableau::Tableau(std::vector<Card*> tableauCards, int numStacks) : Pile(numStacks) {
	int cardCounter = 0; // Keeps track of which card to push next
	// Divide cards over the stacks triangularly
	for (int i = 0; i < numStacks; i++) {
		// Fill temporary vector with cards
		std::vector<Card*> cardSet;
		cardSet.clear();
		cardSet.reserve(i + 1); // Reserve space in advance
		for (int j = 0; j < (i + 1); j++) {
			cardSet.push_back(tableauCards[cardCounter]);
			cardSet.back()->setVisibility(false);
			cardCounter++;
		}
		// Undo invisibility of top card
		cardSet.back()->setVisibility(true);

		this->getStack(i)->addSet(cardSet);
	}
}

// Set default constructor to construct 7 columns
Tableau::Tableau(std::vector<Card*> tableauCards) : Tableau::Tableau(tableauCards, 7) {}

/**
 * Add a set of cards to the tableau (this set can also be coming from the tableau).
 * @param column the column where the set needs to move to (columns 0 - 6)
 * @param cards the set of cards that need to be added
 * @return 'true' if the move was carried out, 'false' if the move is not allowed
 */
bool Tableau::addSet(int column, std::vector<Card*> cards) {
    // top card of tableau is one value above bottom card of vector to be placed, and;
    // both different color (black and red or red and black)
    // OR:
    // if no cards present in this row, only type KING is allowed to be placed here
    if ((stacks[column]->getTopType() == 0 && (*cards.begin())->getType() == Card::KING) ||
            (stacks[column]->getTopType() == 1 + (*cards.begin())->getType() &&
            stacks[column]->getTopSuit() % 2 != (*cards.begin())->getSuit() % 2))
    {
        stacks[column]->appendSet(cards);
        return true;
    }

    return false;
}

bool Tableau::addCard(int column, Card* card) {
	// top card of tableau is one value above bottom card of vector to be placed, and;
    // both different color (black and red or red and black)
    // OR:
    // if no cards present in this row, only type KING is allowed to be placed here
    if ((this->getStack(column)->getTopType() == 0 && card->getType() == Card::KING) ||
            (this->getStack(column)->getTopType() == 1 + card->getType() &&
            this->getStack(column)->getTopSuit() % 2 != card->getSuit() % 2))
    {
        this->getStack(column)->addCard(card);
        return true;
    }

    return false;
}

/**
 * Remove set of cards from tableau.
 */
std::vector<Card*> Tableau::removeSet(int column, int index) {
    return stacks[column]->removeStartingFrom(index);
}
