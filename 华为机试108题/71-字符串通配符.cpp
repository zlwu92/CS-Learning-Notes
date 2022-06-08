// 问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
// 要求：
// 实现如下2个通配符：
// *：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
// ？：匹配1个字符
// 输入：
// 通配符表达式；
// 一组字符串。
// 输出：
// 返回匹配的结果，正确输出true，错误输出false
// 输入描述:
// 先输入一个带有通配符的字符串，再输入一个需要匹配的字符串
// 输出描述:
// 返回匹配的结果，正确输出true，错误输出false
// 输入
// 复制
// te?t*.*
// txt12.xls
// 输出
// 复制
// false
//第六十九题  字符串通配符
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int match_string(string m_str, string w_str) //match wildcard 通配符
{
	int m_len = m_str.size(); // 待匹配字符串
	int w_len = w_str.size(); // 通配符字符串
	vector<vector<int> > b_dp(w_len + 1, vector<int>(m_len + 1, 0));
	//多加一行一列作为初始初值所用
	b_dp[0][0] = 1;
	for (int i = 1; i <= w_len; i++)
	{
		char ch = w_str[i - 1];
		////设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
		b_dp[i][0] = b_dp[i - 1][0] && (ch == '*');
		for (int j = 1; j <= m_len; j++)
		{
			char ch2 = m_str[j - 1];
			if (ch == '*')
				b_dp[i][j] = b_dp[i - 1][j] || b_dp[i][j - 1]; //当匹配字符为*号时，状态取决于上面状态和左边状态的值
			else
				b_dp[i][j] = b_dp[i - 1][j - 1] && (ch == '?' || ch2 == ch);//决定于上一次和本次
		}
	}
	return b_dp[w_len][m_len];
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int rst = match_string(str2, str1);
		if (rst == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}