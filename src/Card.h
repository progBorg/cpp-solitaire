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

class Card {
	// by default private
	// ------------ Variables ------------
	///Why are these variables not working?
	const int ACE = 1;
	const int JACK = 11;
	const int QUEEN = 12;
	const int KING = 13;
	const std::string HEARTS = "Hearts";
	const std::string DIAMONDS = "Diamonds";
	const std::string SPADES = "Spades";
	const std::string CLUBS = "Clubs";

	std::string suit; // suit
	int type; // value
	bool isVisible;


// constructors, queries and commands
public:

	// ------------ Constructor ------------
	/**
	 * The constructor for the Card class.
	 * @param inputDeck desired deck (suit) for this specific card
	 * @param inputType desired type (value) for this specific card
	 */
	Card(std::string inputDeck, int inputType);

	// ------------ Queries ------------
	/**
	 * @return the current suit and type
	 */
	int getCard();
	/**
	 * @return the suit of the card
	 */
	std::string getSuit();
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
