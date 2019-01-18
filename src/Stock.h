/**
 * \brief Stock class (inherits from Pile)
 * \details Part of the Reserve class, together with the Waste class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef C_SOLITAIRE_STOCK_H
#define C_SOLITAIRE_STOCK_H

#include "Pile.h"
using namespace std;

//inherit from Pile
class Stock : public Pile {
    // by default private
    // ------------ Variables ------------

// constructors, queries and commands
public:

    // ------------ Constructor ------------
    Stock(int numStacks); // Inherits from pile
    Stock();

    // ------------ Queries ------------


    // ------------ Commands ------------
    /**
     * Removes to last card from the stock.
     */
    Card* removeCard();
    /**
     * Add a set of cards (only used to reset stock)
     */
    void addSet(vector<Card*>);

    /**
    * Reverse the order of the stack to ensure 'oldest' cards are back on top to be taken first.
    */
    void reverse();

};

#endif //C_SOLITAIRE_STOCK_H
