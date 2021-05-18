#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Game{

};


void robot_collision(vector<Robot> &robots, vector<bool> &status, vector<Element> &fences);

void robot_movement(Element &player, vector<Robot> &robots, vector<bool> &robotStatus);

bool is_fence_or_post(Element &mapSize, int x, int y, vector< Element > &fences);

int is_robot(int x, int y, vector< Robot> &robots, vector<bool> &robotStatus);

bool is_player(int x, int y, Element player);

bool is_alive(Element &mapSize, vector<Robot> &robots, vector< Element> &fences, Element player);

void input_map(Element &mapSize, Element &player, vector< Robot> &robots, vector< Element> &fences, int mapNumber);

void export_results(int mapNumber, time_t gameTime);

void draw(Element &mapSize, vector< Element> &fences, vector< Robot> &robots, vector< bool> &robotStatus, Element player);

void moveTurn(vector< Robot> &robots, vector<bool> &robotStatus, Element &player);

int play_game(int mapNumber);
