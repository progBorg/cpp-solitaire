/**
 * \brief Stock class (inherits from Pile)
 * \details Part of the Reserve class, together with the Waste class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_STOCK_H
#define C_SOLITAIRE_STOCK_H

#include "Pile.h"

class Stock : public Pile { //inherit from Pile
// by default private
// ------------ Variables ------------
    std::vector<Card> cards; // vector containing all the cards in the current stock object

public: // constructor, queries and commands

// ------------ Constructor ------------
    Stock() : Pile(5,2) { // inherit from Pile

    }

// ------------ Queries ------------


// ------------ Commands ------------
/**
 * Removes to last card from the stock.
 */
    void removeCard() {
        cards.pop_back();
    }

///What does this function do?
    void addSet() {

    }

};

#endif //C_SOLITAIRE_STOCK_H
