#include "player.hpp"

Player::Player(string name, vector<Card*> hand) 
        : name(name), hand(hand) 
{

    cout << "Created new player: " << name << endl;
}

// ==========================================================

Player::~Player() {
    for (Card* c: hand) {
        delete c;
    }
}