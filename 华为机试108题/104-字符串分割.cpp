// 输入描述:
// 首先输入数字n，表示要输入多少个字符串。连续输入字符串(输出次数为N,字符串长度小于100)。
// 输出描述:
// 按长度为8拆分每个字符串后输出到新的字符串数组，长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<string> input(n);        
        for(int i = 0; i < n; ++i)    cin >> input[i];
        for(int i = 0; i < n; ++i)
        {
            int k = input[i].size();
            for(int j = 0; j < k; j += 8)
            {
                string base("00000000");
                int l = (j+8 < k) ? 8 : k-j;
                copy(input[i].begin()+j, input[i].begin()+j+l, base.begin());
                cout << base << endl;
            }
        }
    }
    return 0;
}