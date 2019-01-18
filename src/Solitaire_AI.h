/**
 * \brief Solitaire AI, to help the player choose a move
 * \authors Dries Cavelaars
 * \authors Tom Veldman
 * \authors Bas Spijkerman
 */

#ifndef SRC_SOLITAIRE_AI_H
#define SRC_SOLITAIRE_AI_H

#include "Foundation.h"
#include "Stock.h"
#include "Tableau.h"
#include "Waste.h"

class Solitaire_AI {
public:
    // ------------ Constructor ------------
    /**
     * Construct this class
     */
    Solitaire_AI();

    // ------------ Methods ------------
    int determineMove(Waste waste, Stock stock, Tableau tableau, Foundation foundation);
};


#endif //SRC_SOLITAIRE_AI_H
