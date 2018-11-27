/**
 * \brief Foundation class (inherits from Pile)
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef CPP_SOLITAIRE_FOUNDATION_H
#define CPP_SOLITAIRE_FOUNDATION_H

#include "Pile.h"

class Foundation : public Pile {
// by default private
// ------------ Variables ------------
    std::vector<Stack*> stacks; // vector consists of 4 stacks, each with their (suit integer - 1) as the index

public: // constructor, queries and commands

// ------------ Constructor ------------
    Foundation(int x, int y); // Inherits from pile

// ------------ Queries ------------


// ------------ Commands ------------
/**
 * adds card to the foundation
 * @param card the card to be added
 * @param suit the column (ie suit) the card needs to be added to
 * @return 'true' if it succeeded, 'false' if the card is unable to be placed there
 */
bool addCard(Card* card, int suit);

/**
 * removes top card from the foundation
 * @param suit the column (ie suit) from which the top card needs to be removed
 * @return the removed card, so it can be placed somewhere else
 */
Card* removeCard(int suit);


};


#endif //CPP_SOLITAIRE_FOUNDATION_H
