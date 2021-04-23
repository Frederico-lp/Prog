#include <iostream>
#include <bits/stdc++.h> 
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
    int num;
    // cout << "Choose a number to find out if it's prime: ";
    // cin >> num;
    // for(int i = 2; i <= sqrt(num); i++){
    //     if( (num % i) == 0)
    //         cout << "It's not prime and it's first divisor is " << i << endl;
    // }
    // cout << "It's prime";
    cout << "Choose a range of numbers: ";
    cin >> num;
    for(int i = 1; i < num; i++){
        if(prime(i))
            cout << i << endl;
    }



}