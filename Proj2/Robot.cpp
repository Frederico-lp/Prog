#include "Robot.hpp"

Robot::Robot(int x, int y, int id){
    this->x = x;
    this->y = y;
    this->id = id;
    this->alive = true;
}

int Robot::getX(){
    return this->x;
}

int Robot::getY(){
    return this->y;
}

bool Robot::isAlive(){
    return this->alive;
}

void Robot::setX(int x){
    Robot::x = x;
}

void Robot::setY(int y){
    Robot::y = y;
}

void Robot::setPosition(int x, int y){
    Robot::x = x;
    Robot::y = y;
}

void Robot::killRobot(){
    Robot::alive = false;
}

