#include "Player.h"
using namespace std;

Player::Player(const string& playerName, char playerSymbol) : name(playerName), symbol(playerSymbol){}

string Player:: getName() const{
    return name;
}

char Player:: getSymbol() const{
    return symbol;
}