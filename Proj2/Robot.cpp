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

int Robot::getX(){
    return this->x;
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

bool Player::isRobot(int x, int y, vector<Robot> &robots);
//getx ou so x? como é vetor acho q tenho de usar o getX
    for(int i = 0; i < robots.size(); i++){
        if(x == robots.at(i).getX() && y == robots.at(i).getY()){
            if(robotStatus.at(i).isAlive()){
                return 1;
            }
            else return 2;
        }
    }
    return 0;

}