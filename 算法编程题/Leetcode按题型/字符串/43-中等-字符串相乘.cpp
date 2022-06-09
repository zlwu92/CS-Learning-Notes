// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// 若 num1 长度为m，num2 长度为n，则 num1 x num2 的长度不会超过 m+n
// num1 中位置为i的数字乘以 num2 中位置为j的数字，那么得到的两位数字的位置为 i+j 和 i+j+1
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if(m==0 || n==0)    return "0";
        if(num1=="0" || num2=="0")    return "0";
        string res = "";
        vector<int> vals(m + n);
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        if(vals[0] != 0)    res.push_back(vals[0] + '0');
        for(int i = 1; i < m+n; ++i)    res.push_back(vals[i] + '0');
        return res;
    }
};