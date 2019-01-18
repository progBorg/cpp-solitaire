#include "Highscore.h"

/**
 * The constructor for the Highscore class.
 */
Highscore::Highscore() = default;

void Highscore::saveScore(std::string name, int score) {
    outputFile.open("highscore.txt", std::ios_base::app); // start writing at the end of the file
    outputFile << name << "\t" << score << "\n"; // name and score separated by a tab character
    outputFile.close();
}

/**
 * Read saved highscores from file, then sort in descending order and return the vector pairs.
 * @return the vector pair of the string name and corresponding integer score
 */
std::vector<std::pair<std::string, int>> Highscore::getScores() {
    std::vector<std::pair<std::string, int>> highScores;

    inputFile.open("highscore.txt"); // open file to read
    std::string name;
    int score;

    while (inputFile >> name >> score) { // read names and scores
        names.push_back(name); // add the variables to the correct vector
        scores.push_back(score);
    }

    for (int i = 0; i < names.size(); i++) { // create vecor pairs from the variables
        highScores.emplace_back(std::make_pair(names[i],scores[i]));
    }

    // sort by second element of the pair (the integer value score)
    // used reverse iterators to sort in descending order
    std::sort(highScores.rbegin(), highScores.rend(), [](const std::pair<std::string,int> &a, const std::pair<std::string,int> &b) {
        return a.second < b.second;
    });
    inputFile.close();
    return highScores;
}
