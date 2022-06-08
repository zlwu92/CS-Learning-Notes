// 输入描述:
// 输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票。
// 输出描述:
// 每行输出候选人的名字和得票数量
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    while(cin >> n) // 候选人数
    {
        unordered_map<string, int> map;
        string input;
        for(int i = 0; i < n; ++i)
        {
            cin >> input;
            map.insert({input, 0});
        }
        int m;
        int invalid = 0;
        cin >> m;
        for(int i = 0; i < m; ++i)
        {
            string vote;
            cin >> vote;
            if(map.find(vote) != map.end())    map[vote]++;
            else    invalid++;
        }
        unordered_map<string, int>::iterator it;
        for(it = map.begin(); it != map.end(); ++it)
            cout << it->first << " : " << it->second << endl;
        cout << "Invalid : " << invalid << endl;
    }
    return 0;
}