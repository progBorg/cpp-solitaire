/**
 * \brief Reserve class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef CPP_SOLITAIRE_RESERVE_H
#define CPP_SOLITAIRE_RESERVE_H

#include "Card.h"
#include "Stock.h"
#include "Waste.h"

class Reserve {
// by default private
// ------------ Variables ------------
    Stock stock = Stock(0, 0);
    Waste waste = Waste(0, 0);

public: // constructor, queries and commands
// ------------ Errors ------------

// ------------ Constructor ------------
    Reserve();

// ------------ Queries ------------
/**
 * Move a card from the stock pile to the waste pile, to make it visible to the player.
 */
    void getCard();

// ------------ Commands ------------
/**
 * Removes the top card from the waste pile, and returns a pointer to the respective card object.
 * @return pointer to the card object of the top card on the waste pile
 */
    Card* takeCard();

};


#endif //CPP_SOLITAIRE_RESERVE_H
