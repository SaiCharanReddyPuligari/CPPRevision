#include <iostream>
using namespace std;
#include <vector>
#include "game.hpp"

int main(){
    vector<string> playerNames={"sai", "yash"};
    std::vector<std::pair<int, int>> snakes = {{17, 7}, {54, 34}};
    std::vector<std::pair<int, int>> ladders = {{62, 81}, {87, 96}};
    Game game(100, playerNames, snakes, ladders);
    game.play();
    return 0;
}