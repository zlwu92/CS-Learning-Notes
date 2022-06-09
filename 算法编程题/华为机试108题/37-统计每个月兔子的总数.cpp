// arr[i]=arr[i-1]+arr[i-2];
#include <iostream>
using namespace std;
int getTotalCount(int month)
{
    if(month==1 || month==2)    return 1;
    return getTotalCount(month-1) + getTotalCount(month-2);
}
int main()
{
    int month;
    while(cin >> month)
    {
        cout << getTotalCount(month) <<endl;
    }
    return 0;
}