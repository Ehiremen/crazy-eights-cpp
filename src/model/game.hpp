#pragma once
#include "player.hpp"

enum class PlayerActions {
    pickFromDeck,
    playFromHand,
    rearrangeHand,
    showSummary
};

const map<PlayerActions, string> PlayerActionsMap = {
        { PlayerActions::pickFromDeck, "Pick a card from deck" },
    { PlayerActions::playFromHand, "Play a card from hand" },
    { PlayerActions::rearrangeHand, "Rearrange hand" },
    { PlayerActions::showSummary, "Show game summary" }
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
    bool endTurn = false;

    auto initTopCard() -> void;
    auto initNewPlayer(string name) -> void;
    auto summarizePlayers() -> void;
    auto calcWinnerScore() -> int;
    auto announceWinner() -> void;
    auto shufflePlayers() -> void;
    auto nextPlayer() -> void;
    auto pickMove() -> void;
    auto pickFromDeck() -> void;
    auto playFromHand() -> void;
    auto rearrangeHand() -> void;

public:
    Game(int numPlayers, int sizeOfHand, vector<string>& playerNames);
    ~Game();
    auto run() -> void;
};
