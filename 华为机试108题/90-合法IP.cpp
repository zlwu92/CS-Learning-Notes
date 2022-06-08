// 现在IPV4下用一个32位无符号整数来表示，一般用点分方式来显示，
// 点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此不需要用正号出现），
// 如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。
// 现在需要你用程序来判断IP是否合法。
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        // 1. 先判断有无3个.
        int count = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == '.')    count++;
        }
        if(count == 3)
        {
            int flag = 0;
            for(int i = 0; i < 4; ++i)
            {
                int index = str.find(".");
                string tmp = str.substr(0, index);
                bool isNum = true;
                int sum = 0;
                int n = tmp.size();
                // 2. 判断每个部分是否为数字字符串
                for(int j = 0; j < n; ++j)
                {
                    if(tmp[j]>='0' && tmp[j]<='9')
                    {
                        sum += (tmp[j]-'0') * pow(10, n-j-1);
                    }
                    else
                    {
                        sum = -1;
                        break;
                    }
                }
                // 3.  判断每个数字是否 <= 255
                if(sum>=0 && sum <= 255)
                {
                    flag++;
                    str = str.substr(index+1);
                }
                else
                {
                    cout << "NO" << endl;
                    break;
                }
            }
            if(flag == 4)    cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}