/**
 * \brief Stack class used by the Pile class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_STACK_H
#define C_SOLITAIRE_STACK_H

#include <array>
#include <vector>
#include "Card.h"

class Stack {

    // ------------ Variables ------------
    std::vector<Card> cards; // vector containing all the cards in the current Stack object

// constructor, queries and commands
public:

	// ------------ Constructor ------------
	/**
	 * The constructor for the Stack class.
	 */
    Stack(int numCards);

	// ------------ Queries ------------
	/**
	 * @return the current stack object
	 */
    Stack getStack();
    /**
	 * @return the card object of the last card present in the current stack
	 */
    Card getTopCard();

	// ------------ Commands ------------
	/**
	 * @param card the card that needs to be added to the stack
	 */
    void addCard(Card card);
    /**
	 * Removes to last card from the stack.
	 */
    void removeCard();
    /**
	 * Add a set of cards
	 */
    void addSet();
    /**
	 * Remove a set of cards
	 */
    void removeSet();

};

#endif //C_SOLITAIRE_STACK_H
