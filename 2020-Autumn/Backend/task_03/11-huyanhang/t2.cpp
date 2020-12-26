#include<iostream>
using namespace std;


int findNumbers(int* nums, int length) {
	return length / 2;
}
int main()
{
	cout << "******以下为测试用例******" << endl;
	const int length = 5;
	int arr[length] = { 12,345,2,6,7896 };
	cout << "数组为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
	int* nums, n;
	n = length;
	nums = new int[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = arr[i];
	}
	cout << "位数为偶数的数字有：" << findNumbers(nums, length) << "个";


}
