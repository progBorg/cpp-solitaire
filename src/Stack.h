/**
 * \brief Stack class used by the Pile class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef C_SOLITAIRE_STACK_H
#define C_SOLITAIRE_STACK_H

#include <vector>
#include "Card.h"

class Stack {

    // ------------ Variables ------------
    std::vector<Card*> cards; // vector containing all the cards in the current Stack object

// constructor, queries and commands
public:

    // ------------ Constructor ------------
    /**
     * The constructor for the Stack class.
     */
    explicit Stack();

    // ------------ Queries ------------
    /**
     * @return 'true' if there are no more cards present in the stack, 'false' otherwise
     */
    bool isEmpty();

    std::vector<Card*> getCards();

    int getTopType();

    int getTopSuit();

    // ------------ Commands ------------
    void appendSet(std::vector<Card*> cards);

    void addSet (std::vector<Card*> cards);

    /**
     * @param card the card that needs to be added to the stack
     */
    void addCard(Card* card);

    /**
	 * Removes to last card from the stack.
	 */
    Card* removeCard();

    /**
	 * Remove a set of cards
	 */
    void removeSet();

    /**
     * Inverse the order of the cards in the vector.
     */
    void reverse();

    std::vector<Card*> removeStartingFrom(int index);
};

#endif //C_SOLITAIRE_STACK_H
