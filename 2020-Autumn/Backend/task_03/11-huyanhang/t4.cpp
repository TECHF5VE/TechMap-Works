#include<iostream>
using namespace std;
void moveZeroes(int nums[],int length)
{
	int temp = 0;
	for (int i = 0; i < length; i++) {
		if (nums[i] == 0) 
		{
			temp++; 
		}
		else if (temp != 0)
		{
			nums[i - temp] = nums[i];
			nums[i] = 0;
		}
	}
}
int main()
{
	cout << "******以下为测试用例******" << endl;
	const int length = 5;
	int nums[length] = { 0,1,0,3,12 };
	cout << "原数组为：";
	for (int i = 0; i < length; i++)
	{
		cout << nums[i] << " ";
	}cout << endl;
	moveZeroes(nums, length);
	cout << "移动后数组为：";
	for (int i = 0; i < length; i++)
	{
		cout << nums[i] << " ";
	}

}
