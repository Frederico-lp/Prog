#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>
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


//verifica se existem novos robots em colisão e retorna um vector paralelo ao vector dos robots que indica quais estão mortos
//vivos como true e mortos como false
void robot_collision(vector<Robot> &robots, vector<bool> &status, vector<Element> &fences){
    for (int i1 = 0; i1<robots.size(); i1++){
        //loop para colisões entre robots
        for (int i2 = i1+1; i2<robots.size(); i2++){
            if (status.at(i1) || status.at(i2)){
                if (robots.at(i1).x==robots.at(i2).x && robots.at(i1).y==robots.at(i2).y){
                    status.at(i1)=false;
                    status.at(i2)=false;
                }
            }
        }
        //loop para colisões entre robot e fences
        for (int i3 = 0; i3<fences.size(); i3++){
            if (status.at(i1) && (robots.at(i1).x==fences.at(i3).x && robots.at(i1).y==fences.at(i3).y)){
                status.at(i1)=false;
            }
        }
    }
}

//Robot movement
void robot_movement(Element &player, vector<Robot> &robots, vector<bool> &robotStatus){
    for (int i4=0; i4<robots.size(); i4++){
        if(robotStatus.at(i4)){
            if (player.x<robots.at(i4).x){
                robots.at(i4).x-=1;
            }
            else if (player.x>robots.at(i4).x){
                robots.at(i4).x+=1;
            }
            if (player.y<robots.at(i4).y){
                robots.at(i4).y-=1;
            }
            else if (player.y>robots.at(i4).y){
                robots.at(i4).y+=1;
            }
        }
    }
}

