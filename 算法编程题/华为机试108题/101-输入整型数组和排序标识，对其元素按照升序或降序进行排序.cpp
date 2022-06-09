// 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据）
// 排序标识：0表示按升序，1表示按降序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, mode;
    while(cin >> n)
    {
        vector<int> res(n);
        for(int i = 0; i < n; ++i)    cin >> res[i];
        cin >> mode;
        if(mode)    sort(res.begin(), res.end(), greater<int>()); // 降序
        else    sort(res.begin(), res.end());
        for(int i = 0; i < n-1; ++i)    cout << res[i] << " ";
        cout << res[n-1] << endl;
    }
    return 0;
}