#include <iostream>
#include <bits/stdc++.h> 
#include <list>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &vect){
    int i, j, aux = 0;
    for (i = 0; i < vect.size(); i++){     
    // Last i elements are already in place 
        for (j = 0; j < vect.size()-i-1; j++) 
            if (vect[j] > vect[j+1]) 
                swap(vect[j], vect[j+1]);
    }
} 



void inputVector(vector<int> &vect){
    cout<<"input a vector, it ends when -123 is entered"<<endl;
    int input;
    while(cin>>input && input != -123){
        vect.push_back(input);
    }
}

int main(){
    vector<int> vect;
    inputVector(vect);
    bubbleSort(vect);
    cout<< " Sorted vector: \n";
    for(int i = 0; i < vect.size(); i++)
        cout<< vect[i]<<endl;
    

}