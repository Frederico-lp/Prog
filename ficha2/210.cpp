#include <iostream>
#include <bits/stdc++.h> 
#include <list>
using namespace std;


bool prime(int num){
    if(num == 1 || num == 2)
        return true;

    for(int i = 2; i <= sqrt(num); i++){
        if( (num % i) == 0)
            return false;
    }
    return true;

}

int main(){
    int num, i = 2;
    list<int> sol; 
    list<int> it; 
    cout << "Choose a number: ";
    cin >> num;
    while(num != 1 && i <= num){
        if(prime(i) && (num % i == 0)){
            sol.push_back(i);
            num /= i;
            i = 1;
            
        }
        i++;
    }
    for (auto const& i : sol){
        cout << i << " ";
    }
    return 0;


}