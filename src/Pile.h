/**
 * \brief Pile class as parent of the Stock, Waste, Foundation and Tableau
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef C_SOLITAIRE_PILE_H
#define C_SOLITAIRE_PILE_H

#include "Stack.h"

class Pile {
	// by default private
protected:
	// ------------ Variables ------------
    std::vector<Stack*> stacks; // vector containing all the stacks in the current Pile object

// constructors, queries and commands
public:

	// ------------ Constructor ------------
	/**
	 * The constructor for the Pile class.
	 * @param numStacks the amount of stacks in one Pile object
	 * @param numCards the amount of cards per stack
	 */
    explicit Pile(int numStacks);

	// ------------ Queries ------------
	/**
	 * @return the current Pile object
	 */
    Pile getPile();
	/**
	 * @param index which stack number needs to be returned
	 * @return the Stack object associated with this Pile
	 */
    Stack* getStack(int index);

	// ------------ Commands ------------

};

#endif //C_SOLITAIRE_PILE_H
