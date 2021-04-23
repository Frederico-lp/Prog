#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int print_menu(){
    cout<<"Choose an option: \n" << "0) Exit;\n1) Rules;\n2) Play;\n";
    int option;
    cin >> option;
    return option;
}