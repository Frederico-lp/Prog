#include "game.hpp"
#include "menu.cpp"

int main(){
    int option;
    option = print_menu();
    switch (option)
    {
    case 0:
        break;
    case 1:
        exit(0);
        break;
    case 2:
        play_game(1);
    
    default:
    cout<<"Option not valid.\n";
        break;
    }
    if (option == 2)
        play_game(1);
        //play_game(map_number)
        

   return 0;
}