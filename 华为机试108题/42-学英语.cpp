// 数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；
// 输出格式为twenty two；
// 非法数据请返回“error”；
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int getNumLen(long lNum)
{
    int nLen = 0;
    while(lNum / 10 >= 0)
    {
        lNum /= 10;
        nLen++;
    }

    return nLen;
}
#define MAX_SIZE 0x500
std::string g_Output;
void Trans1(int n)
{
    switch(n)
    {
    case 1:
        g_Output += "one ";
        break;
    case 2:
        g_Output += "two ";
        break;
    case 3:
        g_Output += "three ";
        break;
    case 4:
        g_Output += "four ";
        break;
    case 5:
        g_Output += "five ";
        break;
    case 6:
        g_Output += "six ";
        break;
    case 7:
        g_Output += "seven ";
        break;
    case 8:
        g_Output += "eight ";
        break;
    case 9:
        g_Output += "nine ";
        break;
    }
}
void Trans2(int n)
{
    switch(n)
    {
    case 0:
        g_Output += "ten ";
        break;
    case 1:
        g_Output += "eleven ";
        break;
    case 2:
        g_Output += "twelve ";
        break;
    case 3:
        g_Output += "threeteen ";
        break;
    case 4:
        g_Output += "fourteen ";
        break;
    case 5:
        g_Output += "fifteen ";
        break;
    case 6:
        g_Output += "sixteen ";
        break;
    case 7:
        g_Output += "seventeen ";
        break;
    case 8:
        g_Output += "eighteen ";
        break;
    case 9:
        g_Output += "nineteen ";
        break;
    }
}
void Trans3(int n)
{
    switch(n)
    {
    case 2:
        g_Output += "twenty ";
        break;
    case 3:
        g_Output += "thirty ";
        break;
    case 4:
        g_Output += "forty ";
        break;
    case 5:
        g_Output += "fifty ";
        break;
    case 6:
        g_Output += "sixty ";
        break;
    case 7:
        g_Output += "seventy ";
        break;
    case 8:
        g_Output += "eighty ";
        break;
    case 9:
        g_Output += "ninety ";
        break;
    }
}
void Trans(int lHigh)
{
    if(lHigh / 100 > 0)
    {
        Trans1(lHigh / 100);
        g_Output += "hundred ";
        lHigh %= 100;
        if(lHigh > 0)
        {
            g_Output += "and ";
        }
    }

    if(lHigh / 10 > 0)
    {
        if(lHigh / 10 == 1)
        {
            Trans2(lHigh % 10);
            return;
        }

        Trans3(lHigh / 10);
    }

    lHigh %= 10;
    if(lHigh)
    {
        Trans1(lHigh);
    }

    return;
}
int getLen(long lNum)
{
    int nCunt = 0;
    while(lNum)
    {
        nCunt++;
        lNum /= 10;
    }
    return nCunt;
}
int main()
{
    char szInput[MAX_SIZE] = {0};
    while(scanf("%s", szInput) != EOF)
    {
        if(strlen(szInput) > 9)
        {
            printf("error");
            return 0;
        }

        if(szInput[0] == '-')
        {
            printf("error");
            return 0;
        }

        if(std::string(szInput).find('.') != -1)
        {
            printf("error");
            return 0;
        }

        int nLen = strlen(szInput);
        long lNum = atol(szInput);

        if(0 == lNum)
        {
            printf("zero");
            return 0;
        }

        while(1)
        {
            int lHigh = 0;
            if(nLen >= 7)
            {
                lHigh = lNum / 1000000;
                Trans(lHigh);
                lNum = lNum % 1000000;
                g_Output += "million ";
                nLen = getLen(lNum);
            }
            else if(nLen >= 4)
            {
                lHigh = lNum / 1000;
                Trans(lHigh);
                lNum = lNum % 1000;
                g_Output += "thousand ";
                nLen = getLen(lNum);
            }
            else
            {
                Trans((int)lNum);
                break;
            }
        }
        memset(szInput, 0, MAX_SIZE);
        printf("%s\n", g_Output.c_str());
        g_Output.clear();
    }
    return 0;
}