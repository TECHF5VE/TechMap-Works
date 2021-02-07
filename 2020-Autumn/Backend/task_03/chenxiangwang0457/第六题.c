#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int f(int* arr, int length)
{
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
int main()
{
	int arr[50];
	int i, length;
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}
	f(arr, length);
	for (i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}