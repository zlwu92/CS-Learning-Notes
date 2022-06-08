// 请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
// 所有的IP地址划分为 A,B,C,D,E五类
// A类地址1.0.0.0~126.255.255.255;
// B类地址128.0.0.0~191.255.255.255;
// C类地址192.0.0.0~223.255.255.255;
// D类地址224.0.0.0~239.255.255.255；
// E类地址240.0.0.0~255.255.255.255
// 私网IP范围是：
// 10.0.0.0～10.255.255.255
// 172.16.0.0～172.31.255.255
// 192.168.0.0～192.168.255.255
// 子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
// 注意二进制下全是1或者全是0均为非法
// 注意：
// 1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时可以忽略
// 2. 私有IP地址和A,B,C,D,E类地址是不冲突的
// 输入描述:
// 多行字符串。每行一个IP地址和掩码，用~隔开。
// 输出描述:
// 统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<string> split(string str, char delimeter)
{
    stringstream ss(str);
    string token;
    vector<string> ret;
    while(getline(ss, token, delimeter))
    {
        ret.push_back(token);
    }
    return ret;
}
bool ipIsValid(vector<string> segIp)
{
    if(segIp.size()!= 4)    return false;
    else return true;
}
bool maskIsValid(vector<string> segMask)
{
    if(segMask.size()!= 4)    return false;
    bool zero = false;
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if(zero == false)
        {
            if (stoi(segMask[i].c_str()) != 255)
            {
                // 子网掩码为二进制下前面是连续的1，然后全是0
				if (stoi(segMask[i].c_str()) != 0 &&   // 0000 0000
					stoi(segMask[i].c_str()) != 128 && // 1000 0000
					stoi(segMask[i].c_str()) != 192 && // 1100 0000
					stoi(segMask[i].c_str()) != 224 && // 1110 0000
					stoi(segMask[i].c_str()) != 240 && // 1111 0000
					stoi(segMask[i].c_str()) != 248 && // 1111 1000
					stoi(segMask[i].c_str()) != 252 && // 1111 1100
					stoi(segMask[i].c_str()) != 254    // 1111 1110
                   ) 
                {
					return false;
				}
				else    zero = true;
			}
            if (stoi(segMask[i].c_str()) == 0)    count++;
        }
        else
        {
            // this seg already contains 0, then next seg must be all 0
            if(stoi(segMask[i].c_str()) != 0)    return false;
            else count++;
        }
    }
    // mask should not be all 1 or 0
    if (stoi(segMask[3].c_str()) == 255 || count == 4)    return false;
    return true;
}
int main()
{
    string str;
    //0    1    2    3    4       5             6
    //A    B    C    D    E     wrongIP/mask  private 
    vector<int> res(7,0);
    vector<string> ip;
	vector<string> mask;
    while(getline(cin, str))
    {
        vector<string> tmp = split(str, '~');
        ip = split(tmp[0], '.');
		mask = split(tmp[1], '.');
        if(maskIsValid(mask) && ipIsValid(ip))
        {
            if (stoi(ip[0].c_str()) >= 1 && stoi(ip[0].c_str()) <= 126)
            {
				++res[0];
				if (stoi(ip[0].c_str()) == 10)
					++res[6];
			}
            else if (stoi(ip[0].c_str()) >= 128 && stoi(ip[0].c_str()) <= 191)
            {
				++res[1];
				if (stoi(ip[0].c_str()) == 172)
                {
					if (stoi(ip[1].c_str()) >= 16 && stoi(ip[1].c_str()) <= 31)
						++res[6];
				}
			}
            else if (stoi(ip[0].c_str()) >= 192 && stoi(ip[0].c_str()) <= 223)
            {
				++res[2];
				if (stoi(ip[0].c_str()) == 192 && stoi(ip[0].c_str()) == 168)
					++res[6];
			}
            else if (stoi(ip[0].c_str()) >= 224 && stoi(ip[0].c_str()) <= 239)
            {
				++res[3];
			}
			else if (stoi(ip[0].c_str()) >= 240 && stoi(ip[0].c_str()) <= 255)
            {
				++res[4];
			}
        }
        else    res[5]++;
    }
    for(int i = 0; i < 6; ++i)    cout << res[i] << " ";
    cout << res[6] << endl;
    return 0;
}