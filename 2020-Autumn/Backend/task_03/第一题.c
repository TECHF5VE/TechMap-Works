#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findNumberInArray(int* arr, int length, int target)
{
	int count = 0;
	int i;
	for (i = 0; *(arr + i) != '\0'; i++)
	{
		if (*(arr + i) == target)
		{
			count = count + 1;
		}
	}
	return count;
}
int main()
{
	int a[100];
	int length;
	int i, t;
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		scanf("%d", &a[i]);
	}
	int target;
	scanf("%d", &target);
	t = findNumberInArray(a, length, target);
	printf("%d", t);
}