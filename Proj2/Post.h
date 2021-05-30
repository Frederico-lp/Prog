//T08G06
#pragma once

#ifndef PROJ2_POST_H
#define PROJ2_POST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
class Post{

private:
    int x, y;

public:
    Post(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
};

#endif //PROJ2_POST_H
