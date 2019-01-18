/**
 * \brief Card class used by the Stack class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
 * \details The following format is adhered:
 *
 * - Integer 'deck' is the suit of the card, namely:
 * 1 Hearts (red)
 * 2 Spades (black)
 * 3 Diamonds (red)
 * 4 Clubs (black)
 * So odd numbers are red, even are black.
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

class Card {
	// by default private
	// ------------ Variables ------------
	int suit; // suit
	int type; // value
	bool isVisible;

public:
    // types (value):
    const static int ACE = 1;
    const static int TWO = 2;
    const static int THREE = 3;
    const static int FOUR = 4;
    const static int FIVE = 5;
    const static int SIX = 6;
    const static int SEVEN = 7;
    const static int EIGHT = 8;
    const static int NINE = 9;
    const static int TEN = 10;
    const static int JACK = 11;
    const static int QUEEN = 12;
    const static int KING = 13;

    // suits:
    const static int HEARTS = 1;
    const static int SPADES = 2;
    const static int DIAMONDS = 3;
    const static int CLUBS = 4;

// constructors, queries and commands
	// ------------ Constructor ------------
	/**
	 * The constructor for the Card class.
	 * @param inputSuit desired suit for this specific card
	 * @param inputType desired type (value) for this specific card
	 */
	Card(int inputSuit, int inputType);

	// ------------ Queries ------------
	/**
	 * @return the current suit and type
	 */
	int getCard();
	/**
	 * @return the suit of the card
	 */
	int getSuit();
	/**
	 * @return the type of the card
	 */
	int getType();
	/**
	 * @return the visibility of the card
	 */
	bool getVisibility();

	// ------------ Commands ------------
	/**
	 * Sets the visibility of the card to the input parameter.
	 * @param visibility the desired visibility of the card
	 */
	void setVisibility(bool visibility);
};

#endif //C_SOLITAIRE_CARD_H
