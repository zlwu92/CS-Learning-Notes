// 对字符串中的所有单词进行倒排。
// 说明：
// 1、构成单词的字符只有26个大写或小写英文字母；
// 2、非构成单词的字符均视为 单词间隔符；
// 3、要求倒排后的 单词间隔符 以一个 空格 表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
// 4、每个单词最长20个字母；
// 输入描述:
// 输入一行以空格来分隔的句子
// 输出描述:
// 输出句子的逆序
#include<iostream>
#include<string>
#include<ctype.h> //isalpha()
#include<vector>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        string output = "";
        vector<string> result; // 经过处理存储只包含' '为分隔符的字符串
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!(isalpha(s[i])))
            {
                if (i < n - 1 && isalpha(s[i + 1]))
                    result.push_back(" ");
            }
            else
            {
                string temp = "";
                while (isalpha(s[i + 1]))
                {
                    temp += s[i];
                    i++;
                }
                temp += s[i];
                result.push_back(temp);
            }
        }
        if (result[0] == " ")  result.erase(result.begin()); //删除元素
        for (int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i];
        }
    }
    return 0;
}