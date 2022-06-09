// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
// 相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
// 小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
// 小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
// 正常使用时，连写的数字重复不得超过三次。
// 哈希
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map = { {'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D', 500},
                                        {'M', 1000}
                                    };
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(map[s[i]] >= map[s[i+1]])
                res += map[s[i]];
            else
                res -= map[s[i]];
        }
        return res;
    }
};
// 数组 much faster！
class Solution {
public:
    int romanToInt(string s) {
        int chars[89], ans = 0;	// ASCII of 'X' is 88!
        chars['I'] = 1; chars['V'] = 5; chars['X'] = 10; chars['L'] = 50;
        chars['C'] = 100; chars['D'] = 500; chars['M'] = 1000;
        s += 'I'; //防溢出
        for (int i = 0; i < s.size() - 1; ++i) {
            if (chars[s[i]] >= chars[s[i + 1]])
                ans += chars[s[i]];
            else ans -= chars[s[i]];
        }
        return ans;
    }
};
