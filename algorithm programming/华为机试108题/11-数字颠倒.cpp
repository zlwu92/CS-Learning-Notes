// 描述：
// 输入一个整数，将这个整数以字符串的形式逆序输出
// 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
// 输入描述:
// 输入一个int整数
// 输出描述:
// 将这个整数以字符串的形式逆序输出
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        string str = to_string(n);
        for(int i = str.size()-1; i >= 0; --i)
        {
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
		string str;
		while(n)
		{
		    str+=to_string(n%10);
		    n/=10;
		}
		cout<<str<<endl;
    }
    return 0;
}