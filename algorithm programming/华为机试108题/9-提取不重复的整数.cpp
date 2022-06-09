// 输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
// 输入描述:
// 输入一个int型整数
// 输出描述:
// 按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// better!
int main()
{
    int n;
    vector<int> count(10, 0);
    while(cin >> n)
    {
        string str = to_string(n);
        for(int i = str.size()-1; i >= 0; --i)
        {
            if(count[stoi(str.substr(i,1))] == 0)
            {
                cout << str[i];
                count[stoi(str.substr(i,1))] = 1;
            }
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        string str=to_string(n);
        unordered_set<char>s;
        int sum=0;
        for(int i=str.size()-1;i>=0;--i)
        {
            if(s.find(str[i])==s.end())
            {
                sum*=10;
                sum+=(str[i]-'0');
                s.insert(str[i]);
            }
        }
        cout<<sum<<endl;;
    }
    return 0;
}