// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 示例 1:
// 输入:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// 输出: true
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 双指针
        if (matrix.empty() || matrix[0].empty())	return false;
        int i = 0, j = matrix[0].size() - 1; // 这样起始位置指向右上角
        while(i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)  return true;
            else if(matrix[i][j] > target)  --j;
            else if(matrix[i][j] < target)  ++i;
        }
        return false;
    }
};