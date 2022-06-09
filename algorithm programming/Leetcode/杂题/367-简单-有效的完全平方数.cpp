class Solution {
public:
    bool isPerfectSquare(int num) {
        // 二分查找的思想
        int left = 0, right = num;
        while(left <= right)
        {
            long mid = left + (right-left) / 2;
            long square = mid * mid; // 防止大数溢出
            if(square == num)    return true;
            else if(square > num)   right = mid - 1;
            else if(square < num)   left = mid + 1;
        }
        return false;
    }
};