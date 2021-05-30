//T08G06
#include "Player.h"

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
    alive = true;
}

int Player::getX() const{
    return this->x;
}

int Player::getY() const{
    return this->y;
}

bool Player::getAlive() const {
    return alive;
}

void Player::setX(int newX){
    Player::x = newX;
}

void Player::setY(int newY){
    Player::y = newY;
}

void Player::setPosition(int newX, int newY){
    Player::x = newX;
    Player::y = newY;
}

void Player::setAlive(bool status) {
    alive = status;
}

