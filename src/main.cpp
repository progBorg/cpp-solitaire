#include <iostream>
#include "Solitaire.h"

int main() {
    // Dialog options
    std::vector<std::string> gameplayOptions {
            "Yes",
            "No"
    };

    // Repeat until the user doesn't want to replay again
    bool replayGame = true;
    while (replayGame) {
        // Generate cards
        std::vector<Card*> gameCards;
        gameCards = Solitaire::generateCards();

        // Divide cards
        std::vector<Card*> tableauCards(gameCards.begin(), gameCards.begin() + 28);
        std::vector<Card*> reserveCards(gameCards.begin() + 28, gameCards.end());

        // Initiate and run game
        Solitaire solitaireGame(tableauCards, reserveCards);
        solitaireGame.run();

        // Ask user for another game
        // Get user input
        std::cout << "Would you like to play a new round?" << std::endl;
        switch (solitaireGame.getUserInput(gameplayOptions)) {
            case 1:
                replayGame = true;
                break;
            case 2:
            case 0:
                replayGame = false;
                break;
        }
    }

	std::cout << "Goodbye!" << std::endl;

    return 0;
}
