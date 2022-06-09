// Input Param
// n               输入随机数的个数
// inputArray      n个随机整数组成的数组
// Return Value
// OutputArray    输出处理后的随机整数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    // 测试多组，故用while循环
    vector<int> out;
    out.reserve(1024);
    while(cin >> n)
    {                
        int in;
        for(int i = 0; i < n; ++i)
        {
            cin >> in;
            out.push_back(in);
        }
        // unique函数功能是去除相邻的重复元素，注意是相邻，所以必须先使用sort函数
        // unique实际上并没有删除任何元素，而是将无重复的元素复制到序列的前段，从而覆盖相邻的重复元素。
        // unique返回的迭代器指向超出无重复的元素范围末端的下一个位置
        sort(out.begin(), out.end());
        out.erase(unique(out.begin(), out.end()), out.end());
        for(int i = 0; i < out.size(); ++i)
	        cout << out[i] << endl;
        // clear不影响capacity，只把size置0
        out.clear();
    }
    // 清空 capacity
    vector<int>().swap(out);
    return 0;
}
// 计数排序
#include <iostream>
using namespace std;
 
int main() {
    int N, n;
    while (cin >> N) {
        int a[1001] = { 0 };
        while (N--) {
            cin >> n;
            a[n] = 1;
        }
        for (int i = 0; i < 1001; i++)
            if (a[i])
                cout << i << endl;
    }
    return 0;
}