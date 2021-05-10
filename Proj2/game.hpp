#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Player.hpp"
using namespace std;

class Game{
private:
    void robot_collision(vector<Robot> &robots, vector<bool> &status, vector<Element> &fences);

    void robot_movement(Element &player, vector<Robot> &robots, vector<bool> &robotStatus);

    bool is_alive(Element &mapSize, vector<Robot> &robots, vector< Element> &fences, Player player);

    void input_map(Maze &maze, Player &player, mapNumber);

    void export_results(int mapNumber, time_t gameTime);

    void draw(Element &mapSize, vector< Element> &fences, vector< Robot> &robots, vector< bool> &robotStatus, Element player);

    void moveTurn(vector< Robot> &robots, vector<bool> &robotStatus, Element &player);


public:
    int play_game(int mapNumber);

};



