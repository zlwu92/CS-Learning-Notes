// 数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，
// 即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
// 输入描述:
// 先输入键值对的个数
// 然后输入成对的index和value值，以空格隔开
// 输出描述:
// 输出合并后的键值对（多行）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int key;
    int value;
    bool operator  == (const Pair& x)
    {
        return key == x.key;
    }
};
bool cmp(const Pair& x, const Pair& y)
{
    return x.key < y.key;
}

int main()
{
    int n;
    vector<Pair> pairs;
    pairs.reserve(1024);
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            Pair p;
            cin >> p.key >> p.value;
            vector<Pair>::iterator it = find(pairs.begin(), pairs.end(), p); //algorithm
            if(it != pairs.end())
                it->value += p.value;
            else
                pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end(), cmp);
        for(int i = 0; i < pairs.size(); ++i)
        {
            cout << pairs[i].key << " " << pairs[i].value << endl;
        }
    }
    return 0;
}