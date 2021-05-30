//T08G06
#include "Game.h"

using namespace std;

Game::Game():maze(0, 0), player(0, 0){}

Game::~Game(){;}


void Game::robot_collision(vector<Robot> &robots1, Maze &maze1){
    for (int i1 = 0; i1<robots1.size(); i1++){
        //loop para colisões entre robots
        for (int i2 = i1+1; i2<robots1.size(); i2++){
            if (robots1.at(i1).isAlive() || robots1.at(i2).isAlive()){
                if (robots1.at(i1).getX()==robots1.at(i2).getX() &&
                    robots1.at(i1).getY()==robots1.at(i2).getY()){
                    robots1.at(i1).killRobot();
                    robots1.at(i2).killRobot();
                    //simplesmente mata o robo com a funçao, preciso mudar linha acima
                }
            }
        }
        //loop para colisões entre robot e fences
        for (int i3 = 0; i3<maze1.getPosts().size(); i3++){
            if (robots1.at(i1).isAlive() && (robots1.at(i1).getX()==maze1.getPosts().at(i3).getX() &&
                                            robots1.at(i1).getY()==maze1.getPosts().at(i3).getY())){
                robots1.at(i1).killRobot();
            }
        }
    }
}

//Robot movement
void Game::robot_movement(Player &player1, vector<Robot> &robots1){
    for (int i4=0; i4<robots1.size(); i4++){
        if(robots1.at(i4).isAlive()){
            if (player1.getX()<robots1.at(i4).getX()){
                robots1.at(i4).setX(robots1.at(i4).getX() - 1);
            }
            else if (player1.getX()>robots1.at(i4).getX()){
                robots1.at(i4).setX(robots1.at(i4).getX() + 1);
            }
            if (player1.getY()<robots1.at(i4).getY()){
                robots1.at(i4).setY(robots1.at(i4).getY() - 1);
            }
            else if (player1.getY()>robots1.at(i4).getY()){
                robots1.at(i4).setY(robots1.at(i4).getY() + 1);
            }
        }
    }
}



bool Game::is_alive(Maze &maze1, vector< Robot > &robots, Player &player1){

    for(int i = 0; i < maze1.getPosts().size(); i++){
        if(player1.getX() == maze1.getPosts().at(i).getX() &&
            player1.getY() == maze1.getPosts().at(i).getY())
            return false;
    }


    return true;
}

int Game::is_robot(int x, int y, vector<Robot> &robots1){
//getx ou so x? como é vetor acho q tenho de usar o getX
    for(int i = 0; i < robots1.size(); i++){
        if(x == robots1.at(i).getX() && y == robots1.at(i).getY()){
            if(robots1.at(i).isAlive()){
                return 1;
            }
            else return 2;
        }
    }
    return 0;

}

int Game::is_player(int x, int y, Player &player1){
    if (x == player1.getX() && y == player1.getY()){
        if (player1.getAlive())
            return 1;
        else
            return 2;
    }
    return 0;
}

int Game::is_post(int x, int y, std::vector<Post> ePosts, vector<Post> nePosts){

    for(int i = 0; i < ePosts.size(); i++){
        if(x == ePosts.at(i).getX() && y == ePosts.at(i).getY())
            return 1;
    }
    for(int i = 0; i < nePosts.size(); i++){
        if(x == nePosts.at(i).getX() && y == nePosts.at(i).getY())
            return 2;
    }

    return 0;

}

bool Game::is_exit(int x, int y, std::vector<Post> exits){

    for(int i = 0; i < exits.size(); i++){
        if(x == exits.at(i).getX() && y == exits.at(i).getY())
            return true;
    }
    

    return false;

}

int Game::scanPos(int x1, int y1, Player &player1, vector<Robot> &robots1, Maze &Maze1) {
    if (x1==player1.getX() && y1==player1.getY())
        return 1;
    int s;
    s = is_robot(x1, y1 , robots1);
    if (s==1)
        return 2;
    if (s==2)
        return 3;
    s = is_post(x1, y1, Maze1.getPosts(), Maze1.getHarmlessPosts());
    if (s==1)
        return 4;
    if (s==2)
        return 5;
    if (is_exit(x1, y1, Maze1.getExits()))
        return 6;
    if (Maze1.is_outOfBounds(x1, y1))
        return 7;

    return 0;
}

