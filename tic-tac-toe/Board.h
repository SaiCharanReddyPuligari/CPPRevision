#ifndef Board_H
#define Board_H

#include<bits/stdc++.h>
using namespace std;

class Board{
    private:
    int size;
    vector<vector<char>> board;

    public:
    Board(int size);
    void display();
    bool isFull();
    bool placeMove(int row, int col, char symbol);
    bool checkWin(char symbol);
};
#endif