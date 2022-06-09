// 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
class Solution {
public:
    int getSum(int a, int b) {
        // 在二进制下来看，不考虑进位的加，本质上就是异或 ^
        // 如果只考虑进位的加，本质上就是 &
        while(b) // 当进位为0时终止循环
        {
            // 0x7fffffff ==> 最高位为0，其余位都为1，强制将最高位清零，然后再进行左移
            int carry = (a & b & 0x7fffffff) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;        
    }
};