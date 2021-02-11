#include<stdio.h>
#include<stdlib.h>
int moveZeroes(int* nums, int length)
{
	int n(0);
	for (int i = 0; i < length; i++)
		if (*(nums + i) == 0)
		{
			for (int j = i; j < length-1; j++)
				*(nums + j) = *(nums + j + 1);
			*(nums + length - 1) = 0;
		}
	return 0;
}
int main()
{
	int* nums, length;
	printf_s("请输入数组的大小：");
	scanf_s("%d", &length);
	nums = (int*)malloc(length * sizeof(int));
	if (nums == NULL) exit(1);
	printf_s("请输入数组数据\n");
	for (int i = 0; i < length; i++)
	{
		printf_s("第%d个数据为：", i + 1);
		scanf_s("%d", nums + i);
	}
	moveZeroes(nums, length);
	for (int i = 0; i < length; i++)
		printf_s("%d ", *(nums + i));
	free((int*)nums);
	return 0;
}