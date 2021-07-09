#pragma once
#include "player.hpp"

class Game{
private:
    int numPlayers;
    int sizeOfHand;
    Deck deck;
    vector<Player*> players;
    deque<Card*> pileInPlay;
    Card* topCard;
    auto initNewPlayer(string name) -> void;

public:
    Game(int numPlayers, int sizeOfHand);
    ~Game();
};
