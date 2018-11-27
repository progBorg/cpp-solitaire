#include "Tableau.h"

/**
 * The constructor for the Tableau class.
 */
Tableau::Tableau(int x, int y) : Pile(x, y) {

}

/**
 * Add a set of cards to the tableau (this set can also be coming from the tableau).
 * @param column the column where the set needs to move to (columns 0 - 6)
 * @param cards the set of cards that need to be added
 * @return 'true' if the move was carried out, 'false' if the move is not allowed
 */
bool Tableau::addSet(int column, std::vector<Card*> cards) {
    // top card of tableau is one value above bottom card of vector to be placed, and;
    // both even or both odd
    // OR:
    // if no cards present in this row, only type KING is allowed to be placed here
    if ((stacks[column]->getTopType() == 0 && (*cards.begin())->getType() == Card::KING) ||
        (stacks[column]->getTopType() == 1 + (*cards.begin())->getType() &&
         stacks[column]->getTopSuit() % 2 == (*cards.begin())->getSuit() % 2)) {
        stacks[column]->appendSet(cards);
        return true;
    }
}

/**
 * Remove set of cards from tableau.
 */
std::vector<Card*> Tableau::removeSet(int column, int index) {
    return stacks[column]->removeStartingFrom(index);
}
