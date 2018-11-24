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
    std::vector<Card> cards; // vector containing all the cards in the current stock object

// constructors, queries and commands
public:

	// ------------ Constructor ------------
    Stock(int x, int y); // Inherits from pile

	// ------------ Queries ------------


	// ------------ Commands ------------
	/**
	 * Removes to last card from the stock.
	 */
    void removeCard();
	/**
	 * Add a set of cards (only use to reset stock)
	 */
    void addSet();

};

#endif //C_SOLITAIRE_STOCK_H
