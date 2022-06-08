// 给定两个数组，编写一个函数来计算它们的交集。
// 说明：
// 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
// 我们可以不考虑输出结果的顺序。
// 进阶:
// 如果给定的数组已经排好序呢？你将如何优化你的算法？
// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
// 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto num : nums1) ++m[num];
        vector<int> res;
        for(auto num : nums2)
        {
            if(m[num]-- > 0)    res.push_back(num);
        }
        return res;
    }
};
// 双指针法
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        while (i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                ++i;    ++j;
            }
            else if(nums1[i] > nums2[j])    ++j;
            else    ++i;
        }
        return res;
    }
};
