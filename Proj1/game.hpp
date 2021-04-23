#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Robot {
    int x;
    int y;
    int id;
};

struct Element {
    int x;
    int y;
};

bool is_fence_or_post(int x, int y, vector<Element> &fences);

bool is_robot(int x, int y, vector<Robot> &robots);

bool is_player(int x, int y, Element player);

bool is_alive(vector<Robot> &robots, vector< Element> &fences, Element player);


void input_map(vector< Robot> &robots, vector< Element> &fences, int mapNumber);

void draw(vector< Element> &fences, vector< Robot> &robots, Element player);

void move(vector< Robot> &robots, Element &player);

int play_game(int mapNumber);
