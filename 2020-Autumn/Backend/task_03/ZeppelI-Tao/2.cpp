#include <iostream>
using namespace std;
//样例：
//输入：nums = [12, 345, 2, 6, 7896]
//输出：2
//解释：
//因此只有 12 和 7896 是位数为偶数的数字

int findNumbers(int* nums, int length) 
{
	int sum = 0;
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		while (nums[i] > 0)
		{
			nums[i] /= 10;
			n++;
		}
		if (n % 2 == 0)
		{
			sum++;
		}
	}
	return sum;
}
int main()
{
	int nums[] = { 12, 345, 2, 6, 7896 };
	int length = sizeof(nums) / sizeof(nums[0]);
	cout<<findNumbers(nums, length)<<endl;
	system("pause");
	return 0;
}