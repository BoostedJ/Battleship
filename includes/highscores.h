#include <string>
#include <vector>
using namespace std;

class Highscores {
private:
    bool fileExists(const string&);
    void createFile();
    void writeFile(const string&, int);

public:
    void saveScore(const string&, int);
    vector<pair<string, int>> readFile();
    vector<pair<string, int>> getTopScores();
    void displayHighscores(const vector<pair<string, int>>& highScores);
};