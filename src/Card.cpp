#include <string>
#include <cassert>
#include <iostream>

#include "Card.h"

/**
 * The constructor for the Card class.
 * @param inputSuit desired Suit for this specific card
 * @param inputType desired Type (value) for this specific card
 */
Card::Card(int inputSuit, int inputType) {
	this->suit = inputSuit;
	this->type = inputType;
	this->isVisible = false;
}

// ------------ Queries ------------
/**
 * @return the current card object
 */
int Card::getCard() {
	return suit*100+type; // concatenate suit and type together in one integer
}

/**
 * @return the Suit of the card
 */
int Card::getSuit() {
	return this->suit;
}

/**
 * @return the type of the card
 */
int Card::getType() {
	return this->type;
}

/**
 * @return the visibility of the card
 */
bool Card::getVisibility() {
	return this->isVisible;
}

// ------------ Commands ------------
/**
 * Sets the visibility of the card to the input parameter.
 * @param visibility the desired visibility of the card
 */
void Card::setVisibility(bool visibility) {
	this->isVisible = visibility;
}
