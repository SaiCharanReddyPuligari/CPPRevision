#include "Board.h"

#include<bits/stdc++.h>
using namespace std;

Board:: Board(int n): size(n), board(n, vector<char>(n,' ')){ }

void Board:: display(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<" "<<board[i][j];
            if(j<size-1) cout<<" | ";
        }
        cout<<endl;
        if(i<size-1){
            for(int j=0;j<size;j++){
                 cout<<"----";
            }
            cout<<endl;
        }
    }
}

bool Board:: isFull(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]==' ') return false;
        }
    }
    return true;
}

bool Board:: placeMove(int row, int col, char symbol){
     if(row<0 || row>=size || col<0 || col>=size || board[row][col]!=' '){
        return false;
     }
     board[row][col]=symbol;
     return true;
}

bool Board:: checkWin(char symbol){
     for(int i=0;i<size;i++){
        bool rowWin=true;
        bool colWin=true;
        for(int j=0;j<size;j++){
            if(board[i][j]!=symbol){
                rowWin= false;
            }
            if(board[j][i]!=symbol){
                colWin=false;
            }
        }
        if(rowWin || colWin) return true;

        
    }
    //diagnols
    bool mainDiganolWin=true;
        bool antiDiagnolWin=true;
        for(int j=0;j<size;j++){
            if(board[j][j]!=symbol){
                mainDiganolWin= false;
            }
            if(board[j][size-j-1]!=symbol){
                antiDiagnolWin=false;
            }
        }
        if(mainDiganolWin || antiDiagnolWin) return true;
    
    return false;
}