bool is_fence_or_post(Element &mapSize, int x, int y, vector< Element > &fences){
    if(x == 0 || x == mapSize.x || y == 0 || y == mapSize.y)
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
//return = 1 é robot vivo e = 2 é robot morto
int is_robot(int x, int y, vector< Robot> &robots, vector<bool> &robotStatus){
    for(int i = 0; i < robots.size(); i++){
        if(x == robots.at(i).x && y == robots.at(i).y){
            if(robotStatus.at(i)){
                return 1;
            }
            else return 2;
        }
    }
    return 0;
}

bool is_player(int x, int y, Element player){
    if(x == player.x && y == player.y)
        return true;

    return false;
}

bool is_alive(Element &mapSize, vector< Robot > &robots, vector< Element > &fences, Element player){
    for(int i = 0; i < robots.size(); i++){
        if(player.x == robots.at(i).x && player.y == robots.at(i).y)
            return false;
    }

    if(player.x == 0 || player.x == mapSize.x || player.y == 0 
                || player.y == mapSize.y)
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
void input_map(Element &mapSize, Element &player, vector< Robot> &robots, vector< Element> &fences, int mapNumber){
    char mapBuffer[20];
    if (mapNumber < 10){
        sprintf(mapBuffer, "MAZE_0%d.txt", mapNumber);
    }
    else{
        sprintf(mapBuffer, "MAZE_%d.txt", mapNumber);
    }

    ifstream maze(mapBuffer);

    string line;

    getline(maze, line);

    string n = "";
    vector<int> tempMapSize;
    line+=" ";
    for (int i5=0; i5<line.size(); i5++){
        //se char é um numero
        if (line[i5]>47 && line[i5]<58){
            n += line[i5];
        }
        //se char n é um numero completamos um dos tamanhos
        else if (n.size()>0){
            tempMapSize.push_back(stoi(n));
            n="";
        }
    }

    //inserir o tamanho do mapa no Element mapSize (1o valor e height e o 2o e width)
    mapSize.x=tempMapSize.at(1);
    mapSize.y=tempMapSize.at(0);

    int id = 1;

    for(int height = 0; getline(maze, line); height++){
        for(int width = 0; width < line.size(); width++){
            if(line[width] == 'H'){
                player.x = width;
                player.y = height;
            }
            else if(line[width] == 'R'){
                robots.push_back( {width, height, id} );
                id++;
            }

            else if(line[width] == '*')
                //check if its fence or post
                if(height != 0 && height != (mapSize.y - 1) 
                    && width != 0 && width != (mapSize.x - 1) )
                    fences.push_back( {width, height} );
        }
    }
}

void export_results(int mapNumber, time_t gameTime){
    char winBuffer[30];
    if (mapNumber < 10){
        sprintf(winBuffer, "MAZE_0%d_WINNERS.txt", mapNumber);   
    }
    else{
        sprintf(winBuffer, "MAZE_%d_WINNERS.txt", mapNumber);   
    }
    
    ifstream mazeIn(winBuffer);

    string buffer = "";

    char next;
    mazeIn.get(next);
    while(!mazeIn.eof()){
        buffer = buffer + next;
        mazeIn.get(next);
    }

    mazeIn.close();
    if (buffer.find("Player – Time\n----------------------")==-1){
        buffer = "Player – Time\n----------------------" + buffer;
    }
    
    ofstream mazeOut(winBuffer);
    string playerName;

    cout << endl << "Enter your name: ";
    cin.ignore();
    getline(cin, playerName);
    while(playerName.size() > 15){
        cin.clear();
        cout << endl << "The name you enter must be 15 characters long or less.\nEnter your name: ";
        getline(cin, playerName);
    }

    mazeOut << buffer << endl << playerName << " - " << gameTime;

    mazeOut.close();
}


void draw(Element &mapSize, vector< Element> &fences, vector< Robot> &robots, vector< bool> &robotStatus, Element player) {
    cout << "\x1B[2J\x1B[H";

    // draws the map
    for (int i = 0; i <= mapSize.y; i++) {
        for (int j = 0; j <= mapSize.x; j++) {
            
            if (is_player(j, i, player)) {
                cout << 'H' << flush; 
            }
            else if (is_robot(j, i, robots, robotStatus)==1) {
                cout << 'R' << flush;
            }
            else if (is_robot(j, i, robots, robotStatus)==2) {
                cout << 'r' << flush;
            }
            else if (is_fence_or_post(mapSize, j, i, fences)) {
                cout << '*' << flush;
            }
            else {
                cout << ' ' << flush;
            }
        }

        cout << "\n";
    }

}

void moveTurn(vector< Robot > &robots, vector<bool> &robotStatus, Element &player){
    char move;
    cout << "Choose a move" << endl;
    cin >> move;
    if(move == 'q' || move == 'Q'){
        if(is_robot(player.x - 1, player.y - 1, robots, robotStatus) != 2){
            player.x -= 1;
            player.y -= 1;
        }

    } else if(move == 'w' || move == 'W'){
        if(is_robot(player.x, player.y - 1, robots, robotStatus) != 2)
            player.y -= 1;

    } else if(move == 'e' || move == 'E'){
        if(is_robot(player.x + 1, player.y - 1, robots, robotStatus) != 2){
            player.x += 1;
            player.y -= 1;
        }

    } else if(move == 'a' || move == 'A'){
        if(is_robot(player.x - 1, player.y, robots, robotStatus) != 2)
            player.x -= 1;

    } else if(move == 's' || move == 'S'){

    } else if(move == 'd' || move == 'D'){
        if(is_robot(player.x + 1, player.y, robots, robotStatus) != 2)
            player.x += 1;

    } else if(move == 'z' || move == 'Z'){
        if(is_robot(player.x - 1, player.y + 1, robots, robotStatus) != 2){
            player.x -= 1;
            player.y += 1;
        }

    } else if(move == 'x' || move == 'X'){
        if(is_robot(player.x, player.y - 1, robots, robotStatus) != 2)
            player.y += 1;

    } else if(move == 'c' || move == 'C'){
        if(is_robot(player.x + 1, player.y + 1, robots, robotStatus) != 2){
            player.x += 1;
            player.y += 1;
        }

    } else
        cerr << "Invalid move!" << endl;

    robot_movement(player, robots, robotStatus);
}

int play_game(int mapNumber){
    Element mapSize = {0, 0};
    vector< Robot > robots;
    vector< Element > fences;
    Element player = {0, 0};
    bool playing = true; 

    bool victorious = false;
    bool allRobotsDeadCheck = false;

    input_map(mapSize, player, robots, fences, mapNumber);

    vector< bool > robotStatus (robots.size(), true);

    draw(mapSize, fences, robots, robotStatus, player);

    time_t time1, time2, elapsedTime;

    srand((unsigned int) time(NULL));

    time1 = time(NULL);

    while(1){
        moveTurn(robots, robotStatus, player);
        robot_collision(robots, robotStatus, fences);
        if(is_alive(mapSize, robots, fences, player)){
            draw(mapSize, fences, robots, robotStatus, player);
            if(all_of(robotStatus.begin(), robotStatus.end(), [](bool v) { return !v; })){
                allRobotsDeadCheck=true;
            }

            if (allRobotsDeadCheck ){
                victorious = true;
                break;
            }
        }
        else
            break;
    }

    time2 = time(NULL);
    elapsedTime = time2 - time1;

    if (victorious){
        cout << endl << "Victory!\nYou took " << elapsedTime << " seconds to win!\n";
        export_results(mapNumber, elapsedTime);
        return 0;
    }
    else{
        cout << endl << "You lost!\n";
        return -1;
    }
}
