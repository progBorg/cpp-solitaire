/**
 * \brief Card class used by the Stack class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \details The following format is adhered:
 *
 * - String 'deck' is the suit of the card, namely:
 * "Hearts" (red)
 * "Diamonds" (red)
 * "Spades" (black)
 * "Clubs" (black)
 *
 * - Integer 'type' is the value of the card:
 * 1 for Ace
 * 2-10 for respective values 2-10
 * 11 for Jack
 * 12 for Queen
 * 13 for King
 */

#ifndef C_SOLITAIRE_CARD_H
#define C_SOLITAIRE_CARD_H

#include <string>

class Card {
// by default private
// ------------ Variables ------------
///Why are these variables not working?
//    const int ACE = 1;
//    const int JACK = 11;
//    const int QUEEN = 12;
//    const int KING = 13;
const std::string HEARTS = "Hearts";
const std::string DIAMONDS = "Diamonds";
const std::string SPADES = "Spades";
const std::string CLUBS = "Clubs";

    std::string deck; // suit
    int type; // value
    bool isVisible;



public: // constructor, queries and commands

// ------------ Constructor ------------
/**
 * The constructor for the Card class.
 * @param inputDeck desired deck (suit) for this specific card
 * @param inputType desired type (value) for this specific card
 */
    Card(std::string inputDeck, int inputType) {
        std::string full = HEARTS+DIAMONDS+SPADES+CLUBS;
        assert(full.find(inputDeck) != std::string::npos && inputType >= 0 && inputType <= 13); // checking input values
        this->deck = std::move(inputDeck); // faster way of copying expensive parameters
        this->type = inputType;
        this->isVisible = false;
    }

// ------------ Queries ------------
/// what is this function used for?
/**
 * @return the current card object
 */
    Card getCard() {
        return *this;
    }

/**
 * @return the deck of the card
 */
    std::string getDeck() {
        return this->deck;
    }

/**
 * @return the type of the card
 */
    int getType() {
        return this->type;
    }

/**
 * @return the visibility of the card
 */
    bool getVisibility() {
        return this->isVisible;
    }

// ------------ Commands ------------
/**
 * Sets the visibility of the card to the input parameter.
 * @param visibility the desired visibility of the card
 */
    void setVisibility(bool visibility) {
        this->isVisible = visibility;
    }
};

#endif //C_SOLITAIRE_CARD_H
