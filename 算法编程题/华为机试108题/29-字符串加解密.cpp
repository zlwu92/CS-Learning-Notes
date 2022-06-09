// 1、对输入的字符串进行加解密，并输出。
// 2加密方法为：
// 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
// 当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
// 其他字符不做变化。
// 3、解密方法为加密的逆过程。
#include <iostream>
#include <string>
using namespace std;

string & code(string &s)
{
    for(int i=0;i<s.size();++i)
    {
        if(std::isalpha(s[i]))
        {
            if(s[i]<='z'&&s[i]>='a')
            {
                if(s[i]=='z')
                {
                    s[i]='A';
                }
                else
                {
                    s[i]=std::toupper(s[i])+1;
                }
            }
            else
            {
                if(s[i]=='Z')
                {
                    s[i]='a';
                }
                else
                {
                    s[i]=std::tolower(s[i])+1;
                }
            }
        }//end if
        else if(std::isalnum(s[i]))
        {
            if(s[i]=='9')
                s[i]='0';
            else
                s[i]=s[i]+1;
        }
    }
    return s;
}
string & decode(string &s)
{
    for(int i=0;i<s.size();++i)
    {
        if(std::isalpha(s[i]))
        {
            if(s[i]<='z'&&s[i]>='a')
            {
                if(s[i]=='a')
                {
                    s[i]='Z';
                }
                else
                {
                    s[i]=std::toupper(s[i])-1;
                }
            }
            else
            {
                if(s[i]=='A')
                {
                    s[i]='z';
                }
                else
                {
                    s[i]=std::tolower(s[i])-1;
                }
            }
        }//end if
        else if(std::isalnum(s[i])) // 判断字符变量c是否为字母或数字
        {
            if(s[i]=='0')
                s[i]='9';
            else
                s[i]=s[i]-1;
        }
    }
    return s;
}
int main()
{
    string str1 = "", str2 = "";
    while(cin >> str1 >> str2)
    {
        str1 = code(str1);
        str2 = decode(str2);
        cout << str1 << endl;
        cout << str2 << endl;
    }
    return 0;
}

// 法2
#include<iostream>
#include <string>
using namespace std;
 
int main(){
    string a, b;
    while (cin >> a >> b){
        int i = 0;
        while (i < a.size()) {  //字符串加密；
            if (a[i] >= 'a'&&a[i] <= 'z'){
                if (a[i] != 'z')  a[i] += 1 - 'a' + 'A';
                else a[i] = 'A';
            }
            else if (a[i] >= 'A'&&a[i] <= 'Z'){
                if (a[i] != 'Z')  a[i] += 1 - 'A' + 'a';
                else a[i] = 'a';
            }
            else if (isdigit(a[i]))  {
                if (a[i] != '9') a[i]+=1;
                else a[i] = '0';
            }
            ++i;
        }
        i = 0;
        while (i < b.size()){    //字符串解密；
            if (b[i] >= 'A'&&b[i] <= 'Z'){
                if (b[i] != 'A')  b[i] =b[i]- 1 - 'A' + 'a'; //强调一点，b[i]-=1 - 'A' + 'a'相当于b[i]=b[i]-(1 - 'A' + 'a');
                else b[i] = 'z';
            }
            else if (b[i] >= 'a'&&b[i] <= 'z'){
                if (b[i] != 'a')  b[i] = b[i] - 1 - 'a' + 'A';
                else b[i] = 'Z';
            }
            else if (isdigit(b[i]))  {
                if (b[i] != '0') b[i] -=  1;
                else b[i] = '9';
            }
            ++i;
        }
        cout << a << endl << b << endl;
    }
    return 0;
}