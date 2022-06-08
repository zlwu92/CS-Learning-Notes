// 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（重复的也要列举）（如180的质因子为2 2 3 3 5 ）
// 最后一个数后面也要有空格
// 输入描述:
// 输入一个long型整数
// 输出描述:
// 按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
#include <iostream>
using namespace std;

int main()
{
    long input;
    while(cin >> input)
    {
        while(input > 1)
        {
            for(int i = 2; i <= input; ++i) // faster than sqrt(input)
            {
                if(input%i == 0)
                {
                    input /= i;
                    cout << i << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
