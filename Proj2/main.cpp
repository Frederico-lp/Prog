//T08G06
#include <iostream>
#include "Game.h"
#include "Menu.h"

int main(){
    Game game;
    int option;
    option = print_menu();
    switch (option)
    {
        case 0:
            break;
        case 1:
            if(show_rules())
                game.play_game(select_map());
            break;
        case 2:
            game.play_game(select_map());
            break;
        default:
            cout<<"Option not valid.\n";
            break;
    }


    return 0;
}