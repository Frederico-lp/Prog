#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define MAP_HEIGHT 10
#define MAP_WIDTH  20

bool is_fence_or_post(int x, int y, vector< pair <int,int> > &fences){
    if(x == 0 || x == MAP_WIDTH || y == 0 || y == MAP_HEIGHT)
        return true;

    else {
        for(int i = 0; i < fences.size(); i++){
            if(make_pair(x, y) == fences.at(i))
                return true;
        }
    }
    
    return false;

}

//checks if there is a robot in that coordinate
bool is_robot(int x, int y, vector< pair <int,int> > &robots){
    for(int i = 0; i < robots.size(); i++){
        if(make_pair(x, y) == robots.at(i))
            return true;
    }
    return false;
}

//saves the robots coordinates
void input_map(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, int mapNumber){
    ifstream maze("MAZE_01.txt");
    //falta fazer switch para os varios mapas
    string line;
    for(int height = 0; getline(maze, line); height++){
        for(int width = 0; width < line.size(); width++)
            if(line[width] == 'R')
                robots.push_back( make_pair(width, height) );

            else if(line[width] == '*')
                //check if its fence or post
                if(height != 0 && height != (MAP_HEIGHT - 1) 
                    && width != 0 && width != (MAP_WIDTH - 1) )
                    fences.push_back( make_pair(width, height) );
    }
}

void draw(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences) {
    //system("clear");

    // draws the map
    for (int i = 0; i <= MAP_HEIGHT; i++) {
        for (int j = 0; j <= MAP_WIDTH; j++) {

            if (is_fence_or_post(j, i, fences)) {
                cout << '*' << flush;   //flush?
            
            } else if (is_robot(j, i, robots)) {
                cout << 'R' << flush;

            } else {
                cout << ' ' << flush;
            }
        }

        cout << "\n";
    }

}

int play_game(int mapNumber){
    vector< pair <int,int> > robots;
    vector< pair <int,int> > fences;

    input_map(robots, fences, mapNumber);

    draw(robots, fences);
    return 0;
}
