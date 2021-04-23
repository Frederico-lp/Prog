#include <iostream>
#include <bits/stdc++.h> 
#include <list>
using namespace std;
int gcd(int num1, int num2){
    while(1){

        if(num1 == num2)
            return num1;

        if(num1 == 0)
            return num2;
        else if(num2 == 0)
            return num1;

        else{
            if(num1 > num2)
                num1 -= num2;
            else 
                num2 -= num1;
        }
    }
}

bool readFraction(int &num, int &den)
{
    num = den = 0;
    char sep;
    cin >> num;
    cin >> sep;
    cin >> den;
    return sep == '/';
}

void reduceFraction(int &numerator, int &denominator){
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

void operation(int &numerator, int &denominator, char operation){
    switch (operation)
    {
    case '+':
        if()
        break;
    
    default:
        break;
    }
}


int main()
{
    int num, den;
    if(readFraction(num, den)){
        reduceFraction(num, den);
        cout << "Fraccao lida: " << num << " / " << den << endl;
    }
    else
        cout << "Invalid fraction\n";
    return 0;
}
