// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i)
        {
            // 每一行的首个和结尾一个数字都是1，
            // 从第三行开始，中间的每个数字都是上一行的左右两个数字之和。
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};