// 给你两个二进制字符串，返回它们的和（用二进制表示）
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0)
        {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res.insert(res.begin(), (sum & 1) + '0');
            carry = sum >> 1;
        }
        return carry == 1 ? "1" + res : res;
    }
};