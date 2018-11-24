/**
 * \brief Pile class as parent of the Stock, Waste, Foundation and Tableau
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_PILE_H
#define C_SOLITAIRE_PILE_H

#include "Stack.h"

class Pile {
// by default private
// ------------ Variables ------------
    std::vector<Stack> stacks; // vector containing all the stacks in the current Pile object

public: // constructor, queries and commands

// ------------ Constructor ------------
/**
 * The constructor for the Pile class.
 * @param numStacks the amount of stacks in one Pile object
 * @param numCards the amount of cards per stack
 */
    Pile(int numStacks, int numCards) {
        for (int index = 0; index < numStacks; index++) {
            Stack stack(numCards); // will put numCards of cards per stack
            stacks.push_back(stack);
        }
    }

// ------------ Queries ------------
/**
 * @return the current Pile object
 */
    Pile getPile() {
        return *this;
    }

/**
 * @param index which stack number needs to be returned
 * @return the Stack object associated with this Pile
 */
    Stack getStack(int index) {
        return stacks[index];
    }

// ------------ Commands ------------

};

#endif //C_SOLITAIRE_PILE_H
