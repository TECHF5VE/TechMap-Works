#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void moveZeroes(int* nums, int length)
{
	int i;
	for (i = 0;i < length;i++)
	{
		if (nums[i] == 0)
		{
			int t;
			int j = i + 1;
			while (j != length)
			{
				t = nums[i];
				nums[i] = nums[j];
				nums[j] = t;
				j = j + 1;
				i = i + 1;
			}
		}
	}
}
int main()
{
	int a[100];
	int i;
	int length;
	scanf("%d", &length);
	for (i = 0;i < length;i++)
	{
		scanf("%d", &a[i]);
	}
	moveZeroes(a, length);
	for (i = 0;i < length;i++)
	{
		printf("%d ", a[i]);
	}
}