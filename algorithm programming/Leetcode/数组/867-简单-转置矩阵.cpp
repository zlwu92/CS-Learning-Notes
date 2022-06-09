// 给定一个矩阵 A， 返回 A 的转置矩阵。
// 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> res(n, vector<int>(m));
		for (int i = 0; i < m; ++i)
        {
			for (int j = 0; j < n; ++j)
            {
				res[j][i] = A[i][j];
			}
		}
		return res;
    }
};