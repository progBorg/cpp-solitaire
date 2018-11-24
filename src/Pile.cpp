#include "Pile.h"

/**
 * The constructor for the Pile class.
 * @param numStacks the amount of stacks in one Pile object
 * @param numCards the amount of cards per stack
 */
Pile::Pile(int numStacks, int numCards) {
	for (int index = 0; index < numStacks; index++) {
		Stack stack(numCards); // will put numCards of cards per stack
		stacks.push_back(stack);
	}
}

// ------------ Queries ------------
/**
 * @return the current Pile object
 */
Pile Pile::getPile() {
	return *this;
}

/**
 * @param index which stack number needs to be returned
 * @return the Stack object associated with this Pile
 */
Stack Pile::getStack(int index) {
	return stacks[index];
}
