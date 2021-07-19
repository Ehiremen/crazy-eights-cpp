#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "errors.hpp"

using namespace std;

const char suitValues[] = {'S', 'H', 'D', 'C'};
const char faceValues[] = {'J', 'Q', 'K', 'A'};
const int nonFaceValues[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const map<char, int> faceToInt = { 
        {'A', 1}, {'J', 11}, {'Q', 12}, {'K', 13}
    };

// ==========================================================

class Card {
protected:
    char suit;
    int value;
    bool isFace;
    int scoreValue;
    stringstream asString;

public:
    Card(char suit, int value, bool isFace = false) : suit(suit), isFace(isFace) { 
        if (!isFace) {
            asString << value << " of " << suit;
        }
    }
    
    ~Card() = default;
    
    auto toString() -> string { return asString.str(); }
    
    // auto getValue() -> int { return value; }

    // auto getSuit() -> char { return suit; }
    
    auto getScoreValue() -> int { 
        if (value == 8) return 50;
        if (value >= 10) return 10;
        return value;
    }

    auto valuesMatch(Card& c) -> bool { return value == c.value; }
    
    auto suitsMatch(Card& c) -> bool { return suit == c.suit; }
    
    // auto operator == (Card& c) -> bool { return toString() == c.toString(); }
    
};

inline ostream& operator << (ostream& out, Card& c) {
    out << c.toString();
    return out;
}

// ==========================================================

class FaceCard: public Card {
private:
    char face;

public:
    FaceCard(char suit, char face) : Card(suit, faceToInt.at(face), true), face(face) { 
        asString << face << " of " << suit;
    } 
    
    ~FaceCard() = default;
    
    // auto getFace() -> char { return face; }
};

// ==========================================================