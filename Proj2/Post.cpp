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
bool Post::isPost(int width, int height, int x, int y, std::vector<Post> &posts){
    if(x == 0 || x == width || y == 0 || y == height)
        return true;

    else {
        for(int i = 0; i < posts.size(); i++){
            if(x == posts.at(i).getX() && y == posts.at(i).getY())
                return true;
        }
    }
    
    return false;

}

