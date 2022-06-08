// 一个DNA序列由A/C/G/T四个字母的排列组合组成。
// G和C的比例（定义为GC-Ratio）是序列中G和C两个字母的总的出现次数除以总的字母数目（也就是序列长度）。
// 给定一个很长的DNA序列，以及要求的最小子序列长度，研究人员经常会需要在其中找出GC-Ratio最高的子序列。
// 输入描述:
// 输入一个string型基因序列，和int型子串的长度
// 输出描述:
// 找出GC比例最高的子串,如果有多个输出第一个的子串
#include<iostream>
using namespace std;
int main()
{
    string str;
    int len;
    while(cin >> str >> len)
    {
        int index = 0, max = 0;
        for(int i = 0; i <= str.size()-len; ++i)
        {
            int counts = 0;
            for(int j = i; j < i+len; ++j) // len 固定，无需算比例
            {
                if(str[j] == 'G' || str[j] == 'C')
                    counts ++;
            }
            if(counts > max){
                max = counts;
                index = i;
            }
        }
        cout << str.substr(index, len) << endl;
    }
    return 0;
}