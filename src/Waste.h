/**
 * \brief Waste class (inherits from Pile)
 * \details Part of the Reserve class, together with the Stock class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef C_SOLITAIRE_WASTE_H
#define C_SOLITAIRE_WASTE_H

#include "Pile.h"

//inherit from Pile
class Waste : public Pile {
// by default private
// ------------ Variables ------------

// constructors, queries and commands
public:

// ------------ Constructor ------------
    explicit Waste(int numStacks); // Inherits from Pile
    Waste();

// ------------ Queries ------------
/**
 * Check if the waste is empty.
 * @return 'true' if the waste stack is empty, 'false' otherwise
 */
    bool isEmpty();

// ------------ Commands ------------
/**
 * Add card to the stack object.
 * @param card the card to be added
 */
    void addCard(Card* card);

/**
 * Removes top card from the stack object.
 * @return the card that was removed
 */
    Card* removeCard();

/**
 * Remove all the cards from the waste stack, so it can be moved to the stock stack (used when there are no more cards available from the stock).
 * @return the current stack object
 */
    Stack recycle();

};

#endif //C_SOLITAIRE_WASTE_H
