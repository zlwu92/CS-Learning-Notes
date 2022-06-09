// 判断短字符串中的所有字符是否在长字符串中全部出现
// 接口说明
// 原型：
// boolIsAllCharExist(char* pShortString,char* pLongString);
// 输入参数：
//     char* pShortString：短字符串
//     char* pLongString：长字符串
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "";
    string str2 = "";
    while(cin >> str1 >> str2)
    {
        int flag;
        for(int i = 0; i < str1.size(); ++i)
        {
            flag = 0;
            for(int j = 0; j < str2.size(); ++j)
            {
                if(str1[i] == str2[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)    break;
        }
        if(flag == 1)    cout << "true" << endl;
        else    cout << "false" << endl;
    }
    
    return 0;
}
 