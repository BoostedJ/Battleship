#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string Board::board[Board::ROWS][Board::COLS];

Board::Board() {
    srand(time(0));
    initializeBoard();
}
void Board::initializeBoard() {
    for (auto & row : board) {
        for (auto & col : row) {
            col = "[ ]";
        }
    }
}
void Board::printBoard() {
    cout << "   1  2  3  4  5  6  7  8  9  10\n";
    for (int row = 0; row < ROWS; row++) {
        cout << char('A' + row) << " ";
        for (int col = 0; col < COLS; col++) {
            if (board[col][row] != "[ ]" && board[col][row] != "[X]" && board[col][row] != "[O]") {
                cout << "[ ]";
            } else {
                cout << board[col][row];
            }
        }
        cout << endl;
    }
    cout << status << "Legend:      Attempted shots:  " << attemptedShots << endl <<
                    "O - Miss     Misses remaining: " << 15-misses << endl <<
                    "X - Hit      Ships remaining:  " << totalShips << endl;
}
void Board::placePiece(piece piece) {
    bool placed = false;

    while (!placed) {
        int selR = rand() % ROWS;
        int selC = rand() % COLS;
        int horizontal = rand() % 2;

        bool canPlace = true;

        for (int i = 0; i < piece.getLength(); i++) {
            int row = selR + (horizontal == 1 ? 0 : i);
            int col = selC + (horizontal == 1 ? i : 0);

            if (row >= ROWS || col >= COLS || board[row][col] != "[ ]") {
                canPlace = false;
                break;
            }
        }

        if (canPlace) {
            for (int i = 0; i < piece.getLength(); i++) {
                int row = selR + (horizontal == 1 ? 0 : i);
                int col = selC + (horizontal == 1 ? i : 0);
                board[row][col] = "[" + piece.getId() + "]";
            }
            placed = true;
        }
    }
}
bool Board::attemptTurn() {
    if(hits == 17) {
        cout << "You've won!\n";
        return false;
    } else if (misses == 15) {
        cout << "Sorry, you've lost...\n";
        return false;
    }

    string input;
    cout << "Please enter a shot (e.g., A5) or 'quit' to exit: ";
    cin >> input;
    if (input == "quit" || input == "Q" || input == "q") {
        return false;
    }
    char cCol = toupper(input[0]);
    string sRow = input.substr(1);
    if (isdigit(input[0])) {
        sRow = input.substr(0, input.size()-1);
        cCol = toupper(input.back());
    }

    int rowInput;
    try {
        rowInput = stoi(sRow);
    } catch(...) {
        status = "Please enter valid rows and columns! Try again!\n";
        return true;
    }

    rowInput--;
    if (rowInput < 0 || rowInput >= ROWS || cCol < 'A' || cCol > 'J') {
        status = "Please enter valid rows and columns! Try again!\n";
        return true;
    }

    attemptShot(rowInput, cCol);
    return true;
}
void Board::attemptShot(int row, int col) {
    int colIndex = col - 'A';
    if (board[row][colIndex] == "[ ]") {
        status = "  ######## It's a miss #########\n";
        misses++;
        attemptedShots++;
        board[row][colIndex] = "[O]";
    } else if (board[row][colIndex] == "[X]" || board[row][colIndex] == "[O]") {
        status = "  You've already hit this spot! Try again!\n";
    }
    else {
        for (int i = 0; i < size(pieces); i++) {
            piece currPiece = piece(pieces[i]);
            if (board[row][colIndex] == "[" + currPiece.getId() + "]") {
                status = "  ######## It's a hit! #########\n";
                hits++;
                attemptedShots++;
                misses = 0;
                board[row][colIndex] = "[X]";
                int count = 0;
                for (auto & r : board) {
                    for (auto & c : r) {
                        if (c == "[" + currPiece.getId() + "]") {
                            count++;
                            break;
                        }

                    }
                }
                if (count == 0) {
                    status.append("  ######## " + currPiece.name + " has been sunk! ########\n");
                    totalShips--;
                }
            }
        }
    }
}
int Board::getHits() const {
    return hits;
}
int Board::getTotalShots() const {
    return attemptedShots;
}