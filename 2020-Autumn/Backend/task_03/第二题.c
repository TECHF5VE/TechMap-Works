#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findNumbers(int* nums, int length)
{
	int i;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		int num = 0;
		while (nums[i])
		{
			nums[i] /= 10;
			num = num + 1;
		}
		if (num % 2 == 0)
		{
			count = count + 1;
		}
	}
	return count;
}
int main()
{
	int i;
	int a[100];
	int length;
	int t;
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		scanf("%d", &a[i]);
	}
	t = findNumbers(a, length);
	printf("%d", t);
}