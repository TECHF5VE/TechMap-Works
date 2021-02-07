#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int f(int* arr, int length, int a, int b, int c)
{
	int i, j, k;
	int count = 0;
	for (i = 0; i < length - 2; i++)
	{
		for (j = i + 1; j < length - 1; j++)
		{
			for (k = j + 1; k < length; k++)
			{
				if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
				{
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{
	int m, t;
	int k[50];
	int* p = k;
	int length;
	scanf("%d", &length);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (m = 0; m < length; m++)
	{
		scanf("%d", &k[m]);
	}
	t = f(p, length, a, b, c);
	printf("%d", t);
	return 0;
}