bool Game::playerMove(Player &player1, vector<Robot> &robots1, Maze &Maze1) {
    char move;
    int scanResult;
    bool allowedMove = false;
    while (!allowedMove) {
        cout << "\nChoose your move: ";
        while (!(cin >> move) ||
               !(move == 'q' || move == 'Q' || move == 'w' || move == 'W' || move == 'e' || move == 'E' ||
                 move == 'a' || move == 'A' || move == 's' || move == 'S' || move == 'd' || move == 'D' ||
                 move == 'z' || move == 'Z' || move == 'x' || move == 'X' || move == 'c' || move == 'C')) {
            cin.clear();
            cout << "\nSelected move does not exist.\nChoose another move: ";
        }
        if (move == 'q' || move == 'Q') {
            scanResult = scanPos(player1.getX() - 1, player1.getY() - 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat move is not valid, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() - 1);
                player1.setY(player1.getY() - 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() - 1);
                player1.setY(player1.getY() - 1);
                allowedMove = true;
            }
        }
        else if (move == 'w' || move == 'W') {
            scanResult = scanPos(player1.getX(), player1.getY() - 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                    scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setY(player1.getY() - 1);
                return true;
            } else { //target cell has nothing in it
                player1.setY(player1.getY() - 1);
                allowedMove = true;
            }
        }
        else if (move == 'e' || move == 'E') {
            scanResult = scanPos(player1.getX() + 1, player1.getY() - 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() + 1);
                player1.setY(player1.getY() - 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() + 1);
                player1.setY(player1.getY() - 1);
                allowedMove = true;
            }
        }
        else if (move == 'a' || move == 'A') {
            scanResult = scanPos(player1.getX() - 1, player1.getY(), player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() - 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() - 1);
                allowedMove = true;
            }
        }
        else if (move == 's' || move == 'S') {
            scanResult = scanPos(player1.getX(), player1.getY(), player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                return true;
            } else { //target cell has nothing in it
                allowedMove = true;
            }
        }
        else if (move == 'd' || move == 'D') {
            scanResult = scanPos(player1.getX() + 1, player1.getY(), player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() + 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() + 1);
                allowedMove = true;
            }
        }
        else if (move == 'z' || move == 'Z') {
            scanResult = scanPos(player1.getX() - 1, player1.getY() + 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() - 1);
                player1.setY(player1.getY() + 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() - 1);
                player1.setY(player1.getY() + 1);
                allowedMove = true;
            }
        }
        else if (move == 'x' || move == 'X') {
            scanResult = scanPos(player1.getX(), player1.getY() + 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setY(player1.getY() + 1);
                return true;
            } else { //target cell has nothing in it
                player1.setY(player1.getY() + 1);
                allowedMove = true;
            }
        }
        else if (move == 'c' || move == 'C') {
            scanResult = scanPos(player1.getX() + 1, player1.getY() + 1, player1, robots1, Maze1);
            if (scanResult == 3 || scanResult == 5) { //target cell is non electrified post or dead/stuck robot
                cin.clear();
                cout << "\nThat cell is impassable, try another one.";
            } else if (scanResult == 2 || scanResult == 4 ||
                       scanResult == 7) { //target cell is electrified post, outer fence or living robot
                player1.setAlive(false);
                allowedMove = true;
            } else if (scanResult == 6) { //target cell is an exit
                player1.setX(player1.getX() + 1);
                player1.setY(player1.getY() + 1);
                return true;
            } else { //target cell has nothing in it
                player1.setX(player1.getX() + 1);
                player1.setY(player1.getY() + 1);
                allowedMove = true;
            }
        }
    }
    return false;
}

int Game::robotMove(Player &player1, vector<Robot> &robots1, Maze &Maze1) {
    int tempX, tempY;
    int scanResult;
    for (int i = 0; i < robots1.size(); i++){
        if (robots1.at(i).isAlive()) {
            tempX = robots1.at(i).getX();
            tempY = robots1.at(i).getY();
            if (tempX < player1.getX())
                tempX += 1;
            else if (tempX > player1.getX())
                tempX -= 1;
            if (tempY < player1.getY())
                tempY += 1;
            else if (tempY > player1.getY())
                tempY -= 1;
            scanResult = scanPos(tempX, tempY, player1, robots1, Maze1);
            if (scanResult == 1) {
                player1.setAlive(false);
                return 0;
            } else if (scanResult == 2 || scanResult == 3 || scanResult == 5){
                robots1.at(i).setX(tempX);
                robots1.at(i).setY(tempY);
                for (int j = 0 ; j < robots1.size(); j++){
                    if (robots1.at(j).getX()==tempX && robots1.at(j).getY()==tempY)
                        robots1.at(j).killRobot();
                }
            } else if (scanResult == 4) {
                robots1.at(i).killRobot();
            } else {
                robots1.at(i).setX(tempX);
                robots1.at(i).setY(tempY);
            }
        }
    }
    return 0;
}

