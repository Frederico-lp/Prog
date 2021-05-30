//T08G06
#include "Robot.h"

Robot::Robot(int x, int y, int id){
    this->x = x;
    this->y = y;
    this->id = id;
    this->alive = true;
}

int Robot::getX() const{
    return this->x;
}

int Robot::getY() const{
    return this->y;
}

bool Robot::isAlive() const{
    return this->alive;
}

void Robot::setX(int newX){
    Robot::x = newX;
}

void Robot::setY(int newY){
    Robot::y = newY;
}

void Robot::setPosition(int newX, int newY){
    Robot::x = newX;
    Robot::y = newY;
}

void Robot::killRobot(){
    Robot::alive = false;
}
