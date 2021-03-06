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
    cout << "Destroyed " << name << "'s hand" << endl;
}

// ==========================================================

auto Player::printHand() -> void {
    int index = 0;
    cout << name << "'s hand: " << endl;
    for (Card* c: hand) {
        cout << setw(2) << index << ". " << *c << endl;
        index++;
    }
}

// ==========================================================

auto Player::swapInHand(int i, int j) -> void {
    // only swap if both i and j are valid indices in hand
    if (validateIndex(i) && validateIndex(j)) {
        swap(hand[i], hand[j]);
    }
    else {
        cout << "Invalid indexes selected" << endl;
    }
}

// ==========================================================

auto Player::validateIndex(int index) -> bool {
    if (index < 0) return false;
    if (index >= hand.size()) return false;
    return true;
}

// ==========================================================

auto Player::calcHandScore() -> int {
    int score = 0;

    for (Card* c:hand) {
        score += c->getScoreValue();
    }
    
    return score;
}

// ==========================================================

auto Player::addCardToHand(Card* card) -> void {
    hand.push_back(card);
}