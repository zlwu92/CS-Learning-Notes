// 在未排序的数组中找到第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int size = nums.size();
        int target = size - k;
        int left = 0;
        int right = size - 1;
        while (true)
        {
            int p = partition(nums, left, right);
            if (p == target) {
                return nums[p];
            } else if (target < p) {
                right = p - 1;
            } else {
                left = p + 1;
            }
        }
    }
    int partition(vector<int> &nums, int left, int right)
    {
        // 随机在 [left, right] 中, 选择一个数值作为标定点 pivot
        swap(nums[left], nums[rand() % (right - left + 1) + left]);
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right & nums[right] >= pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right & nums[left] < pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

