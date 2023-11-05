#include "piece.h"
#include <iostream>

class Board {
private:
    void initializeBoard();
    static const int ROWS = 10;
    static const int COLS = 10;
    static std::string board[ROWS][COLS];
    int attemptedShots = 0;
    int totalShips = 5;
    std::string status = "\n";
    int hits = 0;
    int misses = 0;
    void attemptShot(int, int);

public:
    std::string pieces[5] = {"F", "S", "D", "B", "A"};
    Board();
    void printBoard();
    static void placePiece(piece);
    bool attemptTurn();
    int getHits() const;
    int getTotalShots() const;

};