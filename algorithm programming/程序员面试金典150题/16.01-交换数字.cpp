// 编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
// 位运算
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1]; // 获取a，b整数位所有不同的信息
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};