#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "game.hpp"
using namespace std;

#define MAP_HEIGHT 10
#define MAP_WIDTH  20


bool is_fence_or_post(int x, int y, vector< Element > &fences){
    if(x == 0 || x == MAP_WIDTH || y == 0 || y == MAP_HEIGHT)
        return true;

    else {
        for(int i = 0; i < fences.size(); i++){
            if(x == fences.at(i).x && y == fences.at(i).y)
                return true;
        }
    }
    
    return false;

}

//checks if there is a robot in that coordinate
bool is_robot(int x, int y, vector< Robot> &robots){
    for(int i = 0; i < robots.size(); i++){
        if(x == robots.at(i).x && y == robots.at(i).y)
            return true;
    }
    return false;
}

bool is_player(int x, int y, Element player){
    if(x == player.x && y == player.y)
        return true;

    return false;
}

bool is_alive(vector< Robot > &robots, vector< Element > &fences, Element player){
    for(int i = 0; i < robots.size(); i++){
        if(player.x == robots.at(i).x && player.y == robots.at(i).y)
            return false;
    }

    if(player.x == 0 || player.x == MAP_WIDTH || player.y == 0 
                || player.y == MAP_HEIGHT)
        return false;

    else {
        for(int i = 0; i < fences.size(); i++){
            if(player.x == fences.at(i).x && player.y == fences.at(i).y)
                return false;
        }
    }

    return true;
}

//saves the robots coordinates
void input_map(vector< Robot > &robots, vector< Element > &fences, int mapNumber){
    ifstream maze("MAZE_01.txt");
    //falta fazer switch para os varios mapas
    string line;
    int id = 1;
    for(int height = 0; getline(maze, line); height++){
        for(int width = 0; width < line.size(); width++)
            if(line[width] == 'R'){
                robots.push_back( {width, height, id} );
                id++;
            }

            else if(line[width] == '*')
                //check if its fence or post
                if(height != 0 && height != (MAP_HEIGHT - 1) 
                    && width != 0 && width != (MAP_WIDTH - 1) )
                    fences.push_back( {width, height} );
    }
}

void draw(vector< Robot > &robots, vector< Element > &fences, Element player) {
    system("clear");

    // draws the map
    for (int i = 0; i <= MAP_HEIGHT; i++) {
        for (int j = 0; j <= MAP_WIDTH; j++) {

            if (is_fence_or_post(j, i, fences)) {
                cout << '*' << flush;   //flush?
            
            } else if (is_robot(j, i, robots)) {
                cout << 'R' << flush;
            
            } else if (is_player(j, i, player)) {
                cout << 'H' << flush;

            } else {
                cout << ' ' << flush;
            }
        }

        cout << "\n";
    }

}

void move(vector< Robot > &robots, Element &player){
    char move;
    cout << "Choose a move" << endl;
    cin >> move;
    
    if(move == 'q' || move == 'Q'){
        player.x -= 1;
        player.y -= 1;

    } else if(move == 'w' || move == 'W'){
        player.y -= 1;

    } else if(move == 'e' || move == 'E'){
        player.x += 1;
        player.y -= 1;

    } else if(move == 'a' || move == 'A'){
        player.x -= 1;

    } else if(move == 's' || move == 'S'){

    } else if(move == 'd' || move == 'D'){
        player.x += 1;

    } else if(move == 'z' || move == 'Z'){
        player.x -= 1;
        player.y += 1;

    } else if(move == 'x' || move == 'X'){
        player.y += 1;

    } else if(move == 'c' || move == 'C'){
        player.x += 1;
        player.y += 1;

    } else
        cerr << "Invalid move!" << endl;

    /*
    vector<pair<int,int> >::iterator itr=arr.begin(); 
    for(;itr!=arr.end();itr++) 
        (*itr).x=10;	
    */


}

int play_game(int mapNumber){
    vector< Robot > robots;
    vector< Element > fences;
    Element player = {5, 5};
    bool playing = true;

    input_map(robots, fences, mapNumber);

    draw(robots, fences, player);

    while(1){
        move(robots, player);
        if(is_alive(robots, fences, player))
            draw(robots, fences, player);
        else
            break;
        //update_Elements()
    }   
    return 0;
}
