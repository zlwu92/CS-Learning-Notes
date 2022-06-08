// 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,
// 渊子把密码中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，
// 声明：密码中没有空格，而密码中出现的大写字母则变成小写之后往后移一位，
// 如：X，先变成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。
// 输入描述:
// 输入包括多个测试数据。输入是一个明文，密码长度不超过100个字符，输入直到文件结尾
// 输出描述:
// 输出渊子真正的密文
// 输入
// YUANzhi1987
// 输出
// zvbo9441987
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<char, char> map = {{'a', '2'}, {'b', '2'}, {'c', '2'},
                                     {'d', '3'}, {'e', '3'}, {'f', '3'},
                                     {'g', '4'}, {'h', '4'}, {'i', '4'},
                                     {'j', '5'}, {'k', '5'}, {'l', '5'},
                                     {'m', '6'}, {'n', '6'}, {'o', '6'},
                                     {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
                                     {'t', '8'}, {'u', '8'}, {'v', '8'},
                                     {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}};
    string str;
    while(cin >> str)
    {
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i]<='z' && str[i]>='a')
            {
                str[i] = map[str[i]];
            }
            else if(str[i]<='Z' && str[i]>='A')
            {
                str[i] = std::tolower(str[i]);
                if(str[i] == 'z')   str[i] = 'a';
                else    str[i] += 1;
            }
        }
        cout << str << endl;
    }
    return 0;
}