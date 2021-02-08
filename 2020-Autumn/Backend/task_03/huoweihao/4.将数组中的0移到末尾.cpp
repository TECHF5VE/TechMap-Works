#include<iostream>
using namespace std;
void moveZeroes(int* nums, int length) {
	for (int i = 0; i < length - 1; i++)
		if (nums[i] == 0)
		{
			for (int j = i + 1; j < length; j++)
				nums[j - 1] = nums[j];
			nums[length - 1] = 0;
		}
}
int main()
{
	return 0;
}