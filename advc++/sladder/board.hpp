#include <bits/stdc++.h>
using namespace std;
#include "player.hpp"

class Board{
    public:
    int size;
    vector<int> playerPositions;
    vector<int> snakePositions;
    vector<int> ladderPositions;
    Board(int s);
    void movePlayer(Player &p, int roll);
    bool checkWinner(Player &p);
    
};