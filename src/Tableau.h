/**
 * \brief Tableau class (inherits from Pile)
 * \details Part of the Reserve class, together with the Waste class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef CPP_SOLITAIRE_TABLEAU_H
#define CPP_SOLITAIRE_TABLEAU_H

#include "Pile.h"

//inherit from Pile
class Tableau : public Pile {
    // by default private
    // ------------ Variables ------------

// constructors, queries and commands
public:

    // ------------ Constructor ------------
    Tableau(int x, int y); // Inherits from pile

    // ------------ Queries ------------


    // ------------ Commands ------------

    /**
     * Adds card to the tableau
     */
    void addCard();

    /**
     * Removes to last card from the tableau.
     */
    void removeCard();

    /**
     * Add a set of cards (only use to reset tableau).
     */
    void addSet();

    /**
     * Remove set of cards from tableau.
     */
    void removeSet();

};


#endif //CPP_SOLITAIRE_TABLEAU_H
