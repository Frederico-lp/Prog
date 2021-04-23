#include <iostream>
#include <fstream>
#include <vector> 

int main(int argc, char argv[])
{
    std::ifstream infile;
    std::ofstream outfile;
    std::vector <char> text;
    char character;
    int i = 0, j = 0;
    infile.open((const char*)argv[1], std::ios::in);
    while(!infile.eof()){
        infile.get(character);
        if(character == 'b'){
            while(character == 'b'){
                i++;
                infile.get(character);
            }
            text.push_back(i);
            text.push_back(character);
            i = 0;

        }
        if(character == 'w'){
            while(character == 'w'){
                j++;
                infile.get(character);
            }
            text.push_back(j);
            text.push_back(character);
            j = 0;

        }
        else text.push_back(character); //para os dois primeiros numeros
    }
    infile.close();
    outfile.open((const char*)argv[2], std::ios::out);
    outfile.close();


    return 0;
}