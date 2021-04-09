#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool is_fence_or_post(int x, int y, vector< pair <int,int> > &fences);

bool is_robot(int x, int y, vector< pair <int,int> > &robots);

bool is_player(int x, int y, pair <int, int> player);

bool is_alive(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, pair <int,int> player);


void input_map(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, int mapNumber);

void draw(vector< pair <int,int> > &fences, vector< pair <int,int> > &robots, pair <int,int> player);

void move(vector< pair <int,int> > &robots, pair <int,int> &player);

int play_game(int mapNumber);
