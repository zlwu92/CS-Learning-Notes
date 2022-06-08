// 将非负整数转换为其对应的英文表示。可以保证给定输入小于 2^31 - 1 
// 思路：由于最高只能到billion位，3个一组也只需处理四组即可，
// 那么我们需要些一个处理三个一组数字的函数，
// 我们需要把1到19的英文单词都列出来，放到一个数组里，
// 还要把20,30，... 到90的英文单词列出来放到另一个数组里，
// 然后我们需要用写技巧，比如一个三位数n，百位数表示为n/100，后两位数一起表示为n%100，
// 十位数表示为n%100/10，个位数表示为n%10，
// 然后我们看后两位数是否小于20，小于的话直接从数组中取出单词，
// 如果大于等于20的话，则分别将十位和个位数字的单词从两个数组中取出来。
// 然后再来处理百位上的数字，还要记得加上Hundred。
// 主函数中调用四次这个帮助函数，然后中间要插入"Thousand", "Million", "Billion"到对应的位置，
// 最后check一下末尾是否有空格，把空格都删掉，返回的时候检查下输入是否为0，是的话要返回'Zero'。
class Solution {
public:
    string numberToWords(int num) {
        string res = convertHundred(num % 1000);
        vector<string> v = {"Thousand", "Million", "Billion"};
        for(int i = 0; i < v.size(); ++i)
        {
            num /= 1000;
            res = num % 1000 ? convertHundred(num % 1000) + " " + v[i] + res : res;
        }
        // 删去末尾可能的空格
        while (res.back() == ' ')   res.pop_back();
        return res.empty() ? "Zero" : res;
    }
    string convertHundred(int num)
    {
        vector<string> v1 = {"", "One", "Two", "Three", "Four", 
                             "Five", "Six", "Seven", "Eight", "Nine", 
                             "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                             "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", 
                             "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res = b < 20 ? v2[b] : v2[b/10] + (c ? " " + v1[c] : "");
        if(a > 0)   res = v1[a] + " Hundred" + (b ? " " + res : "");
        return res;
    }
};