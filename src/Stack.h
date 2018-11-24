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

public: // constructor, queries and commands

// ------------ Constructor ------------
/**
 * The constructor for the Stack class.
 */
    Stack(int numCards) {
        for (int index = 0; index < numCards; index++) {
            Card card("Hearts", 5); // this will obviously have to be randomized
            addCard(card);
        }
    }

// ------------ Queries ------------
/**
 * @return the current stack object
 */
    Stack getStack() {
        return *this;
    }
/**
 * @return the card object of the last card present in the current stack
 */
    Card getTopCard() {
        return cards.back();
    }
// ------------ Commands ------------
/**
 * @param card the card that needs to be added to the stack
 */
    void addCard(Card card) {
        cards.push_back(card);
    }
/**
 * Removes to last card from the stack.
 */
    void removeCard() {
        cards.pop_back();
    }
///What does this function do?
    void addSet() {

    }
///What does this function do?
    void removeSet() {

    }

};

#endif //C_SOLITAIRE_STACK_H
