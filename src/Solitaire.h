/**
 * \brief General solitaire class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
 * \details Includes all the necessary headers to get a game started
 */
#ifndef C_SOLITAIRE_H
#define C_SOLITAIRE_H

#include "Card.h"
#include "Pile.h"
#include "Stack.h"
//#include "Stock.h" // These are included in Reserve.h
//#include "Waste.h"
#include "Foundation.h"
#include "Tableau.h"
#include "Reserve.h"
#include "Highscore.h"


class Solitaire {
// by default private
// ------------ Variables ------------
    int score;
    Foundation foundation;
    Tableau tableau;
    Reserve reserve;

	/**
	 * Print the playing board
	 */
	void printBoard();

	/**
	 * Prompt the user with the provided options.
	 * Returns the index of the chosen option.
	 */
	int getUserInput(std::vector<std::string> options);

public: // constructor, queries and commands

// ------------ Constructor ------------
    Solitaire(std::vector<Card*> tableauCards, std::vector<Card*> reserveCards);


// ------------ Commands ------------
	/**
	 * Run the game loop
	 */
    void run();

    /**
     * Generate all 52 game cards for future use
     * Returns a vector of cards, shuffled randomly
     */
	static std::vector<Card*> generateCards();
};

#endif
