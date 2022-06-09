// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
// 示例 1:
// 输入:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出: [1,2,3,6,9,8,7,4,5]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty())	return ans;
        // 首先初始化上下左右边界
        int upper = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(true)
        {
        	// 向右 移动直到最右，重新设定第一行 上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = left; i <= right; ++i)	ans.push_back(matrix[upper][i]); 
            if(++ upper > down) break;
            // 向下，重新设定右边界，交错设定
            for(int i = upper; i <= down; ++i) ans.push_back(matrix[i][right]);
            if(-- right < left) break;
        	// 向左
            for(int i = right; i >= left; --i) ans.push_back(matrix[down][i]);
            if(-- down < upper) break;
        	// 向上
            for(int i = down; i >= upper; --i) ans.push_back(matrix[i][left]);
            if(++ left > right) break;
        }
        return ans;
    }
};
