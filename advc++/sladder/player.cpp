#include "player.hpp"
#include <random>

Player:: Player(string _name) {
    name=_name;
    position=0;
    moves=0;
}

int Player::rollDice(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

void Player::move(int spaces){
    position+=spaces;
    moves++;
}