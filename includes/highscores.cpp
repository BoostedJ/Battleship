#include "highscores.h"
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

// checks for file exist
bool Highscores::fileExists(const string& filename) {
    ifstream file(filename.c_str());
    return file.good();
}

// create file and create default player
void Highscores::createFile() {
    ofstream highScoresFile("highscores.txt");
    if (highScoresFile.is_open()) {
        highScoresFile << "Player1 0\n";
        highScoresFile.close();
    } else {
        cerr << "Failed to create high scores file." << endl;
    }
}

//basic file reader
vector<pair<string, int>> Highscores::readFile() {
    vector<pair<string, int>> highScores;
    if (!fileExists("highscores.txt")) {
        createFile();
    }
    ifstream highScoresFile("highscores.txt");
    if (highScoresFile.is_open()) {
        string username;
        int score;
        while (highScoresFile >> username >> score) {
            highScores.emplace_back(username, score);
        }
        highScoresFile.close();
    } else {
        std::cerr << "Failed to read high scores from file." << endl;
    }
    return highScores;
}

void Highscores::writeFile(const string& username, int score) {
    vector<pair<string, int>> highScores = readFile();

    bool nameExists = false;
    for (auto& entry : highScores) {
        if (entry.first == username) {
            nameExists = true;
            if (score > entry.second) {
                entry.second = score;
            }
        }
        break;
    }
    if (!nameExists) {
        highScores.push_back({username, score});
    }
    ofstream outFile;
    outFile.open("highscores.txt");
    for (const auto& entry : highScores) {
        outFile << entry.first << " " << entry.second << endl;
    }
    outFile.close();
}
void Highscores::saveScore(const string& name, int score) {
    writeFile(name, score);
}
vector<pair<string, int>> Highscores::getTopScores() {
    vector<pair<string, int>> highScores = readFile();
    // sort scores in descending order
    sort(highScores.begin(), highScores.end(),
         // lambda expression which takes a, b and sorts depending on if a is greater than or less than
         [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    // cuts any scores past 5 scores
    if (highScores.size() > 5) {
        highScores.resize(5);
    }

    return highScores;
}
void Highscores::displayHighscores(const vector<pair<string, int>>& highScores) {
    cout << "\n\n======= Highscores =======\n";
    for (const auto& entry : highScores) {
        cout << entry.first << ": " << entry.second << endl;
    }
    cout << "==========================" << endl;
}
