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
    auto printHand() -> void {
        for (Card* c: hand) {
            cout << *c << endl;
        }
    }
    auto getName() -> string {
        return name;
    }
};