#include <iostream>
#include "Game.hpp"
#include "menu.hpp"

int main(){
    int option;
    option = print_menu();
    switch (option)
    {
    case 0:
        break;
    case 1:
        if(show_rules())
            play_game(select_map());
        break;
    case 2:
        play_game(select_map());
        break;
    default:
    cout<<"Option not valid.\n";
        break;
    }
        

   return 0;
}