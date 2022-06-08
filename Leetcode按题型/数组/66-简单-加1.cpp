// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if(digits[i] == 9)  digits[i] = 0;
            else
            {
                digits[i] += 1;
                return digits; // 一旦不要进位，就可以立马结束了
            }
        }
        if(digits[0] == 0)  digits.insert(digits.begin(), 1);
        return digits;
    }
};