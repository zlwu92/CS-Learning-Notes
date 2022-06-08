// 题目描述
// 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
// 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
// 输入描述:
// 将一个英文语句以单词为单位逆序排放。
// 输出描述:
// 得到逆序的句子
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str = "";
    while(getline(cin, str))
    {
        vector<int> index; // 记录每个' '的下标位置
        int n = str.size();
        index.push_back(n);
        int count = 0;
        string res = "";
        for(int i = n-1; i >= 0; --i)
        {
            if(str[i] == ' ')
            {
                res += str.substr(i+1, index[count]-i-1) + " ";
                count++;
                index.push_back(i);
            }
            if(i == 0)
            {
                res += str.substr(0, index[count]-i);
            }
        }
        cout << res << endl;
    }
    return 0;
}