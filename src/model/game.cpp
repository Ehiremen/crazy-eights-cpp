#include "game.hpp"

Game::Game (int numPlayers, int sizeOfHand, vector<string>& playerNames) 
: numPlayers(numPlayers), sizeOfHand(sizeOfHand), deck(Deck(sizeOfHand)) 
{
    for (int i=1; i<=numPlayers; i++) {
        // initNewPlayer("Player " + to_string(i));
        initNewPlayer(playerNames[i-1]);
    }

    topCard = deck.popCard();

    cout << "\nGame initialized with " << players.size() << " players\n";
    cout << "Top card: " << *topCard << endl;
    cout << "-----Setup complete...-----" << endl << endl;

    summarizePlayers();
    // cout << "Before swap:\n";
    // players[0]->printHand();
    // players[0]->swapInHand(0,1);
    // cout << "\n\nAfter swap:\n";
    // players[0]->printHand();
    // for (Player*p : players) {
    //     cout << p->getName() << "'s hand: \n";
    //     p->printHand();
    //     cout << endl;
    // }

    // printHand() of each player in players
    // for (Player*p : players) {
    //     p->printHand();
    //     cout << endl;
    // }

}

// =========================================================

Game::~Game () {
    cout << "Returning play-pile to deck" << endl;
    deck.pushCards(pileInPlay);
    cout << endl;

    if (topCard) {
        delete topCard;
        cout << "Destroyed top card" << endl;
    }

    for (Player* p:players) {
        delete p;
    }
    cout << "Destroyed players in current game" << endl;
}

// =========================================================

auto Game::initNewPlayer(string name) -> void {
    vector<Card*> hand;
    deck.dealHand(hand);
    Player* p = new Player(name, hand);
    players.push_back(p);
}

// =========================================================

auto Game::summarizePlayers() -> void {
    for (Player* p:players) {
        cout << p->getName() << " has " << p->sizeOfHand()
            << " cards in hand" << endl;
    }
}

// =========================================================

auto Game::calcWinnerScore() -> int {
    int score = 0;

// loop through each player and add their score to the total
    for (Player* p:players) {
        score += p->calcHandScore();
    }

    return score;
}

// =========================================================

auto Game::run() -> void {
}