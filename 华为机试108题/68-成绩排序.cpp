// 题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
// 都按先录入排列在前的规则处理。
// 注：0代表从高到低，1代表从低到高
// 输入描述:
// 输入多行，先输入要排序的人的个数，然后分别输入他们的名字和成绩，以一个空格隔开
// 输出描述:
// 按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
	string name;
	int score;
};
bool cmp1(Student a, Student b)
{
	return a.score<b.score; //升序
}
bool cmp2(Student a, Student b)
{
	return a.score>b.score; //降序
}
int main()
{
    int n;
    int mode;
    while(cin >> n)
    {
        cin >> mode;
        vector<Student> stu(n);
        for(int i = 0; i < n; ++i)    cin >> stu[i].name >> stu[i].score;
        if(mode)    stable_sort(stu.begin(), stu.end(), cmp1);
        else    stable_sort(stu.begin(), stu.end(), cmp2);
        for(int i = 0; i < n; ++i)
            cout << stu[i].name << " " << stu[i].score << endl;
    }
    return 0;
}