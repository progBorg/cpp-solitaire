/**
 * \brief Stock class (inherits from Pile)
 * \details Part of the Reserve class, together with the Waste class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_STOCK_H
#define C_SOLITAIRE_STOCK_H

#include "Pile.h"

//inherit from Pile
class Stock : public Pile {
    // by default private
    // ------------ Variables ------------
    Stack stack = Stack(0);

// constructors, queries and commands
public:

    // ------------ Constructor ------------
    Stock(int x, int y); // Inherits from pile

    // ------------ Queries ------------


    // ------------ Commands ------------
    /**
     * Removes to last card from the stock.
     */
    Card* removeCard();
    /**
     * Add a set of cards (only used to reset stock)
     */
    void addSet(std::vector<Card*>);

    /**
    * Reverse the order of the stack to ensure 'oldest' cards are back on top to be taken first.
    */
    void reverse();

};

#endif //C_SOLITAIRE_STOCK_H
