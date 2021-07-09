#include <iostream>
#include "model/game.hpp"
#include "model/deckOfCards.hpp"
#include "model/player.hpp"

using namespace std;

auto banner () -> void ;

// =========================================================

auto main (int argc, char** argv) -> int {
    if (argc != 3) {
        cerr << "expected: crazy-eights {numPlayers} {sizeOfPlayerHand}" << endl;
        return badArgCount;
    }

    /*  atoi() doesn't throw exceptions, so I'm "validating"
        by checking if the value falls within an arbitrary
        range 
    */

    int numPlayers = 0; numPlayers = atoi(argv[1]);
    if (numPlayers < 2 || numPlayers > 6) {
        cerr << "only 2 to 6 players allowed" << endl;
        return badNumPlayers;
    }

    int sizeOfHand = 0; sizeOfHand = atoi(argv[2]);
    if (sizeOfHand < 5 || (sizeOfHand*numPlayers > 30)) {
        cerr << "size of hand must be between 5 and " << (30/numPlayers) << endl;
        return badHandSize;
    }

    banner();
    Game game(numPlayers, sizeOfHand);
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