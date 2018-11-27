/**
 * \brief Highscore class
 * \details Saves (if needed) the player's score and displays the saved highscores on screen.
 * \authors Dries Cavelaars
 * \authors Tom Veldman
*/

#ifndef CPP_SOLITAIRE_HIGHSCORE_H
#define CPP_SOLITAIRE_HIGHSCORE_H

#include <fstream>
#include <vector>


class Highscore {
// by default private
// ------------ Variables ------------
    std::ofstream outputFile; // write only
    std::ifstream inputFile; // read only
    std::vector<std::string> names; // temporary storing of read names from file
    std::vector<int> scores; // temporary storing of read scores from file

public: // constructor, queries and commands

// ------------ Constructor ------------
    Highscore();

// ------------ Queries ------------
    std::vector<std::pair<std::string, int>> getScores(); // vector pair containing name and score

// ------------ Commands ------------
    void saveScore(std::string name, int score);
};


#endif //CPP_SOLITAIRE_HIGHSCORE_H
