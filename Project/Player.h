//
// Created by frederico on 10/05/21.
//

#ifndef PROJECT_PLAYER_H
#define PROJECT_PLAYER_H


class Player {
private:
    int x, y;
    bool isAlive();

public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

private:
    bool isPlayer(int x, int y);

public:
    Player(int x, int y);
    void setPosition(int x, int y);
    movePlayer();

};


#endif //PROJECT_PLAYER_H
