#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void moveZeroes(int* nums, int length)
{
	int i;
	int temp = 0;
	for (i = 0; i < length; i++)
	{
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
	int a[100];
	int i;
	int length;
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		scanf("%d", &a[i]);
	}
	moveZeroes(a, length);
	for (i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
}


