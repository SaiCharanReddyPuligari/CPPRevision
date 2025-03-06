#include <iostream>
using namespace std;
#include "board.hpp"

class Game{
    public:
    Board board;
    vector<Player> players;
    vector<pair<int, int>> snakes;
    vector<pair<int, int>> ladders;

    Game(int boardSize, vector<string> playerNames,vector<pair<int, int>> sn, vector<pair<int, int>> la);
    void play();
};