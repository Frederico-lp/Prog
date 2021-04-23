#include <iostream>
using namespace std;
int main()
{
    int a, b, c, sec, min, hours, days, div;
    char temp;
    cout << "Time1 (hours minutes seconds) ?\n";
    cin >> c >> temp >> b >> temp >> a;
    sec = a;
    min = b;
    hours = c;
    days = 0;
    cout << "Time2 (hours minutes seconds) ?\n";
    cin >> c >> temp >> b >> temp >> a;
    sec += a;
    if(sec > 60){
        div = sec / 60;
        sec %= 60;
        min += div;
    }
    min += b;
    if(min > 60){
        div = min / 60;
        min %= 60;
        hours += div;
    }
    hours += c;
    if(hours > 24){
        div = hours / 24;
        hours %= 24;
        days += div;
    }

    cout << days << " day(s), " << hours << " hours, " << min << " minutes and " << sec << " seconds\n";


    return 0;

}