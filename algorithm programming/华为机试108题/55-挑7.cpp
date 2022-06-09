// 输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数
// （一组测试用例里可能有多组数据，请注意处理）
// 输入描述:
// 一个正整数N。(N不大于30000)
// 输出描述:
// 不大于N的与7有关的数字个数，例如输入20，与7有关的数字包括7,14,17.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int count = 0;
        if(n < 7)    cout << 0 << endl;
        else
        {
            int i = 7;
            while(i <= n)
            {
                count++;
                i = 7 * (count+1);
            }
            for(int j = 17; j <= n;  ++j)
            {
                if(j%7 != 0)
                {
                    string str = to_string(j);
                    if(str.find('7') != string::npos)    count++;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}
// faster!
#include <iostream>
using namespace std;
 
int main()
{
    int N = 0, i = 0;
    int count = 0, temp = 0;
    bool flag = false;
    while(cin >> N)
	{
		count = 0;
		for(i = 7; i <= N; i++)
		{
            if(i%7 == 0)    count++;
            else
            {
                int tmp = i;
                while(tmp)
                {
                    if(tmp%10 == 7)
                    {
                        count++;
                        break;
                    }
                    tmp /= 10;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}