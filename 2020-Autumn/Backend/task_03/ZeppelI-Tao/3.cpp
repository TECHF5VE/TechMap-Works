#include <iostream>
using namespace std;

bool findNumberIn2DArray(int arr[][5], int n, int m, int target) 
{
	int i = 0;
	int j = m-1;
	while (i <= n-1 && i >= 0 && j <= m-1 && j >= 0)
	{
		if (arr[i][j] > target)
		{
			j--;
		}
		else if (arr[i][j] < target)
		{
			i++;
		}
		else if (arr[i][j] == target)
		{
			return true;
		}
			return false;
	}
}

int main()
{
	const int m = 5;
	const int n = 5;
	int target = 0;
	cout << "请输入目标数字: ";
	cin >> target;
	int arr[n][m] =
	{
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	bool ret = findNumberIn2DArray(arr, n, m,target);
	if (ret)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}
//[
//	[1, 4, 7, 11, 15],
//	[2, 5, 8, 12, 19],
//	[3, 6, 9, 16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//给定 target = 5，返回 true。
//给定 target = 20，返回 false。