#include <iostream>
#include <bits/stdc++.h> 

int main(){
    int in[3], max = -999999, min = 9999999;
    for(int i = 0; i < 3; i++){
        std::cin >> in[i];
        if(in[i] > max)
            max = in[i];
        else if(in[i] < min)
            min = in[i];
    }
    int n = sizeof(in) / sizeof(in[0]);
    std::sort(in, in + n);
    for(int i = 0; i < n; i++){
        std::cout << in[i] << std::endl;
    }
    std::cout <<"max = "<< max << std::endl;
    std::cout <<"min = "<< min << std::endl;



}