/**
 * \brief Waste class (inherits from Pile)
 * \details Part of the Reserve class, together with the Stock class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef C_SOLITAIRE_WASTE_H
#define C_SOLITAIRE_WASTE_H

class Waste : public Pile { //inherit from Pile
// by default private
// ------------ Variables ------------

public: // constructor, queries and commands

// ------------ Constructor ------------
    Waste() : Pile(5,2) { // inherit from Pile

    }

// ------------ Queries ------------


// ------------ Commands ------------



};

#endif //C_SOLITAIRE_WASTE_H
