//T08G06
#pragma once

#ifndef PROJ2_PLAYER_H
#define PROJ2_PLAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>

class Player{

private:
    int x, y;
    bool alive;

public:
    Player(int x, int y);
    int getX() const;
    int getY() const;
    bool getAlive() const;
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    void setAlive(bool status);
};

#endif //PROJ2_PLAYER_H
