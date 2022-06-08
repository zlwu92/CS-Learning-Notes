// 计算两个字符串的最大公共字串的长度，字符不区分大小写
// 计算两个字符串的最大公共字串的长度，字符不区分大小写
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp(string s1, string s2){
	if (s1.empty() || s2.empty())  return 0;
	int maxsub = 0;
	vector<vector<int>> dp(s1.size(), vector<int>(s2.size(),0));
	for (int i = 0; i < s1.size(); ++i){
		for (int j = 0; j < s2.size(); ++j){
			if (s1[i] == s2[j]){
				if (i - 1 >= 0 && j - 1 >= 0)  dp[i][j] = dp[i - 1][j - 1] + 1;
				else  dp[i][j] = 1;
			}
			maxsub = max(maxsub, dp[i][j]);   //更新最大子串长度；
		}
	}
	return maxsub;
}
int main(){
	string s1, s2;
	while (cin >> s1 >> s2){  //动态规划；
		cout << dp(s1, s2) << endl;
	}
	return 0;
}