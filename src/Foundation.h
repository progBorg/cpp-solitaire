/**
 * \brief Foundation class (inherits from Pile)
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef CPP_SOLITAIRE_FOUNDATION_H
#define CPP_SOLITAIRE_FOUNDATION_H

#include "Pile.h"

class Foundation : public Pile {
// by default private
// ------------ Variables ------------

public: // constructor, queries and commands

// ------------ Constructor ------------
    explicit Foundation(int numStacks); // Inherits from pile
	Foundation();

// ------------ Queries ------------


// ------------ Commands ------------
	/**
	 * adds card to the foundation
	 * @param card the card to be added
	 * @param suit the column (ie suit) the card needs to be added to
	 * @return 'true' if it succeeded, 'false' if the card is unable to be placed there
	 */
	bool addCard(Card* card);

	/**
	 * removes top card from the foundation
	 * @param suit the column (ie suit) from which the top card needs to be removed
	 * @return the removed card, so it can be placed somewhere else
	 */
	Card* removeCard(int suit);

	/**
	 * Returns true when all top cards are kings, false otherwise
	 */
	bool isGameOver();

};


#endif //CPP_SOLITAIRE_FOUNDATION_H
