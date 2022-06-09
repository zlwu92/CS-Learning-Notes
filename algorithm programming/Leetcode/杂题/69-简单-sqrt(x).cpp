// 牛顿迭代法
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)    return x;
        double res = 1.0f, curVal = 0;
        // 要求 x2 = n 的解，令 f(x)=x2-n，相当于求解 f(x)=0 的解
        // xi+1=xi - f(xi) / f'(xi)
        // xi+1=xi - (xi2 - n) / (2xi) = (xi + n/xi) / 2
        while(abs(curVal - res) > 1e-6)
        {
            curVal = res;
            res = (res + x/res) / 2;
        }
        return res;
    }
};