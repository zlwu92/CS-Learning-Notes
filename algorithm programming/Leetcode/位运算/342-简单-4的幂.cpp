// 定其是2的次方数了之后，发现只要是4的次方数，减1之后可以被3整除
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};