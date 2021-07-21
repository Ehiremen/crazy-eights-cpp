#include "game.hpp"

Game::Game (int numPlayers, int sizeOfHand, vector<string>& playerNames) 
: numPlayers(numPlayers), sizeOfHand(sizeOfHand), deck(Deck(sizeOfHand)) 
{
    for (int i=1; i<=numPlayers; i++) {
        // initNewPlayer("Player " + to_string(i));
        initNewPlayer(playerNames[i-1]);
    }

    initTopCard();
    shufflePlayers();
    currentPlayerIterator = players.begin();

    cout << "\nGame initialized with " << players.size() << " players\n";
    cout << "Player order is: ";
    for (Player* p : players) { cout << p->getName() << " -> "; }
    cout << "\nTop card: " << *topCard << endl;
    cout << "-----Setup complete...-----" << endl << endl;

    run();
}
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

    // printHand() of each player in players
    // for (Player*p : players) {
    //     p->printHand();
    //     cout << endl;
    // }

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

auto Game::summarizePlayers() -> void {
    for (Player* p:players) {
        cout << p->getName() << " has " << p->sizeOfHand()
            << " cards in hand" << endl;
    }
}

// =========================================================

auto Game::calcWinnerScore() -> int {
    int score = 0;

// loop through each player and add their score to the total
    for (Player* p:players) {
        score += p->calcHandScore();
    }

    return score;
}

// =========================================================

auto Game::shufflePlayers() -> void {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(players.begin(), players.end(), default_random_engine(seed));
}

// =========================================================

auto Game::initTopCard() -> void {
    topCard = deck.popCard();
    deque<Card*> returnToDeck;

    while (topCard->isEight()) {
        returnToDeck.push_back(topCard);
        topCard = deck.popCard();
    }

    if (!returnToDeck.empty()) { deck.pushCards(returnToDeck); }
}

// ========================================================

auto Game::nextPlayer() -> void {
    currentPlayerIterator++;
    if (currentPlayerIterator == players.end()) {
        currentPlayerIterator = players.begin();
    }
}

// ========================================================

auto Game::pickMove() -> void {
    int choice = -1;
    do {
        cout << "Pick a move: \n";
        for (pair<PlayerActions, string> p:PlayerActionsMap) {
            cout << int(p.first) << ". " << p.second << endl;
        }
        cout << "Choice: ";
        cin >> choice;

        if (choice < 0 || choice > 3) { cout << "Please retry ..." << endl << endl; }
        else { cout << endl; }
    } while (choice < 0 || choice > 3);

    switch (choice) {
        case int(PlayerActions::pickFromDeck): pickFromDeck(); break;
        case int(PlayerActions::playFromHand): playFromHand(); break;
        case int(PlayerActions::rearrangeHand): rearrangeHand(); break;
        case int(PlayerActions::showSummary): summarizePlayers(); break;
    }

}

// ========================================================

auto Game::pickFromDeck() -> void {
    (*currentPlayerIterator)->addCardToHand(deck.popCard());
    (*currentPlayerIterator)->printHand();
}

// ========================================================

auto Game::playFromHand() -> void {
    
    endTurn = true;
}

// ========================================================

auto Game::rearrangeHand() -> void {
    int card1, card2;

    (*currentPlayerIterator)->printHand();

    cout << "Choose two cards to swap: ";
    cin >> card1 >> card2;
    (*currentPlayerIterator)->swapInHand(card1, card2);
    (*currentPlayerIterator)->printHand();

}

// ========================================================

auto Game::run() -> void {
    for (;;) {
        if (pileInPlay.size() > deck.size()) { deck.pushCards(pileInPlay); }
        endTurn = false;
        while (!endTurn) {
            pickMove();
        }

        if ((*currentPlayerIterator)->handIsEmpty()) {
            announceWinner();
            return;
        }

        nextPlayer();
    }
    pickMove();
}

// ========================================================

auto Game::announceWinner() -> void {
    int score = calcWinnerScore();

    cout << "Game over!\n";
    cout << (*currentPlayerIterator)->getName() << " wins with a score of " << score << endl;
    cout << "-----Game Over-----\n\n" << endl;
}