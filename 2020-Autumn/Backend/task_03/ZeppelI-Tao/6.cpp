#include <iostream>
using namespace std;
//使用快速排序的方法进行排序，时间复杂度不高于n^2
void quickSort(int arr[], int left, int right)
{
	if (left >= right) //判断是否成立，若不成立则结束
	{
		return;
	}
	int i, j, k;
	i = left;
	int base = arr[i];   //设置基准数，大于基准数的值放在其右侧
	j = right;           //小于基准书的值放在其左侧 
	while (i < j)        
	{   //当设置基准数位于左边时，从数组的右侧开始搜索
		while (arr[j] >= base && i < j)
		{
			j--;                        //从右边开始遇到大于其的值则跳过，小于其的值便保留
		}
		while (arr[i] <= base && i < j)
		{
			i++;
		}
		if (i < j)               //将左右保留的值互换，使得基准数左右均为小于||大于其的值
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	arr[left] = arr[i];    //基准数归位
	arr[i] = base;
	quickSort(arr, left, i - 1);   //递归左边
	quickSort(arr, i + 1, right);  //递归右边
}
int main()
{
	int arr[10] = { 3,15,8,6,22,48,1,96,71,0 };
	quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}