#include "Game.h"

Game:: Game(const string & player1Name, const string &Player2Name, int boardSize): player1(player1Name, 'X'), player2(Player2Name, 'O'),board(boardSize), currentPlayer(&player1), isGameOver(false){}

void Game:: start(){
    cout<<"Welcome to tic tac toe\n";
    board.display();
    while(!isGameOver){
        playTurn();
        board.display();

        if(board.checkWin(currentPlayer->getSymbol())){
            cout<<currentPlayer->getName()<<" Winds !!"<<endl;
            isGameOver=true;
        }
        else if(board.isFull()){
            cout<<"Its a draw game";
            isGameOver =true;
        }
        else{
            currentPlayer= (currentPlayer ==&player1) ?&player2: &player1;
        }
    }
}

void Game:: playTurn(){
    int row, col;
    cout<<currentPlayer->getName()<<"'s Turn. Enter row and column (0-based)";
    cin>>row>>col;

    while(!board.placeMove(row,col, currentPlayer->getSymbol())){
        cout<<"Invalid mode, Try again please";
        cin>>row>>col;
    }
}

bool Game:: isDraw(){
    return board.isFull() && !board.checkWin(player1.getSymbol() && !board.checkWin(player2.getSymbol()));
}