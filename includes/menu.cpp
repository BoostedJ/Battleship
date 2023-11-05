#include "menu.h"
#include "highscores.h"
#include <limits>
#include <iostream>
using namespace std;

bool Menu::displayMenu() {
    while(true) {
        cout << "=============================" << endl;
        cout << "         BATTLESHIP" << endl;
        cout << "=============================" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. High Scores" << endl;
        cout << "4. Quit" << endl;
        cout << "=============================" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        // discards the amount of characters in choice, as it is giving error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail()) {
            cin.clear();
            cout << "Please enter a number between 1-4. \n";
            continue;
        }

        switch (choice) {
            case 1:
                return true;
                break;
            case 2:
                instructions();
                break;
            case 3:
                highScores();
                break;
            case 4:
                cout << "Thank you for your time! Have a nice day!";
                return false;
            default:
                cout << "Please enter a number between 1-4.\n";
                choice = -1;
                break;
        }
    }
}

void Menu::instructions() {
    cout << "\n\nWelcome to Battleship!\n"
                 "Outlined below are the basic rules and controls for the game:\n"
                 "=============================" << endl <<
              "         CONTROLS" << endl <<
              "=============================" << endl <<
              "1. Coordinate System:\n"
              "   - Battleship uses a coordinate system for targeting.\n"
              "   - Rows are labeled with numbers (1-10), and columns with letters (A-J).\n"
              "   - To target a cell, input the row and column (e.g., '2A').\n\n"
              "=============================" << endl <<
              "         RULES" << endl <<
              "=============================" << endl <<
              "2. Game Rules:\n"
              "   - You are playing against the computer, trying to sink each other's ships.\n"
              "   - The computer has its fleet hidden on the board.\n"
              "   - Take turns firing shots at the opponent's board to sink their ships.\n\n"
              "3. Scoring:\n"
              "   - Points are awarded based on the number of shots required to sink the opponent's fleet.\n"
              "   - Achieve the highest score by sinking the opponent's fleet with the fewest shots.\n\n"
              "4. Game Objective:\n"
              "   - Your goal is to locate and sink all of the computer's ships before 15 consecutive misses.\n"
              "   - If you miss 15 times in a row, the enemy will consolidate and sink you, ending the game, so use your shots wisely!\n"
              "=============================" << endl <<
              "    MENU OPTIONS" << endl <<
              "=============================" << endl <<
              "5. Menu Options:\n"
              "   - In-game menu options include starting a new game, viewing high scores, and quitting.\n\n"
              "6. Good Luck and Have Fun!\n"
              "   - May the best strategist win! Enjoy the game and have fun playing Battleship!\n"
              "=============================" << endl;
    cout << "Please press Enter or any key to continue..." << endl;
    string io;
    getline(cin, io);
}

void Menu::highScores() {
    Highscores highscores;
    vector<pair<string, int>> topScores = highscores.getTopScores();

    if (topScores.empty()) {
        cout << "\nNo high scores available yet!\n";
    } else {
        highscores.displayHighscores(topScores);
    }

    cout << "Please press Enter or any key to continue..." << endl;
    string io;
    getline(cin, io);
}

