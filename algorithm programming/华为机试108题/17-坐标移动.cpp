// 开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。
// 从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
// 输入：
// 合法坐标为A(或者D或者W或者S) + 数字（两位以内）
// 坐标之间以;分隔。
// 非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
// 下面是一个简单的例子 如：
// A10;S20;W10;D30;X;A1A;B10A11;;A10;
// 处理过程：
// 起点（0,0）
// +   A10   =  （-10,0）
// +   S20   =  (-10,-20)
// +   W10  =  (-10,-10)
// +   D30  =  (20,-10)
// +   x    =  无效
// +   A1A   =  无效
// +   B10A11   =  无效
// +  一个空 不影响
// +   A10  =  (10,-10)
// 结果 （10， -10）
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
bool is_valid(string s, int& op, int &pointer)
{
    if(s.size()<2||s.size()>3)    return false;
    char point = s[0];
    if(point!='W' && point!='S' && point!='A' && point!='D')    return false;
    else if(point == 'W')    pointer=2;
    else if(point == 'A')    pointer=0;
    else if(point == 'S')    pointer=3;
    else    pointer=1;
    string response = s.substr(1);
    size_t index = 0;
    auto res = std::stoi(response, &index);
    if(index == response.size())    op = res; // 为了保证后面的部分全为数字，这样才合法！
    else    return false;
    return true;
}
int main(int argc,char **argv)
{
    string input;
    while(getline(cin,input))
    {
        stringstream ss(input);
        vector<string> steps;
        int x=0;
        int y=0;
        while(ss.good())
        {
            string step;
            int op = -1;
            int pointer = -1;
            getline(ss, step, ';');
            if(is_valid(step, op, pointer))
            {
                //op: 0 -A -x | 1 -D +x | 2 -W +y | 3 -S -y
                if(pointer == 0)    x -= op;
                else if(pointer == 1)    x += op;
                else if(pointer == 2)    y += op;
                else    y -= op;
            }
        }
        cout << x << "," << y << endl;
    }
    return 0;
}