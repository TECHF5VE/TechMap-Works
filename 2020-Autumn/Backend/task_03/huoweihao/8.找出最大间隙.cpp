#include<iostream>
using namespace std;
int MAX(int a, int b)
{
	return a >= b ? a : b;
}
int MIN(int a, int b)
{
	return a <= b ? a : b;
}
int maximumGap(int* nums, int length) {
	if (length < 2)
		return 0;

	//求原数组的最大最小值
	int max = nums[0], min = nums[0];
	for (int i = 1; i < length; i++)
	{
		max = (max >= nums[i] ? max : nums[i]);
		min = (min <= nums[i] ? min : nums[i]);
	}
	if (max == min)
		return 0;


	//设置length+1个桶
	int* maxs = new int[length + 1]{};//记录每个桶中的最大数
	int* mins = new int[length + 1]{};//记录每个桶中的最小数
	bool* has = new bool[length + 1]{ 0 };//记录桶中是否有数


	for (int i = 0; i < length; i++)
	{
		int ID = (nums[i] - min) * length / (max - min);//求出原数组某个元素的对应桶编号
		maxs[ID] = has[ID] ? MAX(nums[i], maxs[i]) : nums[i];//保留桶里数字的最大值
		mins[ID] = has[ID] ? MIN(nums[i], maxs[i]) : nums[i];//保留桶里数字的最小值
		has[ID] = 1;
	}


	int maxgap = 0;//记录最大间隙
	int lastmax;//记录第一个空桶前的非空桶的最大值
	int i = 1;
	while (i < length + 1)//遍历所有的空桶区域
	{
		if (has[i] == 0)
		{
			lastmax = maxs[i - 1];
			i++;
			while (has[i] == 0)//防止一个空桶区域有多个连续空桶
				i++;
			if (mins[i] - lastmax > maxgap)
				maxgap = mins[i] - lastmax;
		}
		i++;
	}
	delete[] maxs, mins, has;
	return maxgap;
}
int main()
{
	return 0;
}