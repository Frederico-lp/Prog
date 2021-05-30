//T08G06
#pragma once

#ifndef PROJ2_MAZE_H
#define PROJ2_MAZE_H

#include "Post.h"
using namespace std;
class Maze{

private:
    int width;
    int height;
    vector <Post> posts;
    vector <Post> harmlessPosts;
    vector <Post> exits;

public:
    Maze(int width, int height);
    int getWidth() const;
    int getHeight() const;
    void setWidth(int width);
    void setHeight(int height);
    vector<Post> getPosts();
    void addPost(Post post);
    vector<Post> getExits();
    void addExit(Post exit);
    vector<Post> getHarmlessPosts();
    void addHarmlessPost(Post post);
    bool is_outOfBounds(int x1, int y1); //returns true if outside playing area, exits are not considered playing area
};

#endif //PROJ2_MAZE_H
