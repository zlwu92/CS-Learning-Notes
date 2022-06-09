// 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，
// 对角线遍历如下图所示。
// 示例:
// 输入:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出:  [1,2,4,7,5,3,6,8,9]
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())    return {};
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = 0;
        vector<int> res(m * n);
        for(int i = 0; i < m * n; ++i)
        {
            res[i] = matrix[r][c];
            // 根据横纵左边之和的奇偶性来判断遍历的方向
            if((r+c) % 2 == 0) // 向上
            {
                if(c == n-1)    ++r;
                else if(r == 0) ++c;
                else
                {
                    --r;    ++c;
                }
            }
            else
            {
                if(r == m-1)    ++c;
                else if(c == 0) ++r;
                else
                {
                    ++r;    --c;
                }
            }
        }
        return res;
    }
};