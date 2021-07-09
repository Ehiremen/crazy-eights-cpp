#pragma once
 #include "deckOfCards.hpp"

 using namespace std;

 class Player {
private:
    string name;
    vector<Card*> hand;

public:
    Player(string name, vector<Card*> hand);
    ~Player();
};