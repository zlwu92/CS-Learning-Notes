#include <iostream>
using namespace std;

int main()
{
    int year, month, day;
    int dayNum[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(cin >> year >> month >> day)
    {
        bool isLeap = false; // 是否为闰年
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))    isLeap = true;
        int res = 0;
        for(int i = 0; i < month-1; ++i)    res += dayNum[i];
        res += day;
        if(isLeap)    res += 1;
        cout << res << endl;
    }
    return 0;
}