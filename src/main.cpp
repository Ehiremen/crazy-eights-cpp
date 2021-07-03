#include <iostream>
#include "model/game.hpp"

using namespace std;

void banner () {
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

int main (int argc, char** argv) {
    if (argc != 2) {
        cerr << "expected: crazy-eights {numPlayers}" << endl;
        return -1;
    }

    int numPlayers = atoi(argv[1]);
    if (numPlayers < 2 || numPlayers > 6) {
        cerr << "only 2 to 6 players allowed" << endl;
        return -1;
    }

    banner();
    Game* game = new Game(numPlayers);
    cout << "normal termination" << endl << endl;
    return 0;
}