/**
 * \brief Reserve class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef CPP_SOLITAIRE_RESERVE_H
#define CPP_SOLITAIRE_RESERVE_H

#include "Card.h"
#include "Stock.h"
#include "Waste.h"

class Reserve {
// by default private
// ------------ Variables ------------
    Stock stock;
    Waste waste;

public: // constructor, queries and commands
// ------------ Constructor ------------
    explicit Reserve(std::vector<Card*> wasteCards);

// ------------ Queries ------------
	/**
	 * Move a card from the stock pile to the waste pile, to make it visible to the player.
	 */
    int getCard();
    /**
     * Get the stock pile
     */
    Stock getStock();
	/**
     * Get the waste pile
     */
    Waste getWaste();

// ------------ Commands ------------
/**
 * Removes the top card from the waste pile, and returns a pointer to the respective card object.
 * @return pointer to the card object of the top card on the waste pile
 */
    Card* takeCard();

/**
 * Only returns the top card from the waste pile, without removing it.
 * @return pointer to the card object of the top card on the waste pile
 */
    Card* topCard();

    };


#endif //CPP_SOLITAIRE_RESERVE_H
