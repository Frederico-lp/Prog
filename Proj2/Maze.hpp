#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>
class Maze
using namespace std;
    
private:
    int width, height;
    vector <Post> posts;

public:
    Maze(int width, int height);
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHeight(int height);
    vector* getPosts();
    void addPost(Post post);
};