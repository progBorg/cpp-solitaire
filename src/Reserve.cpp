#include "Reserve.h"
#include "Stock.h"
#include "Waste.h"

/**
 * Construct Reserve, initializing stock and waste to empty stacks
 */
Reserve::Reserve(std::vector<Card*> wasteCards) : stock(), waste() {
	this->stock.getStack(0)->addSet(wasteCards); // Add the cards to the waste pile
}

/**
* Move a card from the stock pile to the waste pile, to make it visible to the player.
*/
int Reserve::getCard() {
    Card* tempCard = this->stock.removeCard();
    if (tempCard != nullptr) { // if the card was successfully removed
        this->waste.addCard(tempCard); // add the top card to the waste
        return 0;
    } else {
        if (this->waste.isEmpty()) {
            return -1; // Error: reserve is completely empty
        } else { // recycle the cards back to stock
            this->stock.addSet(this->waste.recycle().getCards()); // moving the stack from the waste pile to the stock pile
            stock.reverse(); // invert order of stock to put old cards on top again
            getCard(); // then running the function again
            return 0;
        }
    }
}

/**
 * Removes the top card from the waste pile, and returns a pointer to the respective card object.
 * @return pointer to the card object of the top card on the waste pile
 */
Card* Reserve::takeCard() {
    Card* lastCard = this->waste.removeCard();
    if (lastCard != nullptr) {
        return lastCard;
    } else {
        return nullptr; // error: no card in waste to be taken
    }
}

/**
 * Get the stock pile
 */
Stock Reserve::getStock() {
	return this->stock;
}

/**
 * Get the waste pile
 */
Waste Reserve::getWaste() {
	return this->waste;
}
