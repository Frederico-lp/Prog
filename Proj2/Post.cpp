#include "Post.hpp"

Post::Post(int x, int y){
    this->x = x;
    this->y = y;
}

int Post::getX(){
    return this->x;
}

int Post::getX(){
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


bool Player::isPost(int width, int height, int x, int y, vector<Post> &fences){
    if(x == 0 || x = width || y == 0 || y == height)
        return true;

    else {
        for(int i = 0; i < fences.size(); i++){
            if(x == fences.at(i).getX() && y == fences.at(i).getY())
                return true;
        }
    }
    
    return false;

}

