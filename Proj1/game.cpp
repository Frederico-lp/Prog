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

bool is_player(int x, int y, pair <int, int> player){
    if(make_pair(x, y) == player)
        return true;

    return false;
}

bool is_alive(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, pair <int,int> player){
    for(int i = 0; i < robots.size(); i++){
        if(player == robots.at(i))
            return false;
    }

    if(player.first == 0 || player.first == MAP_WIDTH || player.second == 0 
                || player.second == MAP_HEIGHT)
        return false;

    else {
        for(int i = 0; i < fences.size(); i++){
            if(player== fences.at(i))
                return false;
        }
    }

    return true;
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

void draw(vector< pair <int,int> > &robots, vector< pair <int,int> > &fences, pair <int,int> player) {
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

void move(vector< pair <int,int> > &robots, pair <int,int> &player){
    char move;
    cout << "Choose a move" << endl;
    cin >> move;
    
    if(move == 'q' || move == 'Q'){
        player.first -= 1;
        player.second -= 1;

    } else if(move == 'w' || move == 'W'){
        player.second -= 1;

    } else if(move == 'e' || move == 'E'){
        player.first += 1;
        player.second -= 1;

    } else if(move == 'a' || move == 'A'){
        player.first -= 1;

    } else if(move == 's' || move == 'S'){

    } else if(move == 'd' || move == 'D'){
        player.first += 1;

    } else if(move == 'z' || move == 'Z'){
        player.first -= 1;
        player.second += 1;

    } else if(move == 'x' || move == 'X'){
        player.second += 1;

    } else if(move == 'c' || move == 'C'){
        player.first += 1;
        player.second += 1;

    } else
        cerr << "Invalid move!" << endl;

    /*
    vector<pair<int,int> >::iterator itr=arr.begin(); 
    for(;itr!=arr.end();itr++) 
        (*itr).first=10;	
    */


}

int play_game(int mapNumber){
    vector< pair <int,int> > robots;
    vector< pair <int,int> > fences;
    pair <int,int> player = make_pair(5, 5);
    bool playing = true;

    input_map(robots, fences, mapNumber);

    draw(robots, fences, player);

    while(1){
        move(robots, player);
        if(is_alive(robots, fences, player))
            draw(robots, fences, player);
        else
            break;
        //update_positions()
    }   
    return 0;
}
