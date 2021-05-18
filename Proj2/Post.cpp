#include "Post.hpp"

Post::Post(int x, int y){
    this->x = x;
    this->y = y;
}

int Post::getX(){
    return this->x;
}

int Post::getY(){
    return this->x;
}

void Post::setX(int x){
    Post::x = x;
}

void Post::setY(int y){
    Post::y = y;
}

void Post::setPosition(int x, int y){
    Post::x = x;
    Post::y = y;
}

//mudar isto para game.


