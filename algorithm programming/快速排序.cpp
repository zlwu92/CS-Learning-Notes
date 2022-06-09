// 1. 首先在序列中找一个数做基准数a
// 2. 将这个序列中所有比a大的数放在a的右边，比基准数小的数放在a的左边
// 3. 从初始序列“6  1  2 7  9  3  4  5 10  8”两端开始“探测”。先从右往左找一个小于6的数，再从左往右找一个大于6的数，然后交换他们
// 4. 当哨兵i和哨兵j相遇，说明此时“探测”结束。我们将a和arr[i]进行交换
// 平均时间复杂度为O(NlogN)
// 快速排序,说白了就是给基准数据找其正确索引位置的过程
// 当基准数选择最左边的数字时，那么就应该先从右边开始搜索；
// 当基准数选择最右边的数字时，那么就应该先从左边开始搜索。不论是从小到大排序还是从大到小排序！
// 递归法，升序
#include <iostream>
#include <vector>
using namespace std;
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)	return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)	j--;
		while (arr[i] <= base && i < j)	i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);
	quickSort(i + 1, right, arr);
}
int main()
{
    int n;// = 5;
    while(cin >> n)
    {
        vector<int> input;// = {2, 2, 5, 4, 1};
        for(int i = 0; i < n; ++i)    cin >> input[i];
        quickSort(0, n-1, input);
        for(int i = 0; i < n-1; ++i)    cout << input[i] << " ";
        cout << input[n-1] << endl;
    }
    return 0;
}
// 快速排序：平均nlogn，最坏n^2，不稳定 -- 快速排序最复杂的地方在于边界位置的选取
// 归并排序：平均nlogn，最坏nlogn，稳定 -- 分治递归，其核心思想是：递归的将 排好序 的子数组 组合成 排好序的 大数组。
										// 其划分的过程实质是一个平衡二叉树的过程
// 当数据量越来越大时，尽管归并排序的比较次数较少，但是归并排序后期的合并操作所花费的时间便越来越大，
// 合并操作对整体的效率影响越来越明显，包括后面大量数据的赋值操作等。
// 所以当数据量变大时，不需要专门合并的快速排序的优势就变得越发明显。
#include<iostream>
using namespace std;
void Merge(int arr[],int low,int mid,int high)
{
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=low,j=mid+1,k=0; //mid+1为第2有序区第1个元素，j指向第1个元素
    int *temp = new int[high-low+1]; //temp数组暂存合并的有序序列
    if(!temp)
    { //内存分配失败
        cout<<"error";
        return;
    }
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j]) //较小的先存入temp中
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++]=arr[i++];
    while(j<=high)//同上
        temp[k++]=arr[j++];
    for(i=low,k=0;i<=high;i++,k++)//将排好序的存回arr中low到high这区间
		arr[i]=temp[k];
    delete []temp;//删除指针，由于指向的是数组，必须用delete []
}
//用递归应用二路归并函数实现排序——分治法
void MergeSort(int arr[],int low,int high)
{
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
} 
int main()
{
    int a[10]={5,1,9,3,7,4,8,6,2,0};
    MergeSort(a,0,9);
    for(int i=0;i<10;i++)	cout<<a[i]<<" ";
    return 0;
}

// 堆排序：堆：本身就是一个完全二叉树
// 若一个结点的下标为k，那么它的父结点为(k-1)/2，其子节点为2k+1和2k+2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//堆排序的核心是建堆,传入参数为数组，根节点位置，数组长度
void Heap_build(int a[],int root,int length)
{
    int lchild = root*2+1;//根节点的左子结点下标
    if (lchild < length)//左子结点下标不能超出数组的长度
    {
        int flag = lchild;//flag保存左右节点中最大值的下标
        int rchild = lchild+1;//根节点的右子结点下标
        if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
        {
            if (a[rchild] > a[flag])//找出左右子结点中的最大值
            {
                flag = rchild;
            }
        }
        if (a[root] < a[flag])
        {
            //交换父结点和比父结点大的最大子节点
            swap(a[root],a[flag]);
            //从此次最大子节点的那个位置开始递归建堆
            Heap_build(a,flag,length);
        }
    }
}
void Heap_sort(int a[],int len)
{
    for (int i = len/2; i >= 0; --i)//从最后一个非叶子节点的父结点开始建堆
    {
        Heap_build(a,i,len);
    }
 
    for (int j = len-1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
    {
        swap(a[0],a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
        Heap_build(a,0,j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
    }
}
int main(int argc, char **argv)
{
    int a[10] = {12,45,748,12,56,3,89,4,48,2};
    Heap_sort(a,10);
 	for (int i = 0; i != 10; ++i)	cout<<a[i]<<" ";
    return 0;
}
