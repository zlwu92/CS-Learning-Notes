// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 假设 nums1 和 nums2 不会同时为空。
// 执行用时 :16 内存消耗 :7.4 MB
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m<=0 && n<=0)	return 0;
        if(m==1 && n==0)    return nums1[0]*1.f;
        if(m==0 && n==1)    return nums2[0]*1.f;
        vector<int> first_half(1+(m+n)/2, -1);
        int count = 0;
        int start1 = 0, start2 = 0;
        int N = first_half.size();
        while(count < N)
        {
            if(start1<m && start2<n)
            {
                if(nums1[start1] <= nums2[start2])
                {
                    first_half[count++] = nums1[start1];
                    start1++;
                }
                else
                {
                    first_half[count++] = nums2[start2];
                    start2++;
                }
            }
            else if(start1 == m)
            {
                first_half[count++] = nums2[start2];
                start2++;  
            }
            else if(start2 == n)
            {
                first_half[count++] = nums1[start1];
                start1++;
            }
            
        }
        return ((m+n)%2==0) ? (first_half[N-1]+first_half[N-2])*1.f/2.f : first_half[N-1]*1.f;
        // if((m+n)%2!=0) first_half[N-2] = first_half[N-1];
        // return (first_half[N-1]+first_half[N-2])*1.f/2.f;
    }
};
// 执行用时 :12 内存消耗 :7.3 MB
// 二分查找
class Solution {
    int len1;
    int len2;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<=0 && nums2.size()<=0)
            return 0;
        len1 = nums1.size();
        len2 = nums2.size();
        int left = (len1+len2+1)/2,right = (len1+len2+2)/2;
        return (find(nums1,0,nums2,0,left) +  find(nums1,0,nums2,0,right) )/2.0;        
    }
    //i,j代表索引（0开始），k代表第几个数（1开始）在两个有序数组中找到第K个元素
    int find(vector<int>& nums1,int i,vector<int>& nums2,int j,int k) 
    {
        if(i>=nums1.size()) return nums2[j+k-1];    //对应情况1
        if(j>=nums2.size()) return nums1[i+k-1];	//对应情况1
        if(k == 1)	return min(nums1[i],nums2[j]);  //对应情况2
        int midval1 = i+k/2-1 < nums1.size() ? nums1[i+k/2-1]:INT_MAX;  //以下是情况3
        int midval2 = j+k/2-1 < nums2.size() ? nums2[j+k/2-1]:INT_MAX;
        if(midval1<midval2)
            return find(nums1,i+k/2,nums2,j,k-k/2);
        else
            return find(nums1,i,nums2,j+k/2,k-k/2);
    }
};