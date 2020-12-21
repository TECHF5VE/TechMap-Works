#include <iostream>
using namespace std;

int findNumberInArray(int* arr, int length, int target, bool isleft)
{
	int position = 0;
	int left = 0;
	int right = length - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			position = mid;
			if (isleft)//判断左右是否还有同样的数并取其位置
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}
	return position;
}

int main()
{
	int arr[] = { 1,2,3,4,4,4,4,5,6,7 } ;
	int length = sizeof(arr) / sizeof(arr[0]);
	int target = 0;
	cout << "请输入要查找的数字：";
	cin >> target;
	int low = findNumberInArray(arr, length, target, true);
	int high = findNumberInArray(arr, length, target, false);
	int sum = high - low + 1;
	cout << "数字共有：" << sum << " 个";
	system("pause");
	return 0;
}