/**
 * \brief Waste class (inherits from Pile)
 * \details Part of the Reserve class, together with the Stock class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_WASTE_H
#define C_SOLITAIRE_WASTE_H

#include "Pile.h"

//inherit from Pile
class Waste : public Pile {
	// by default private
	// ------------ Variables ------------

// constructors, queries and commands
public:

	// ------------ Constructor ------------
	// inherit from Pile
    Waste(int x, int y); // Inherits from Pile

	// ------------ Queries ------------


	// ------------ Commands ------------



};

#endif //C_SOLITAIRE_WASTE_H
