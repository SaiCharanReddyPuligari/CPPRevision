#include "board.hpp"

Board :: Board(int s){
    size=s;
}

void Board:: movePlayer(Player &p, int roll){
    int newPos=p.position + roll;

    if(newPos > size) return;

    for(int i=0;i<ladderPositions.size();i+=2){
        if (newPos == ladderPositions[i]) {
            newPos = ladderPositions[i + 1];
            break;
        }
    }

    for (int i = 0; i < snakePositions.size(); i += 2) {
        if (newPos == snakePositions[i]) {
            newPos = snakePositions[i + 1];
              break;
        }
    }

    p.position = newPos;
}

bool Board:: checkWinner(Player &p){
    if(p.position == size){
        cout<<p.name <<"Won"<<endl;
        return true;
    }
    return false;
}