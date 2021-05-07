#include <iostream>
using namespace std;
//第一道
void text01(int m, int n,int* arrA, int* arrB)
{
	int i, j;
	i = m - 1;
	j = n - 1;
	while (i >= 0 && j >= 0)
	{
		if (arrA[i] >= arrB[j]) //从后向前排序，将较大的值赋给A。
		{
			arrA[i + j + 1] = arrA[i];
			i--;
		}
		else
		{
			arrA[i + j + 1] = arrB[j];
			j--;
		}
	}
	while (j >= 0)//当B中有剩余的值时，将剩余的值赋到A中
			  //若剩余的是A中的值，则直接在数组A中
	{
		arrA[j] = arrB[j];
	}
}
int main()
{
	int arrA[7] = { 1, 2, 3, 8, 0, 0, 0 };
	int arrB[3] = { 2,5,6 };
	text01(4, 3, arrA,arrB);
	for (int i = 0; i < 7; i++)
	{
		cout << arrA[i] << "  ";
	}

	system("pause");
	return 0;
}