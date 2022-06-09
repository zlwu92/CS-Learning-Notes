// 按照指定规则对输入的字符串进行处理。
// 详细描述：
// 将输入的两个字符串合并。
// 对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标意思是字符在字符串中的位置。
// 对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，
// 并转换为相应的大写字符。如字符为‘4’，为0100b，则翻转后为0010b，也就是2。
// 转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’。
// 举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，
// 分别对“dca”和“efb”进行排序，
// 排序后为“abcedf”，转换后为“5D37BF”
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string& change(unordered_map<char, char>& dmap, string& tmp)
{
    for(int i = 0; i < tmp.size(); ++i)
    {
        if(isdigit(tmp[i]))
        {
            tmp[i] = dmap[tmp[i]];
            if(isalpha(tmp[i]))    tmp[i] = toupper(tmp[i]);
        }
        else if(toupper(tmp[i])>='A' && toupper(tmp[i])<='F')
        {
            tmp[i] = dmap[toupper(tmp[i])];
        }
    }
    return tmp;
}
int main()
{
    // 所代表的16进制的数进行BIT倒序的操作
    unordered_map<char, char> dmap = {{'0', '0'}, 
                                  {'1', '8'}, 
                                  {'2', '4'}, 
                                  {'3', 'C'}, 
                                  {'4', '2'}, 
                                  {'5', 'A'}, 
                                  {'6', '6'}, 
                                  {'7', 'E'}, 
                                  {'8', '1'}, 
                                  {'9', '9'}, 
                                  {'A', '5'}, 
                                  {'B', 'D'}, 
                                  {'C', '3'}, 
                                  {'D', 'B'}, 
                                  {'E', '7'}, 
                                  {'F', 'F'} };
    string str1 = "";
    string str2 = "";
    while(cin >> str1 >> str2)
    {
        string tmp = str1 + str2;
        int n = tmp.size();
        string s1 = "", s2 = "";
        // step1 store as even and odd
        for(int i = 0; i < n; ++i)
        {
            if((i&1) == 0)    s2 += tmp[i];
            else    s1 += tmp[i];
        }
        // step2 sort both even and odd
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int k1 = 0, k2 = 0;
        // step3 insert to generate a new string
        for(int i = 0; i < n; ++i)
        {
            if((i&1) == 0)    tmp[i] = s2[k2++];
            else    tmp[i] = s1[k1++];
        }
        // step4 final processing for string
        tmp = change(dmap, tmp);
        cout << tmp << endl;
    }
    return 0;
}