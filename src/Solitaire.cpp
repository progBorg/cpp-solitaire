#include <iostream>
#include <algorithm>
#include <random>
#include "Solitaire.h"
using namespace std;

// ------------ Constructor ------------
// Create game and initialize foundation, tableau and reserve
Solitaire::Solitaire(vector<Card*> tableauCards, vector<Card*> reserveCards) :
		foundation(),
		tableau(tableauCards),
		reserve(reserveCards)
{

}

/**
 * Generate all cards and return them randomly shuffled
 */
vector<Card*> Solitaire::generateCards() {
	// Get all card values and suits
	int values[13] = {Card::ACE, Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN,
			Card::JACK, Card::QUEEN, Card::KING};
	int suits[4] = {Card::HEARTS, Card::SPADES, Card::DIAMONDS, Card::CLUBS};

	// Generate all cards
	vector<Card*> gameCards;
	gameCards.reserve(52); // Reserve space in advance
	for (int suit = 0; suit < 4; suit++) {
		for (int value = 0; value < 13; value++) {
			// Generate current card in place and add it to the vector
			Card tempCard(suits[suit], values[value]);
			Card* tempCardPointer = &tempCard;
			gameCards.push_back(tempCardPointer);
		}
	}

	// shuffle cards
	auto rng = default_random_engine {};
	shuffle(begin(gameCards), end(gameCards), rng);

	return gameCards;
}

// ------------ Commands ------------
/**
 * Run the game
 */
void Solitaire::run() {
	cout << "Welcome to Solitaire!" << endl;

	return;
}
