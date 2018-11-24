#include <string>
#include <cassert>
#include "Card.h"

/**
 * The constructor for the Card class.
 * @param inputSuit desired Suit (suit) for this specific card
 * @param inputType desired type (value) for this specific card
 */
Card::Card(std::string inputSuit, int inputType) {
	std::string full = HEARTS+DIAMONDS+SPADES+CLUBS;
	assert(full.find(inputSuit) != std::string::npos && inputType >= 0 && inputType <= 13); // checking input values
	this->suit = std::move(inputSuit); // faster way of copying expensive parameters
	this->type = inputType;
	this->isVisible = false;
}

// ------------ Queries ------------
/**
 * @return the current card object
 */
int Card::getCard() {
	return 101;
}

/**
 * @return the Suit of the card
 */
std::string Card::getSuit() {
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
