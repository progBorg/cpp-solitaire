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
    std::vector<Stack*> stacks; // vector consists of 7 stacks

// constructors, queries and commands
public:
    // ------------ Constructor ------------
    Tableau(int x, int y); // Inherits from pile

    // ------------ Queries ------------


    // ------------ Commands ------------
    /**
     * Add a set of cards (only use to reset tableau).
     */
    bool addSet(int column, std::vector<Card*> cards);

    /**
     * Remove set of cards from tableau.
     */
    std::vector<Card*> removeSet(int column, int index);

};

#endif //CPP_SOLITAIRE_TABLEAU_H
