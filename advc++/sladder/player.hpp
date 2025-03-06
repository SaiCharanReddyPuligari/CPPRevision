#include <bits/stdc++.h>
using namespace std;

class Player{
    public:
    string name;
    int position;
    int moves;
    Player(string _name);
    int rollDice();
    void move(int spaces);
};