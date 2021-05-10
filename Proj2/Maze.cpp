#include "Maze.hpp"
using namespace std;

Maze::Maze(int width, int height){
    this->width = width;
    this->height = height;

}

vector* Maze::getPosts(){
    return this->posts;
}

int getWidth(){
    return this->width;
}
    
int getHeight(){
    return this->height;
}

void setWidth(int width){
    this->width = width;
}

void setHeight(int height){
    this->height = height;
}

void addPost(Post post){
    this->posts.push_back(post);
}