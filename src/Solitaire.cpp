#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>
#include <chrono>
#include "Solitaire.h"

// ------------ Constructor ------------
// Create game and initialize foundation, tableau and reserve
Solitaire::Solitaire(std::vector<Card*> tableauCards, std::vector<Card*> reserveCards) :
        foundation(),
        tableau(tableauCards),
        reserve(reserveCards)
{

}

/**
 * Generate all cards and return them randomly shuffled
 */
std::vector<Card*> Solitaire::generateCards() {
    // Get all card values and suits
    int values[13] = {Card::ACE, Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN,
                      Card::JACK, Card::QUEEN, Card::KING};
    int suits[4] = {Card::HEARTS, Card::SPADES, Card::DIAMONDS, Card::CLUBS};

    // Generate all cards
    std::vector<Card*> gameCards;
    gameCards.reserve(52); // Reserve space in advance
    for (int suit = 0; suit < 4; suit++) {
        for (int value = 0; value < 13; value++) {
            // Generate current card in place and add it to the vector
            auto * tempCard = new Card(suits[suit], values[value]);
            gameCards.push_back(tempCard);
        }
    }

    // shuffle cards, using the current time as seed for the random generator
    unsigned int seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle(std::begin(gameCards), std::end(gameCards), std::default_random_engine(seed));

    return gameCards;
}

// ------------ Commands ------------
/**
 * Run the game
 */
void Solitaire::run() {
    std::cout << "Welcome to Solitaire!" << std::endl;

    std::vector<std::string> moveOptions {
            "Get new card from Stock",
            "Move card from Waste to Tableau",
            "Move card from Waste to Foundation",
            "Move card from Tableau to Foundation",
            "Move cards within Tableau"
    };

    bool winnerWinnerChickenDinner = false; // set to 'true' to skip game, go directly to highscore process
    while (!winnerWinnerChickenDinner) {
        printBoard();

        // Get user move
        std::cout << "What would you like to do?" << std::endl;
        int choice = getUserInput(moveOptions);

        // Parse user move
        switch (choice) {
			case 0:
				std::cout << "Exiting current game..." << std::endl << std::endl;
				return;
            case 1: // card from stock
                cardFromStock();
                break;
            case 2: // waste to tableau
                wasteToTableau();
                break;
            case 3: // waste to foundation
                wasteToFoundation();
                break;
            case 4: // tableau to foundation
                tableauToFoundation();
                break;
            case 5: // move within tableau
                tableauMove();
                break;
            default:
                std::cout << "A user input error has occured, exiting..." << std::endl;
                return;
        }

        winnerWinnerChickenDinner = foundation.isGameOver();
    }

    std::cout << "Congratulations, you've won!" << std::endl;

    // ---------- Highscore system ----------
    std::cout << "Would you like to save your score?" << std::endl;

    std::vector<std::string> highscoreOptions {
            "Yes",
            "No"
    };

    Highscore highscore;
    switch (getUserInput(highscoreOptions)) {
        case 1: { // save score
            std::cout << "What is your name?" << std::endl;
            std::string name;
            std::cin >> name;
            highscore.saveScore(name, score);
            break;
        }
        case 0: { // exit highscore sytem
            return;
        }
        default: { // go on to displaying saved scores
            break;
        }
    }

    // read saved highscores and print them
    std::cout << "\nThe highscores are:" << std::endl;
    std::vector<std::pair<std::string, int>> scores = highscore.getScores();
    for (int row = 0; row < scores.size(); row++) {
        std::cout << scores[row].first << "\t" << scores[row].second << std::endl;
    }
}

/**
 * Prints the board to screen
 */
