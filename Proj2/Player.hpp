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

public:
    Player(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    bool isPlayer(int x, int y);
};