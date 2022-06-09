// 有一种技巧可以对数据进行加密，它使用一个单词作为它的密匙。
// 下面是它的工作原理：首先，选择一个单词作为密匙，如TRAILBLAZERS。
// 如果单词中包含有重复的字母，只保留第1个，其余几个丢弃。
// 现在，修改过的那个单词属于字母表的下面，如下所示：
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
// 上面其他用字母表中剩余的字母填充完整。
// 在对信息进行加密时，信息中的每个字母被固定于顶上那行，
// 并用下面那行的对应字母一一取代原文的字母(字母字符的大小写状态应该保留)。
// 因此，使用这个密匙，Attack AT DAWN(黎明时攻击)就会被加密为Tpptad TP ITVH。
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string s1 = "nihhao"; // key
    string s2 = "niH";
//    while(cin>>s1>>s2)
    {
        // 假设密匙全为小写字符，去除26个小写字符中包含密匙的字符，
        // 并把密匙去除重复字符，只保留第一个出现的字符，然后把去重后的密匙和剩下的小写字符组成一个密码本，
        // 接着把原文加密输出就可以了。
        string s = "abcdefghijklmnopqrstuvwxyz";
        int i = 0;
        while(i < s.size())
        {
            size_t j = s1.find(s[i]);
            if(j != string::npos)
            {
                j = s1.find(s[i], j+1);  //从j的下一个位置开始查找，若j+1>=s1.size(),返回npos
                while(j!=string::npos)
                {
                    s1.erase(s1.begin() + j);  //删掉密匙中的重复字符
                    j = s1.find(s[i],j);
                }
                s.erase(s.begin()+i);   //去掉s中的密匙key
            }
            else  ++i;
        }
        cout << "s = " << s << endl; // bcdefgjklmpqrstuvwxyz
        cout << "s1 = " << s1 << endl; // nihao
        s = s1 + s;    //构成密码本
        cout << "s = " << s << endl; // nihaobcdefgjklmpqrstuvwxyz
        s1 = "";
        for(int i=0;i<s2.size();++i)
        {
            if(isupper(s2[i]))	s1 += (s[s2[i]-'A']-'a'+'A'); // 保留大小写输出
            else s1 += s[s2[i]-'a'];
        }
        cout << s1 << endl;
    }
    return 0;
}