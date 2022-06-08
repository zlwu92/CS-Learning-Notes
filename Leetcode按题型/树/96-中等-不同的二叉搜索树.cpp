// 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//                 1                        n = 1
//             2        1                   n = 2
//            /          \
//           1            2
// 1         3     3      2      1          n = 3
// \       /     /      / \      \
//  3     2     1      1   3      2
// /     /       \                 \
// 2     1         2                 3
// 卡塔兰数列的递推式为：
// C[0] = 1, C[1] = 1, C[n] = sum(C[i] * C[n-i])	for i = 0, ..., n
class Solution {
public:
    int numTrees(int n) {
        // Cartalan number
        vector<int> dp(n+1); // 0,...,n
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i-1 - j];
            }
        }
        return dp[n];
    }
};