//T08G06
#include "Post.h"

Post::Post(int x, int y){
    this->x = x;
    this->y = y;
}

int Post::getX() const{
    return this->x;
}

int Post::getY() const{
    return this->y;
}

void Post::setX(int newX){
    Post::x = newX;
}

void Post::setY(int newY){
    Post::y = newY;
}

void Post::setPosition(int newX, int newY){
    Post::x = newX;
    Post::y = newY;
}

//mudar isto para game.
