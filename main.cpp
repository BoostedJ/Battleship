#include "includes/board.h"
#include "includes/menu.h"
#include "includes/highscores.h"
using namespace std;

int calculateScore(int hits, int totalHits) {
    int hitPercentage = (hits * 100) / totalHits;
    return (hitPercentage * 1000 / 100);
}

bool gameLoop(Board board) {
    bool playing = true;
    board.printBoard();
    while(playing) {
        playing = board.attemptTurn();
        if(playing) {
            board.printBoard();
        } else {
            cout << "Thanks for playing!\n";
            playing = false;
        }
    }

    if (!playing) {
        int score = calculateScore(board.getHits(), board.getTotalShots());
        cout << "Your score is: " << score << "!" << endl;

        string name;
        do {
            cout << "Enter a 3-character name to save your score: ";
            cin >> name;
        } while (name.length() != 3);
        Highscores highscores;
        highscores.saveScore(name, score);
        vector<pair<string, int>> topScores = highscores.getTopScores();
        highscores.displayHighscores(topScores);
    }

    char again ='Y';
    cout << R"(Want to play again? ('Y'/'N'): )";
    cin >> again;
    if (toupper(again) == 'Y') {
        return true;
    } else {
        return false;
    }
}

Board setup() {
    Board board;
    for(const auto& i : board.pieces) {
        piece currPiece = piece(i);
        board.placePiece(currPiece);
    }
    return board;
}

int main() {
    Menu menu;
    bool replay = menu.displayMenu();
    while(replay) {
        Board board = setup();
        replay = gameLoop(board);
    }
}