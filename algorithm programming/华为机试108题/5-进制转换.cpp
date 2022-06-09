// 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）
// 输入描述:
// 输入一个十六进制的数值字符串。
// 输出描述:
// 输出该数值的十进制字符串。
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, int> dmap = {{'0', 0},
                                     {'1', 1},
                                     {'2', 2},
                                     {'3', 3},
                                     {'4', 4},
                                     {'5', 5},
                                     {'6', 6},
                                     {'7', 7},
                                     {'8', 8},
                                     {'9', 9},
                                     {'A', 10},
                                     {'a', 10},
                                     {'B', 11},
                                     {'b', 11},
                                     {'C', 12},
                                     {'c', 12},
                                     {'D', 13},
                                     {'d', 13},
                                     {'E', 14},
                                     {'e', 14},
                                     {'F', 15},
                                     {'f', 15}};
    string str = "";
    while(cin >> str)
    {
        str = str.substr(2); // jump head 0x
        long sum = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            sum *= 16;
            sum += dmap[str[i]];
        }
        cout << sum << endl;
    }
    return 0;
}