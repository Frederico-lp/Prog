#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool is_fence_or_post(int x, int y, vector< pair <int,int> > &fences);

bool is_robot(int x, int y, vector< pair <int,int> > &robots);

void input_map(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, int mapNumber);

void draw(vector< pair <int,int> > &fences, vector< pair <int,int> > &robots);

int play_game(int mapNumber);
