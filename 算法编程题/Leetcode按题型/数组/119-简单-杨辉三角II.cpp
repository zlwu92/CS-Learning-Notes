// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
// 进阶：
// 你可以优化你的算法到 O(k) 空间复杂度吗？
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        // 二项展开系数公式 C(n,k) = C(n-1, k-1) + C(n-1, k)
        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i; j >= 1; --j)
            {
                res[j] += res[j-1];
            }
        }
        return res;
    }
};