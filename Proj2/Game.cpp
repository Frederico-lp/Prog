#include "Game.hpp"
using namespace std;


//verifica se existem novos robots em colisão e retorna um vector paralelo ao vector dos robots que indica quais estão mortos
//vivos como true e mortos como false
void Game::robot_collision(vector<Robot> &robots, Maze &maze){
    for (int i1 = 0; i1<robots.size(); i1++){
        //loop para colisões entre robots
        for (int i2 = i1+1; i2<robots.size(); i2++){
            if (robots.at(i1).isAlive() || robots.at(i2).isAlive()){
                if (robots.at(i1).getX()==robots.at(i2).getX() &&
                     robots.at(i1).getY()==robots.at(i2).getY()){
                    robots.at(i1).killRobot();
                    robots.at(i2).killRobot();
                    //simplesmente mata o robo com a funçao, preciso mudar linha acima
                }
            }
        }
        //loop para colisões entre robot e fences
        for (int i3 = 0; i3<maze.getPosts().size(); i3++){
            if (robots.at(i1).isAlive() && (robots.at(i1).getX()==maze.getPosts().at(i3).getX() &&
                 robots.at(i1).getY()==maze.getPosts().at(i3).getY())){
                robots.at(i1).killRobot();
            }
        }
    }
}

//Robot movement
void Game::robot_movement(Player &player, vector<Robot> &robots){
    for (int i4=0; i4<robots.size(); i4++){
        if(robots.at(i4).isAlive()){
            if (player.getX()<robots.at(i4).getX()){
                robots.at(i4).setX(robots.at(i4).getX() - 1);
            }
            else if (player.getX()>robots.at(i4).getX()){
                robots.at(i4).setX(robots.at(i4).getX() + 1);
            }
            if (player.getY()<robots.at(i4).getY()){
                robots.at(i4).setY(robots.at(i4).getY() - 1);
            }
            else if (player.getY()>robots.at(i4).getY()){
                robots.at(i4).setY(robots.at(i4).getY() + 1);
            }
        }
    }
}



bool Game::is_alive(Maze &maze, vector< Robot > &robots, Player &player){
    for(int i = 0; i < robots.size(); i++){
        if(player.getX() == robots.at(i).getX() && player.getY() == robots.at(i).getY())
            return false;
    }

    if(player.getX() == 0 || player.getX() == maze.getWidth() || player.getY() == 0 
                || player.getY() == maze.getHeight())
        return false;

    else {
        for(int i = 0; i < maze.getPosts()->size(); i++){
            if(player.getX() == maze.getPosts().at(i).getX() &&
                 player.getY() == maze.getPosts().at(i).getY())
                return false;
        }
    }

    return true;
}

bool Game::is_robot(int x, int y, vector<Robot> &robots){
//getx ou so x? como é vetor acho q tenho de usar o getX
    for(int i = 0; i < robots.size(); i++){
        if(x == robots.at(i).getX() && y == robots.at(i).getY()){
            if(robots.at(i).isAlive()){
                return 1;
            }
            else return 2;
        }
    }
    return 0;

}

//saves the robots coordinates
void Game::input_map(Maze &maze, vector<Robot> &robots, Player &player, int mapNumber){
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
    maze.setWidth(tempMapSize.at(1));
    maze.setHeight(tempMapSize.at(0));

    int id = 1;

    for(int height = 0; getline(level, line); height++){
        for(int width = 0; width < line.size(); width++){
            if(line[width] == 'H'){
                player.setX(width);
                player.setY(height);
            }
            else if(line[width] == 'R'){
                Robot robot = new Robot(width, height, id)
                robots.push_back(robot);
                id++;
            }

            else if(line[width] == '*'){
                //check if its fence or post
                if(height != 0 && height != (maze.getHeight() - 1) 
                    && width != 0 && width != (maze.getWidth() - 1) ){
                        //posso fazer isto?
                        Post post = new post(width, height, id);
                        maze.addPost( {width, height, id} );
                    }
            }
        }
    }
}

void Game::export_results(int mapNumber, time_t gameTime){
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


void Game::draw(Maze &maze, vector< Robot> &robots, Player player) {
    cout << "\x1B[2J\x1B[H";

    // draws the map
    for (int i = 0; i <= maze.getHeight(); i++) {
        for (int j = 0; j <= maze.getWidth(); j++) {
            
            if (is_player(j, i, player)) {
                cout << 'H' << flush; 
            }
            else if (is_robot(j, i, robots)==1) {
                cout << 'R' << flush;
            }
            else if (is_robot(j, i, robots)==2) {
                cout << 'r' << flush;
            }
            else if (is_post(maze.getWidth(), maze.getHeight(), j, i, maze.getPosts())) {
                cout << '*' << flush;
            }
            else {
                cout << ' ' << flush;
            }
        }

        cout << "\n";
    }

}

void Game::moveTurn(vector< Robot > &robots, Player &player){
    char move;
    cout << "Choose a move" << endl;
    cin >> move;
    if(move == 'q' || move == 'Q'){
        if(is_robot(player->getX() - 1, player.getY - 1, robots) != 2){
            player->setX(player->getX() - 1);
            player->setY(player->getY() - 1);
        }

    } else if(move == 'w' || move == 'W'){
        if(is_robot(player->getX(), player->getY() - 1, robots) != 2)
            player->setY(player->getY() - 1);

    } else if(move == 'e' || move == 'E'){
        if(is_robot(player.x + 1, player.y - 1, robots) != 2){
            player->setX(player->getX() + 1);
            player->setY(player->getY() - 1);
        }

    } else if(move == 'a' || move == 'A'){
        if(is_robot(player.x - 1, player.y, robots) != 2)
            player->setX(player->getX() - 1);

    } else if(move == 's' || move == 'S'){

    } else if(move == 'd' || move == 'D'){
        if(is_robot(player.x + 1, player.y, robots) != 2)
            player->setX(player->getX() + 1);

    } else if(move == 'z' || move == 'Z'){
        if(is_robot(player.x - 1, player.y + 1, robots) != 2){
            player->setX(player->getX() - 1);
            player->setY(player->getY() + 1);
        }

    } else if(move == 'x' || move == 'X'){
        if(is_robot(player.x, player.y - 1, robots) != 2)
            player->setY(player->getY() + 1);

    } else if(move == 'c' || move == 'C'){
        if(is_robot(player.x + 1, player.y + 1, robots) != 2){
            player->setX(player->getX() + 1);
            player->setY(player->getY() + 1);
        }

    } else
        cerr << "Invalid move!" << endl;

    robot_movement(player, robots);
}

int Game::play_game(int mapNumber){
    Maze *maze = new Maze(0, 0);
    Player *player = new Player(0, 0);
    vector< *Robot > robots;

    bool playing = true; 
    bool victorious = false;
    bool allRobotsDeadCheck = false;

    input_map(maze, robots, player, mapNumber);


    draw(maze, robots, player);

    time_t time1, time2, elapsedTime;

    srand((unsigned int) time(NULL));

    time1 = time(NULL);
    /*
    while(1){
        moveTurn(robots, robotStatus, player);
        robot_collision(robots, robotStatus, fences);
        if(is_alive(mapSize, robots, fences, player)){
            draw(mapSize, fences, robots, player);
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
    */

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
