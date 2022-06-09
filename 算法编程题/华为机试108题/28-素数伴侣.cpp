// 若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。
// 现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，
// 例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，
// 而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
// 输入:
// 有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
// 输出:
// 输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
// 二分图最大匹配问题
// 首先明确只有一个偶数和一个奇数相加才会产生一个素数
// 是否有好感的判定就是用一个 isPrime函数即可
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <stdlib.h>
using namespace std;
// girl[j]表示 j 号女生的配偶编号
// used[j] 在当前挑选过程中，j号女生被used[j]号男生宣布了主权
int used[100];
int girl[100];
vector<int> even(1); //存放输入的偶数
vector<int> odd(1); //存放输入的奇数
bool isPrime(int n)
{
    if(n==1 || n==2)    return true;
    int k = sqrt(n);
    for(int i = 2; i <=k; ++i)
    {
        if(n%i == 0)    return false;
    }
    return true;
}
int isFind(int x)
{
    for(int j = 1; j < odd.size(); ++j)
    {
		if( used[j]==0 && isPrime(x+odd[j]) ) // 互有好感且女生没有被宣布主权
        {
			used[j] = x; // x号男生对 j 号女生宣布主权
            // 如果名花无主 or 名花有主的情况下，看能不能让这个主腾一下位置
			if( girl[j]==0 || isFind(girl[j]) )
            {
				girl[j] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
    int n, input;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
        {
            cin >> input;
            if(input%2 == 0)    even.push_back(input);
            else    odd.push_back(input);
        }
        int count = 0;
        memset(girl, 0, sizeof(girl));		
		for(int i = 1; i < even.size(); ++i)
        {
			memset(used, 0, sizeof(used)); // 处理i号男生时候0个女生被宣布主权
			count += isFind(even[i]);
		}
        cout << count << endl;
        odd.clear();
        even.clear();
		odd.push_back(1);
		even.push_back(1);
    }
    return 0;
}