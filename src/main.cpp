#include <iostream>
#include "model/game.hpp"
#include "model/deckOfCards.hpp"
#include "model/player.hpp"

using namespace std;

auto banner () -> void ;

// =========================================================

auto main (int argc, char** argv) -> int {
    if (argc < 2) {
        cerr << "expected: crazy-eights {numPlayers} {space-separated-playerNames}" << endl;
        return badArgCount;
    }

    /*  atoi() doesn't throw exceptions, so I'm "validating"
        by checking if the value falls within an arbitrary
        range 
    */

    int numPlayers = 0; numPlayers = atoi(argv[1]);
    if (numPlayers < 2 || numPlayers > 5) {
        cerr << "only 2 to 5 players allowed" << endl;
        return badNumPlayers;
    }
    int sizeOfHand = (numPlayers == 2) ? 7 : 5;

    // validate that argc is correct
        if (argc != 2 + numPlayers) {
        cerr << "expected: crazy-eights {numPlayers} ";
        for (int i=1; i<=numPlayers; i++) {
            cerr << "{name" << i << "} ";
        }
        cerr << endl;
        return badNumPlayerNames;
    }

    // store playerNames in a vector of strings
    vector<string> playerNames;
    for (int i = 2; i < argc; i++) {
        playerNames.push_back(argv[i]);
    }

    banner();
    Game game(numPlayers, sizeOfHand, playerNames);
    // Deck d(sizeOfHand);
    cout << "normal termination" << endl << endl;
    return 0;
}

// =========================================================

auto banner () -> void {
    cout << endl << endl << " ";
    for (int i=0; i<30; i++) cout << "-";
    // cout << endl << "|" << "|";
    printf("\n|%31s", "|");
    printf("\n|%31s", "|");
    printf("\n%-9s%s%11s", "|", "CRAZY EIGHTS", "|");
    printf("\n|%31s", "|");
    printf("\n|%31s\n ", "|");
    for (int i=0; i<30; i++) cout << "-";
    cout << endl << endl << endl;
}