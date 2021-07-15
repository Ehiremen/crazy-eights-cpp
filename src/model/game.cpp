#include "game.hpp"

Game::Game (int numPlayers, int sizeOfHand) : numPlayers(numPlayers), sizeOfHand(sizeOfHand), deck(Deck(sizeOfHand)) 
{
    for (int i=1; i<=numPlayers; i++) {
        initNewPlayer("Player " + to_string(i));
    }

    cout << "Game initialized with " << players.size() << " players\n";
    cout << "-----Setup complete...-----" << endl << endl;

    // for (Player*p : players) {
    //     cout << p->getName() << "'s hand: \n";
    //     p->printHand();
    //     cout << endl;
    // }
}

// =========================================================

Game::~Game () {
    deck.pushCards(pileInPlay);

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
