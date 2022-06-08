// 将两个整型数组按照升序合并，并且过滤掉重复数组元素
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n)
    {
        vector<int> in1(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> in1[i];
        }
        cin >> m;
        vector<int> in2(m);
        for(int i = 0; i < m; ++i)
        {
            cin >> in2[i];
        }
        vector <int> res(n+m);
        for(int i = 0; i < res.size(); ++i)
        {
            if(i < n)    res[i] = in1[i];
            else    res[i] = in2[i-n];
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        for(auto x : res)    cout << x;
        cout << endl;
    }
    return 0;
}
