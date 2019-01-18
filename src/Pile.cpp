#include "Pile.h"
using namespace std;

/**
 * The constructor for the Pile class.
 * @param numStacks the amount of stacks in one Pile object
 * @param numCards the amount of cards per stack
 */
Pile::Pile(int numStacks) {
	for (int index = 0; index < numStacks; index++) {
		Stack* stack = new Stack; // Create empty stack
		stacks.push_back(stack); // Add stack to pile
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
Stack* Pile::getStack(int index) {
	return stacks[index];
}
