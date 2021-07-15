#pragma once

#include "card.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Deck {
private:
    int sizeOfHand;
    deque<Card*> deck;

    auto createDeck() -> void;
    auto shuffleDeck() -> void;

public:
    Deck (int sizeOfHand=5);
    ~Deck ();
    
    auto dealHand(vector<Card*>& hand) -> void;
    auto popCard() -> Card*; // remove from top
    auto pushCards (deque<Card*>& d) -> void; // add to bottom
};