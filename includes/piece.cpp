#include "piece.h"
#include <iostream>

using namespace std;


piece::piece(string identifier) : identifier(identifier) {
    determineTraits(identifier);
}

void piece::printPiece() const {
    cout << "Piece Identifier: " << identifier << endl;
    cout << "Piece length: " << length << endl;
}

int piece::getLength() {
    return length;
}
string piece::getId() {
    return identifier;
}
int piece::getHealth() {
    return hp;
}
void piece::setHealth() {
    hp--;
}

void piece::determineTraits(string identifier) {
    if (identifier == "F") {
        name = "Frigate";
        length = 2;
    } else if (identifier == "S" || identifier == "D") {
        length = 3;
        if (identifier == "S") {
            name = "Submarine";
        } else {
            name = "Destroyer";
        }
    } else if (identifier == "B") {
        name = "Battleship";
        length = 4;
    } else if (identifier == "A") {
        name = "Aircraft Carrier";
        length = 5;
    } else {
        cerr << "Invalid identifier: " << identifier << endl;
    }
    hp = length;
}