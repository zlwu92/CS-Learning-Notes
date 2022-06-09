// 功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
// 输入: 一个byte型的数字
// 输出: 无
// 返回: 对应的二进制数字中1的最大连续数
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        // 位运算法
        int count = 0;
        while(n)
        {
            n &= (n << 1);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int n,max=0,count=0;
    while(cin>>n){
        max=0,count=0;
        while(n){
            if(n%2!=0)
                count++;
            else
                count=0;
            if(count>max)
                max=count;
            n/=2;
        }
        cout<<max<<endl;
    }
    return 0;
}