//saves the robots coordinates
void Game::input_map(Maze &maze1, vector<Robot> &robots1, Player &player1, int mapNumber){
    char mapBuffer[20];
    if (mapNumber < 10){
        sprintf(mapBuffer, "MAZE_0%d.txt", mapNumber);
    }
    else{
        sprintf(mapBuffer, "MAZE_%d.txt", mapNumber);
    }

    ifstream level(mapBuffer);

    string line;

    getline(level, line);

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

    //inserir o tamanho do mapa
    maze1.setWidth(tempMapSize.at(1));
    maze1.setHeight(tempMapSize.at(0));

    int id = 1;

    for(int height = 0; getline(level, line); height++){
        for(int width = 0; width < line.size(); width++){

            if(line[width] == 'H'){
                player1.setPosition(width, height);
            }

            else if(line[width] == 'R'){
                Robot robot(width, height, id);
                robots1.push_back(robot);
                id++;
            }

            else if(line[width] == '*'){
                //check if its fence or post
                    Post post(width, height);
                    maze1.addPost(post);
            }

            else if(line[width] == '+'){
                Post post(width, height);
                maze1.addHarmlessPost(post);
            }

            else if(line[width] == 'O'){
                    Post exit(width, height);
                    maze1.addExit(exit);
                    cout<<"entra aqui\n";
                
            }
        }
    }
    
}


void Game::export_results(int mapNumber, time_t gameTime){
    char winBuffer[50];
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
    while(!mazeIn.eof() && !mazeIn.fail()){
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


void Game::draw(Maze &maze1, vector< Robot> &robots1, Player &player1) {
    cout << "\x1B[2J\x1B[H";

    // draws the map
    for (int i = 0; i <= maze1.getHeight(); i++) {
        for (int j = 0; j <= maze1.getWidth(); j++) {

            if (is_player(j, i, player1)==1) {
                cout << 'H' << flush;
            }
            else if (is_player(j, i, player1)==2){
                cout << 'h' << flush;
            }
            else if (is_robot(j, i, robots1)==1) {
                cout << 'R' << flush;
            }
            else if (is_robot(j, i, robots1)==2) {
                cout << 'r' << flush;
            }
            else if (is_post(j, i, maze1.getPosts(), maze1.getHarmlessPosts())==1) {
                cout << '*' << flush;
            }
            else if (is_post(j, i, maze1.getPosts(), maze1.getHarmlessPosts())==2) {
                cout << '+' << flush;
            }
            else if (is_exit(j, i, maze1.getExits())) {
                cout << 'O' << flush;
            }
            else {
                cout << ' ' << flush;
            }
        }

        cout << "\n";
    }

}

void Game::moveTurn(vector< Robot > &robots1, Player &player1){
    char move;
    cout << "Choose a move" << endl;
    cin >> move;
    if(move == 'q' || move == 'Q'){
        if(is_robot(player1.getX() - 1, player1.getY() - 1, robots1) != 2){
            player1.setX(player1.getX() - 1);
            player1.setY(player1.getY() - 1);
        }

    } else if(move == 'w' || move == 'W'){
        if(is_robot(player1.getX(), player1.getY() - 1, robots1) != 2)
            player1.setY(player1.getY() - 1);

    } else if(move == 'e' || move == 'E'){
        if(is_robot(player1.getX() + 1, player1.getY() - 1, robots1) != 2){
            player1.setX(player1.getX() + 1);
            player1.setY(player1.getY() - 1);
        }

    } else if(move == 'a' || move == 'A'){
        if(is_robot(player1.getX() - 1, player1.getY(), robots1) != 2)
            player1.setX(player1.getX() - 1);

    } else if(move == 's' || move == 'S'){

    } else if(move == 'd' || move == 'D'){
        if(is_robot(player1.getX() + 1, player1.getY(), robots1) != 2)
            player1.setX(player1.getX() + 1);

    } else if(move == 'z' || move == 'Z'){
        if(is_robot(player1.getX() - 1, player1.getY() + 1, robots1) != 2){
            player1.setX(player1.getX() - 1);
            player1.setY(player1.getY() + 1);
        }

    } else if(move == 'x' || move == 'X'){
        if(is_robot(player1.getX(), player1.getY() - 1, robots1) != 2)
            player1.setY(player1.getY() + 1);

    } else if(move == 'c' || move == 'C'){
        if(is_robot(player1.getX() + 1, player1.getY() + 1, robots1) != 2){
            player1.setX(player1.getX() + 1);
            player1.setY(player1.getY() + 1);
        }

    } else
        cerr << "Invalid move!" << endl;

    robot_movement(player1, robots1);
}

int Game::play_game(int mapNumber){

    bool victorious = false;

    input_map(maze, robots, player, mapNumber);


    draw(maze, robots, player);

    time_t time1, time2, elapsedTime;

    srand((unsigned int) time(NULL));

    time1 = time(NULL);

    /*
    while(1){
        moveTurn(robots, player);
        robot_collision(robots, maze);
        if(is_alive(maze, robots, player)){
            if(is_exit(player.getX(), player.getY(), maze.getExits())){
                victorious = 1;
                break;
            }
            draw(maze, robots, player);
                //break;
        }
        else
            break;
    }
     */

    while (1) {
        if (playerMove(player, robots, maze)) {
            victorious = true;
            break;
        } else if (!(player.getAlive())){
            break;
        } else {
            robotMove(player, robots, maze);
            if (!(player.getAlive()))
                break;
            draw(maze, robots, player);
        }
    }


    time2 = time(NULL);
    elapsedTime = time2 - time1;

    //draw(maze, robots, player);

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

