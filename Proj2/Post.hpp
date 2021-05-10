#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>
class Post
using namespace std;
    
private:
    int x, y;

public:
    Robot(int x, int y, id);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    bool isPost(int width, int height, int x, int y, vector<Post> &fences);
};