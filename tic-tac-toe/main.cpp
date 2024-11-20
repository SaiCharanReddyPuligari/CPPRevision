#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    
    int boardSize;
    string PlayerOne, PlayerTwo;
    
    cout<<"Enter the board size";
    cin>> boardSize;
    
    cout<<"Enter P1";
    cin>>PlayerOne;
    
    cout<<"Enter P2";
    cin>>PlayerTwo;

    Game tictactoe(PlayerOne, PlayerTwo, boardSize);
    tictactoe.start();
    return 0;
}