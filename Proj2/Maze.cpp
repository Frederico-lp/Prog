//T08G06
#include "Maze.h"

using namespace std;

Maze::Maze(int width, int height){
    this->width = width;
    this->height = height;

}

vector<Post> Maze::getPosts(){
    return this->posts;
}

vector<Post> Maze::getExits(){
    return this->exits;
}

vector<Post> Maze::getHarmlessPosts(){
    return this->harmlessPosts;
}

int Maze::getWidth() const{
    return this->width;
}

int Maze::getHeight() const{
    return this->height;
}

void Maze::setWidth(int newWidth){
    Maze::width = newWidth;
}

void Maze::setHeight(int newHeight){
    Maze::height = newHeight;
}

void Maze::addPost(Post post){
    this->posts.push_back(post);
}

void Maze::addExit(Post exit){
    this->exits.push_back(exit);
}

void Maze::addHarmlessPost(Post post){
    this->harmlessPosts.push_back(post);
}

bool Maze::is_outOfBounds(int x1, int y1) {
    if (x1==0 || x1==width || y1==0 || y1==height)
        return true;
    return false;
}
