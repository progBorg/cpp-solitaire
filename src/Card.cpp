#include <iostream>
#include <string>
#include <cassert>
#include "Card.h"

/**
 * The constructor for the Card class.
 * @param inputSuit desired Suit for this specific card
 * @param inputType desired Type (value) for this specific card
 */
Card::Card(int inputSuit, int inputType) {
	this->suit = inputSuit;
	this->type = inputType;
	this->isVisible = true; // All cards are visible by default
}

// ------------ Queries ------------
/**
 * @return the current card representation
 */
int Card::getCard() {
	return (suit * 100) + type; // concatenate suit and type together in one integer
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