void Solitaire::printBoard() {
	// Separator
	std::cout << "___________________________________________________" << std::endl;

    Waste wasteStack = this->reserve.getWaste();
    Stock stockStack = this->reserve.getStock();

	// Pile descriptions
	std::cout << "Stock\tWaste\t\tFoundation" << std::endl;

    // ------------ Stock ------------
    std::cout << stockStack.getPile().getStack(0)->getCards().size() << "\t";

    // ------------ Waste ------------
    std::vector<Card *> wasteCards = wasteStack.getStack(0)->getCards();
    if (wasteCards.empty()) {
        std::cout << "---" << "\t\t";
    } else {
		std::cout << wasteCards.back()->getCard() << "\t\t";
    }

    // ------------ Foundation ------------
	// Print the top card of each foundation column
	for (int column = 0; column < 4; column++) {
		if (foundation.getStack(column)->getCards().empty()) {
			std::cout << "---" << "\t"; // print absence of card
		} else {
			std::cout << foundation.getStack(column)->getCards().back()->getCard() << "\t";
		}
	}

// ------------ Tableau ------------
	// Separate top row and tableau
	std::cout << std::endl << std::endl << "Tableau" << std::endl;
	std::cout << "(1)\t(2)\t(3)\t(4)\t(5)\t(6)\t(7)" << std::endl;

	// Retrieve all cards and store them in a matrix
    std::vector<std::vector<Card *>> matrix; // storing cards in a matrix
    for (int stack = 0; stack < 7; stack++) {
        matrix.push_back(tableau.getStack(stack)->getCards());
    }

	// Check how far down we need to go through the tableau rows
    unsigned long maximum = std::max({
        matrix[0].size(),
        matrix[1].size(),
        matrix[2].size(),
        matrix[3].size(),
        matrix[4].size(),
        matrix[5].size(),
        matrix[6].size()
    });

	// Loop through all rows that need printing
    for (int row = 0; row < maximum; row++) {
		// Loop through all columns
        for (int column = 0; column < 7; column++) {
            if (row <= (int) matrix[column].size() - 1) { // row is in range of this column
                if (matrix[column][row]->getVisibility()) { // only if card is visible
                    std::cout << matrix[column][row]->getCard() << "\t"; // print the current card
                } else {
                    std::cout << "???" << "\t"; // visibility is 'hidden', so print "??"
                }
            } else {
                std::cout << "---" << "\t"; // print absence of card
            }
        }
        std::cout << std::endl; // move on to next row
    }

	// A little spacing between playing board and options
	std::cout << "___________________________________________________" << std::endl << std::endl;
}

/**
 * Prints options to screen, let's user choose, and returns the index of the chosen option.
 */
int Solitaire::getUserInput(std::vector<std::string> options) {
	// Print options
	for (int i = 0; i < options.size(); i++) {
		std::cout << i+1 << ") " << options[i] << std::endl;
	}
	std::cout << "0) Exit/Cancel" << std::endl;

	std::string input = "";
	int choice = 0;
	bool correctInput = false;
	while (!correctInput) {
		// Get user input
		std::cout << ">>";
		std::getline(std::cin, input);

		// Safely convert string to number
		std::stringstream myStream(input);
		// If input is indeed an integer
		if (myStream >> choice) {
			if (0 <= choice && choice <= options.size()) {
				correctInput = true; // check if input is in selectable range
			} else {
				std::cout << "That is not a valid choice. Please try again." << std::endl;
			}
		} else {
			std::cout << "Please input a number." << std::endl;
		}
	}

	return choice;
}

/**
 * Game move methods
 */
void Solitaire::cardFromStock() {
	// Get card from stock
	if (this->reserve.getCard()) {
		// Waste and stock are both empty
		std::cout << "ERROR: Can't get a new card, waste and stock are empty." << std::endl;
	}
}

void Solitaire::wasteToTableau() {
    std::vector<std::string> tableauColumnOptions {
            "Column 1",
            "Column 2",
            "Column 3",
            "Column 4",
            "Column 5",
            "Column 6",
            "Column 7"
    };

    // Get user input
    std::cout << "What column to move the card to?" << std::endl;
    int tableauColumn = getUserInput(tableauColumnOptions) - 1;

    // Get card from waste
    Card* tempCard = reserve.topCard();
    if (tempCard == nullptr) {
        std::cout << "ERROR: Waste is empty." << std::endl;
        return;
    }

    // If successful move
    if (tableau.addCard(tableauColumn, tempCard)) {
        score += 5;
        reserve.takeCard(); // remove the card from waste
    } else {
        std::cout << "ERROR: Move not possible." << std::endl;
    }
}

