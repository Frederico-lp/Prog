//T08G06
#pragma once

#ifndef PROJ2_GAME_H
#define PROJ2_GAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <cstddef>
#include "Player.h"
#include "Maze.h"
#include "Robot.h"
using namespace std;

class Game{
private:
    Maze maze;

    Player player;

    vector< Robot > robots;

    void robot_collision(vector<Robot> &robots1, Maze &maze1);

    void robot_movement(Player &player1, vector<Robot> &robots1);

    bool is_alive(Maze &maze1, vector< Robot > &robots, Player &player1);

    int is_robot(int x, int y, vector<Robot> &robots1);
    //returns 0 for no robot, 1 for alive robot, 2 for dead robot

    int is_player(int x, int y, Player &player1);
    //returns 0 for no player, 1 for alive player, 2 for dead player

    int is_post(int x, int y, std::vector<Post> ePosts, vector<Post> nePosts);
    //returns 0 for no post, 1 for electrified post, 2 for non-electrified post

    bool is_exit(int x, int y, std::vector<Post> exits);

    int scanPos(int x1, int y1, Player &player1, vector<Robot> &robots1, Maze &Maze1);
    //return 0 for nothing, 1 for player, 2 for alive robot, 3 for dead robot, 4 for electrified post, 5 for non-electrified post, 6 for exit, 7 for outer fence

    bool playerMove(Player &player1, vector<Robot> &robots1, Maze &Maze1);
    //returns true if player escapes maze, else false

    int robotMove(Player &player1, vector<Robot> &robots1, Maze &Maze1);

    void input_map(Maze &maze1, vector<Robot> &robots1, Player &player1, int mapNumber);

    void export_results(int mapNumber, time_t gameTime);

    void draw(Maze &maze, vector< Robot> &robots, Player &player);

    void moveTurn(vector< Robot> &robots, Player &player);


public:
    Game();

    ~Game();

    int play_game(int mapNumber);

};

#endif //PROJ2_GAME_H
