#include "game.hpp"

Game::Game (int numPlayers, int sizeOfHand) : numPlayers(numPlayers), 
sizeOfHand(sizeOfHand), deck(Deck(sizeOfHand)) 
{
    for (int i=1; i<=numPlayers; i++) {
        initNewPlayer("Player " + to_string(i));
    }

    topCard = deck.popCard();

    cout << "\nGame initialized with " << players.size() << " players\n";
    cout << "Top card: " << *topCard << endl;
    cout << "-----Setup complete...-----" << endl << endl;

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
