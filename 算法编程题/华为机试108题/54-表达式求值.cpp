// 给定一个字符串描述的算术表达式，计算出结果值。
// 输入字符串长度不超过100，合法的字符包括”+, -, *, /, (, )”，”0-9”，
// 字符串内容的合法性及表达式语法的合法性由做题者检查。本题目只涉及整型计算。
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    string s = "3*5+8-0*3-6+0+0";//"12+2*(3-1)";//
    cout << s << endl;
//    while (cin >> s)
    {
        stack<char> opera;
        vector<int> numcnt;
        string s1;
        // 中缀表达式转后缀表达式
        for (int i = 0; i<s.size(); i++)
        {
            if (s[i] >= '0'&&s[i] <= '9')
            {
                // 记录每个运算数的位数
                int tmp = 0;
                while (s[i] >= '0'&&s[i] <= '9')
                {
                    tmp++;
                    s1 += s[i];
                    i++;
                }
                i--;
                cout << "s1 = " << s1 << " " << __LINE__ << endl;
                numcnt.push_back(tmp);
            }
            else if (s[i] == '-' || s[i] == '+')
            {
                if (s[i] == '-' && (s[i - 1] == '(' ))  s1 += '0';
                while (!opera.empty() && (opera.top() == '*' || opera.top() == '/' || opera.top() == '+' || opera.top() == '-'))
                {
                    s1 += opera.top();
                    opera.pop();
                }
                cout << "s1 = " << s1 << " " << __LINE__ << endl;
                opera.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!opera.empty() && (opera.top() == '*' || opera.top() == '/'))
                {
                    s1 += opera.top();
                    opera.pop();
                }
                cout << "s1 = " << s1 << " " << __LINE__ << endl;
                opera.push(s[i]);
            }
            else if (s[i] == '(' )
                opera.push(s[i]);
            else if (s[i] == ')')
            {
                while (opera.top() != '(') // 从括号开始解析，运算最高优先级
                {
                    s1 += opera.top();
                    opera.pop();
                }
                cout << "s1 = " << s1 << " " << __LINE__ << endl;
                opera.pop();
            }
            else
                cout << "Invalid input!" << endl;
        }
        cout << "s1 = " << s1 << " " << __LINE__ << endl;
        while (!opera.empty())
        {
            s1 += opera.top();
            opera.pop();
        }
        //计算后缀表达式的值
        cout << "s1 = " << s1 << endl;
        for(int i = 0; i < numcnt.size(); ++i)  cout << numcnt[i] << " ";
        cout << endl;
        // 更新每队二元运算的结果
        stack<int> nums;
        int ind = 0;
        for (int i = 0; i<s1.size(); i++)
        {
            if (s1[i] >= '0'&&s1[i] <= '9')
            {
                int total = 0;
                while (numcnt[ind]--)
                    total = 10 * total + (s1[i++] - '0');
                i--;
                nums.push(total);
                ind++;
                cout << nums.top() << " " << __LINE__ << endl;
            }
            else
            {
                int tmp1 = nums.top();
                nums.pop();
                int tmp2 = nums.top();
                nums.pop();
                if (s1[i] == '+')
                    nums.push(tmp2 + tmp1);
                else if (s1[i] == '-')
                    nums.push(tmp2 - tmp1);
                else if (s1[i] == '*')
                    nums.push(tmp2*tmp1);
                else
                    nums.push(tmp2 / tmp1);
                cout << nums.top() << " " << __LINE__ << endl;
            }
        }
        cout << nums.top() << endl;
    }
}