/**
 * \brief Tableau class (inherits from Pile)
 * \details Part of the Reserve class, together with the Waste class
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
*/

#ifndef CPP_SOLITAIRE_TABLEAU_H
#define CPP_SOLITAIRE_TABLEAU_H

#include "Pile.h"
using namespace std;

//inherit from Pile
class Tableau : public Pile {
    // by default private
    // ------------ Variables ------------

// constructors, queries and commands
public:
    // ------------ Constructor ------------
    Tableau(vector<Card*> tableauCards, int numStacks); // Inherits from pile
    Tableau(vector<Card*> tableauCards);

    // ------------ Queries ------------


    // ------------ Commands ------------
    /**
     * Add a set of cards (only use to reset tableau).
     */
    bool addSet(int column, vector<Card*> cards);

    /**
     * Remove set of cards from tableau.
     */
    vector<Card*> removeSet(int column, int index);

};

#endif //CPP_SOLITAIRE_TABLEAU_H
