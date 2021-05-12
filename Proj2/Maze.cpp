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

int getWidth(){
    return this->width;
}
    
int getHeight(){
    return this->height;
}

void setWidth(int width){
    Maze::width = width;
}

void setHeight(int height){
    Maze::height = height;
}

void addPost(Post post){
    this->posts.push_back(post);
}