void Solitaire::wasteToFoundation() {
    // Get card from waste
    Card* tempCard = reserve.topCard();
    if (tempCard == nullptr) {
        std::cout << "ERROR: Waste is empty." << std::endl;
        return;
    }

    // If successful move
    if (foundation.addCard(tempCard)) {
        reserve.takeCard(); // remove the card from waste
        score += 10;
    } else {
        std::cout << "Move not possible." << std::endl;
    }
}

void Solitaire::tableauToFoundation() {
    std::vector<std::string> tableauColumnOptions {
            "Column 1",
            "Column 2",
            "Column 3",
            "Column 4",
            "Column 5",
            "Column 6",
            "Column 7"
    };

    // Get user input
    std::cout << "What column top-card to move to the foundations?" << std::endl;
    int tableauColumn = getUserInput(tableauColumnOptions);
    if (tableauColumn == 0) {
		return; // Return if desired
	}
	tableauColumn--; // Convert to vector index

    // Back up tableau stack
    std::vector<Card*> backupStack = this->tableau.getStack(tableauColumn)->getCards();

    // Get card
    Card* tempCard = this->tableau.getStack(tableauColumn)->removeCard();
    if (tempCard == nullptr) {
        std::cout << "ERROR: Column is empty." << std::endl;
        return;
    }

    // Move tempCard onto foundation
    // If move failed
    if (! foundation.addCard(tempCard)) {
        std::cout << "ERROR: Move not possible." << std::endl;
        // Put card back
        this->tableau.getStack(tableauColumn)->addSet(backupStack);
    } else {
        score += 10;
		// Make top card visible if invisible
		if (! this->tableau.getStack(tableauColumn)->getCards().back()->getVisibility()) {
			this->tableau.getStack(tableauColumn)->getCards().back()->setVisibility(true);
			score += 5; // points for turning over Tableau card
		}
	}

}

void Solitaire::tableauMove() {
    std::vector<std::string> tableauColumnOptions {
            "Column 1",
            "Column 2",
            "Column 3",
            "Column 4",
            "Column 5",
            "Column 6",
            "Column 7"
    };

    std::cout << "Move the card(s) from what column?" << std::endl;
    int fromColumn = getUserInput(tableauColumnOptions);
    if (fromColumn == 0) {
		return; // Return if desired
	}
	fromColumn--; // Convert to vector index

    std::vector<Card*> entireColumn = this->tableau.getStack(fromColumn)->getCards(); // also backup

	// Retrieve available cards
    std::vector<std::string> cardOptions;
    int offset = 0;
    for (int index = 0; index < entireColumn.size(); index++) {
        if (entireColumn[index]->getVisibility()) { // if visible add to vector
            cardOptions.push_back(std::to_string(entireColumn[index]->getCard()));
        } else {
            offset++; // hidden cards count as extra row, but is not shown as a choice to user
        }
    }

    std::cout << "Move which card(s)? (in case of multiple cards, select uppermost)" << std::endl;
    int fromRow = getUserInput(cardOptions);
	if (fromRow == 0) {
		return; // Return if desired
	}
	fromRow += offset - 1; // Convert to vector index and add offset (amount of hidden cards)

    // Get user input
    std::cout << "What column to move the card(s) to?" << std::endl;
    int toColumn = getUserInput(tableauColumnOptions);
    if (toColumn == 0) {
		return; // Return if desired
	}
	toColumn--; // Convert to vector index

    if (!tableau.addSet(toColumn, tableau.removeSet(fromColumn, fromRow))) {
		// if move failed
        std::cout << "ERROR: Move not possible." << std::endl;
        // Put card back
        this->tableau.getStack(fromColumn)->addSet(entireColumn);
    } else { // if successful move
		// Make top card visible if invisible
		if (! this->tableau.getStack(fromColumn)->getCards().back()->getVisibility()) {
			this->tableau.getStack(fromColumn)->getCards().back()->setVisibility(true);
			score += 5; // get points for turning over tableau card
		}
	}
}
