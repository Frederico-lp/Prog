#include "Maze.hpp"
using namespace std;

Maze::Maze(int width, int height){
    this->width = width;
    this->height = height;
    vector<Post> posts;

}

vector<Post> Maze::getPosts(){
    return this->posts;
}

int Maze::getWidth(){
    return this->width;
}
    
int Maze::getHeight(){
    return this->height;
}

void Maze::setWidth(int width){
    Maze::width = width;
}

void Maze::setHeight(int height){
    Maze::height = height;
}

void Maze::addPost(Post post){
    this->posts.push_back(post);
}
