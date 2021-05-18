#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <ostream>
#include <cstddef>
#include "Player.hpp"
#include "Maze.hpp"
#include "Robot.hpp"
using namespace std;

class Game{
private:
    void robot_collision(vector<Robot> &robots, Maze &maze);

    void robot_movement(Player &player, vector<Robot> &robots);

    bool is_alive(Maze &maze, vector< Robot > &robots, Player &player);

    bool is_robot(int x, int y, vector<Robot> &robots);

    bool is_player(int x, int y, Player &player);

    bool is_post(int width, int height, int x, int y, std::vector<Post> posts);

    void input_map(Maze &maze, vector<Robot> &robots, Player &player, int mapNumber);

    void export_results(int mapNumber, time_t gameTime);

    void draw(Maze &maze, vector< Robot> &robots, Player &player);

    void moveTurn(vector< Robot> &robots, Player &player);


public:
    int play_game(int mapNumber);

};



