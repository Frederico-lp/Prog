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
    int getX();
    int getY();
    bool isAlive();
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);
    void killRobot();
    int isRobot(int x, int y, std::vector<Robot> &robots);

};