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

public: // constructor, queries and commands

// ------------ Constructor ------------
    Foundation(int x, int y); // Inherits from pile

// ------------ Queries ------------


// ------------ Commands ------------
/**
 * adds card to the foundation
 */
void addCard();

/**
 * removes card from the foundation
 */
void removeCard();


};


#endif //CPP_SOLITAIRE_FOUNDATION_H
