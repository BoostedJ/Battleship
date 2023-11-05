#include <string>

class piece {
public:
    piece(std::string identifier);
    void printPiece() const;
    int getLength();
    std::string getId();
    std::string name;
    int getHealth();
    void setHealth();

private:
    std::string identifier;
    int length;
    int hp;
    void determineTraits(std::string identifier);
};