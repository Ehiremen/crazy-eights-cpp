#pragma once
#include <utility>
#include <iomanip>
 #include "deckOfCards.hpp"

 using namespace std;

 class Player {
private:
    string name;
    vector<Card*> hand;

public:
    Player(string name, vector<Card*> hand);
    ~Player();
    auto printHand() -> void;
    auto getName() -> string { return name; }
    auto swapInHand(int i, int j) -> void;
    auto validateIndex(int index) -> bool;
    auto sizeOfHand() -> int { return hand.size(); }
    auto calcHandScore() -> int;
    auto addCardToHand(Card* card) -> void;
    auto handIsEmpty() -> bool { return hand.empty(); }
};