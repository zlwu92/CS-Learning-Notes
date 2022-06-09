// 编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符
// 方法2：利用二进制求绝对值
class Solution {
public:
    // 公式：max(a,b) = (a + b + |a - b|) / 2
    int maximum(int a, int b) {
        long sum = long(a) + long(b), diff = long(a) - long(b);
        cout << diff << " " << (diff >> 63) << endl;
        cout << (diff ^ (diff >> 63)) << endl;
        long abs_diff = (diff ^ (diff >> 63)) - (diff >> 63);
        return (sum + abs_diff) / 2;
    }
};