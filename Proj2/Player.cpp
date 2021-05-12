#include "Player.hpp"

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
}

int Player::getX(){
    return this->x;
}

int Player::getY(){
    return this->x;
}

void Player::setX(int x){
    Player::x = x;
}

void Player::setY(int y){
    Player::y = y;
}

void Player::setPosition(int x, int y){
    Player::x = x;
    Player::y = y;
}

bool Player::is_player(int x, int y){
    if(x == this->x && y == this->y)
        return true;

    return false;

}


