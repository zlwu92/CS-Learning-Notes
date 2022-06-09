// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
// 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            // 注意：这里最好用left + (right - left) / 2计算 mid 时需要防止溢出
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            // if(nums[mid] == target) // 最右匹配
            // {
            //     while(nums[mid+1] == target) mid++;
            //     return mid;
            // }
            // if(nums[mid] == target) // 最左匹配
            // {
            //     while(nums[mid-1] == target) mid--;
            //     return mid;
            // }
            else if(nums[mid] < target) left = mid + 1;
            // else if(nums[mid] > target) right = mid - 1;
            else    right = mid - 1;
        }
        return -1;
    }
};
// 寻找左侧边界的二分搜索
int leftBoundBinarySearch(vector<int>& nums, int target)
{
    // 分析: 结果返回的index = 小于target的个数
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        // 左闭右开，找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right，
        // 在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左侧边界的目的
        int mid = (left + right) / 2;
        if (nums[mid] == target)        right = mid - 1;
        else if (nums[mid] > target)    right = mid - 1;
        else if(nums[mid] < target)     left = mid + 1; 
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.length || nums[left] != target)    return -1;
    return left;
}
// 寻找右侧边界的二分搜索
int rightBoundBinarySearch(vector<int>& nums, int target)
{
    // 完全类似
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right-left) / 2;
        // 别返回，锁定右侧边界
        if (nums[mid] == target)        left = mid + 1;
        else if (nums[mid] < target)    left = mid + 1;
        else if (nums[mid] > target)    right = mid - 1;
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target) return -1;
    return right;
}