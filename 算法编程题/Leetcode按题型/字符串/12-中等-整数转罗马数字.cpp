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
class Solution {
public:
    string intToRoman(int num) {
        char* c[4][10] = {
            {"","M","MM","MMM"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","I","II","III","IV","V","VI","VII","VIII","IX"} };  // char* is faster than vector<string>
        string res = "";
        res.append(c[0][num / 1000]);    
        res.append(c[1][(num % 1000) / 100]);
        res.append(c[2][(num % 100) / 10]);
        res.append(c[3][num % 10]);
        return res;
    }
};