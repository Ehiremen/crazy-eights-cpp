#pragma once
#include "player.hpp"

enum class PlayerActions {
    pickFromDeck,
    playFromHand,
    rearrangeHand,
    showSummary
};

class Game{
private:
    int numPlayers;
    int sizeOfHand;
    Deck deck;
    vector<Player*> players;
    deque<Card*> pileInPlay;
    Card* topCard;
    vector<Player*>::iterator currentPlayerIterator;

    auto initTopCard() -> void;
    auto initNewPlayer(string name) -> void;
    auto summarizePlayers() -> void;
    auto calcWinnerScore() -> int;
    auto shufflePlayers() -> void;
    auto nextPlayer() -> void;

public:
    Game(int numPlayers, int sizeOfHand, vector<string>& playerNames);
    ~Game();
    auto run() -> void;
};
