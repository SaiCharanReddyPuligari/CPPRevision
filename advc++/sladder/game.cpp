#include "game.hpp"

// Board board;
//     vector<Player> players;
//     vector<pair<int, int>> snakes;
//     vector<pair<int, int>> ladders;

Game::Game(int boardSize, vector<string> playerNames, vector<pair<int, int>> sn, vector<pair<int, int>> ld):board(boardSize){
      for(int i=0;i<playerNames.size();i++){
            //creating players
            players.push_back(Player(playerNames[i]));  //passing values to player constructor
        }

        for(int i=0;i<sn.size();i++){
            board.snakePositions.push_back(sn[i].first);
            board.snakePositions.push_back(sn[i].second);
        }

        for(int i=0;i<ld.size();i++){
            board.ladderPositions.push_back(ld[i].first);
            board.ladderPositions.push_back(ld[i].second);
        }
}

void Game:: play(){
     while(true){
        //take out the player for every while loop and rollDice
        for(int i=0;i<players.size();i++){
            int roll= players[i].rollDice(); 
            std::cout << players[i].name << " rolled a " << roll << std::endl;
            board.movePlayer(players[i], roll);
            std::cout << players[i].name << " is now on square " << players[i].position << std::endl;
            if(board.checkWinner(players[i])){
                return;
            }
        }
     }
}