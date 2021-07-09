#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "errors.hpp"

using namespace std;

const char suitValues[] = {'S', 'H', 'D', 'C'};
const char faceValues[] = {'J', 'Q', 'K', 'A'};
const int nonFaceValues[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

class Card {
    protected:
    char suit;
    bool isFace;
    stringstream asString;

    public:
    Card(char suit, bool isFace) : suit(suit), isFace(isFace) { }
    ~Card() { }
    string toString() { return asString.str(); }
    
    bool operator == (Card& c) {
        return toString() == c.toString();
    }
    
};

inline ostream& operator << (ostream& out, Card& c) {
    out << c.toString();
    return out;
}

class FaceCard: public Card {
    private:
    char value;

    public:
    FaceCard(char suit, char value) : Card(suit, true), value(value) { 
        asString << value << " of " << suit;
    } 
    ~FaceCard();
    char getValue() { return value; }
    
};

class NonFaceCard: public Card {
    private:
    int value;

    public:
    NonFaceCard(char suit, int value) : Card(suit, false), value(value) { 
        asString << value << " of " << suit;
    } 
    ~NonFaceCard();
    int getValue() { return value; }
};