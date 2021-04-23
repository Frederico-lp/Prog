#include <iostream>
using namespace std;
int main()
{
    float a, b, c;
    float mean;
    cout << "Input 3 numbers\n";
    cin >> a >> b >> c;
    mean = (a + b + c) / 3;
    cout << "Mean = " << float(mean) << endl;
    cout << "A - mean = " << a - mean << endl;
    cout << "B - mean = " << b - mean << endl;
    cout << "C - mean = " << c - mean << endl;

    return 0;

}