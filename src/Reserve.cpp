#include "Reserve.h"
#include "Stock.h"
#include "Waste.h"

Reserve::Reserve() {
    this->stock = Stock(1,2);
    this->waste = Waste(1,2);
}

/**
* Move a card from the stock pile to the waste pile, to make it visible to the player.
*/
void Reserve::getCard() {
    Card* tempCard = this->stock.removeCard();
    if (tempCard != nullptr) { // if the removeCard() was completed successfully
        this->waste.addCard(tempCard); // add the top card to the waste
    } else {
        if (this->waste.isEmpty()) {
            // error: Reserve is completely empty
            // TODO is an error message needed?
        } else { // recycle the cards back to stock
            this->stock.addSet(this->waste.recycle()); // moving the stack from the waste pile to the stock pile
            getCard(); // then running the function again
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
        // TODO is an error message needed?
    }
}