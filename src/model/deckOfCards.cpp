#include "deckOfCards.hpp"

// provide default sizeOfHand=5 in case unspecified
Deck::Deck (int sizeOfHand=5) : sizeOfHand(sizeOfHand) {
    createDeck();
    shuffleDeck();
    cout << "New deck created with " << deck.size() << " cards\n";
}

// ==========================================================

Deck::~Deck () {
    for (Card* c: deck) {
        delete c;
    }
    cout << "Destroyed deck" << endl;
}

// ==========================================================

auto Deck::createDeck() -> void {
    for (char s: suitValues) {
        for (int n: nonFaceValues) {
            deck.push_back(new NonFaceCard(s, n));
        }
        for (char f: faceValues) {
            deck.push_back(new FaceCard(s, f));
        }
    }
    return;
} 

// ==========================================================

auto Deck::shuffleDeck() -> void {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
    return;
}

// ==========================================================

auto Deck::dealHand(vector<Card*>& hand) -> void {
    for (int i=0; i<sizeOfHand; i++) {
        hand.push_back(deck.front());
        deck.pop_front();
    }

    cout << "New hand dealt\n";
    return;
}

// ==========================================================

auto Deck::popCard() -> Card* {
    if (deck.size() == 0) {
        cerr << "Deck is empty... abnormal termination\n";
        exit(emptyDeck);
    }

    Card* out = deck.front();
    deck.pop_front();
    return out;
}

// ==========================================================

auto Deck::pushCards (deque<Card*>& d) -> void {
    if (d.size() == 0) {
        cerr << "No cards returned\n";
        return;
    }

    for (Card* c: d) {
        deck.push_back(c);
    }
    shuffleDeck();
    d.clear();

    return;
}

// ==========================================================