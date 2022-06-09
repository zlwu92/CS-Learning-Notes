// 1、中文大写金额数字前应标明“人民币”字样。
// 中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。（30分） 
// 2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，
// 如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。（30分） 
// 3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，
// 如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。
#include<iostream>
#include<string>
using namespace std;

const string num_s[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
const string unit_s[9] = {"", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};
const string small_s[4] = {"角", "分"};
const string unit = "元";
const string inter = "整";

int main()
{
    double num_in = 230010.12;//1.4;//151121.15;//
//    while(cin >> num_in)
    {
        int sm = (num_in - int(num_in)) * 100 + 0.5;
        string sm_str = "";
        // 先处理小数部分
        if(sm == 0)	sm_str.append(inter); // 整数元
        else
        {
            if(sm / 10 != 0)
                sm_str.append(num_s[sm / 10] + small_s[0]);
            if(sm % 10 != 0)
                sm_str.append(num_s[sm % 10] + small_s[1]);
        }
        // 处理整数部分
        string int_res = "人民币";
        int num_int = num_in;
        string dit_trans = to_string(num_int);
        int int_len = dit_trans.length();
        bool zero_flag = false; // 把中间 “零” 作为一个标志位
        for(int i = 0; i < int_len; i ++)
        {
            if(dit_trans[i] != '0')
            {
                if(zero_flag)
                {
                    int_res.append(num_s[0]);	// 中间 “零”
                    zero_flag = false;
                }
                if(!((int_len - i) % 4 == 2 && dit_trans[i] == '1'))
                    int_res.append(num_s[dit_trans[i] - '0']);
                int_res.append(unit_s[int_len - i - 1]);
            }
            else	zero_flag = true;
        }
        if(num_int != 0)	int_res.append(unit); // 元
        cout << int_res + sm_str << endl;
    }
    return 0;
}
