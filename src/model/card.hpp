#pragma once
#include <string>
#include "errors.hpp"

using namespace std;

enum suits {spades, hearts, diamonds, clubs};
const char suitValues[] = {'S', 'H', 'D', 'C'};

enum faces {J, Q, K, A};
const char faceValues[] = {'J', 'Q', 'K', 'A'};

const int nonFaceValues[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

struct Card {
    char suit;
    bool isFace;
    union {
        int value;
        char face;
    };

    bool operator == (Card& c) {
        if (suit != c.suit) return false;
        if (isFace != c.isFace) return false;
        if (isFace) {
            if (face != c.face) return false;
        }
        else {
            if (value != c.value) return false;
        }
        return true;
    }
};