//T08G06
#pragma once

#ifndef PROJ2_ROBOT_H
#define PROJ2_ROBOT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>

class Robot{

private:
    int x, y, id;
    bool alive;

public:
    Robot(int x, int y, int id);
    int getX() const;
    int getY() const;
    bool isAlive() const;
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    void killRobot();

};

#endif //PROJ2_ROBOT_H
