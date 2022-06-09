// 给定n个字符串，请对n个字符串按照字典序排列。
// 输入描述:
// 输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
// 输出描述:
// 数据输出n行，输出结果为按照字典序排列的字符串
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    string str = "";
    // greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。
    // 其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
    // 升序 --> 小顶堆，默认是 降序 --> 大顶堆
    priority_queue<string, vector<string>, greater<string> > q;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            cin >> str;
            q.push(str);
        }
        while(!q.empty())
        {
            cout << q.top() << endl;
            q.pop();
        }
    }
    return 0;
}