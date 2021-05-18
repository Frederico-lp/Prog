#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int print_menu(){
    int option;
    cout << endl << "Choose an option: \n" << "0) Exit;\n1) Rules;\n2) Play;\n";
    while(!(cin >> option) || (option!=0 && option!=1 && option!=2)){
        cin.clear();
        cout << endl <<"Choose a valid option: \n" << "0) Exit;\n1) Rules;\n2) Play;\n";
    }
    return option;
}

int select_map(){
    int option2;
    cout << endl << "Which map will you choose?\nMap: ";
    cin >> option2;

    char mapBuffer[20];
    if (option2 < 10){
        sprintf(mapBuffer, "MAZE_0%d.txt", option2);
    }
    else{
        sprintf(mapBuffer, "MAZE_%d.txt", option2);
    }
    ifstream maze(mapBuffer);
    while (maze.fail()){
        cin.clear();
        maze.clear();
        cout << endl << "Which map will you choose?\nMake sure you select an existing map (maps only go up to 99).\nMap: ";
        cin >> option2;
        if (option2 < 10){
            sprintf(mapBuffer, "MAZE_0%d.txt", option2);
        }
        else{
            sprintf(mapBuffer, "MAZE_%d.txt", option2);
        }
        maze.open(mapBuffer);
    }
    return option2;
}

int show_rules(){
    int option;
    cout<<"The player is placed in a maze made up of high-voltage fences and posts. There are also some interceptor robots that will try to destroy the player. If the player touches the maze or any of these robots, that is the end of the game (and the player!).The robots are also destroyed when they touch the fences/postsor when they collide with each other.Every time the player moves in any direction(horizontally, vertically, or diagonally)to a contiguous cell, each robot movesone cell closer to the new player's location, in whichever direction is the shortest path. The robots have no vision sensors but they have an accurate odour sensor that allows them to follow the player!There is one hope: make the robots hit the maze or each other. If all of them are destroyed, the player wins.\n";
    cout<<"Use S to stay in the same place, W and X to move vertically, A and D to move horizontally and Q, E, Z and C to move diagonally\n";
    cout<<"Do you want to exit(0) or play(1)?\n";
    while(!(cin >> option) || (option!=0 && option!=1)){
        cin.clear();
        cout << endl <<"Choose a valid option: \n" << "0) Exit;\n1) Play;\n";
    }
    
    return option;
}
