#include<stdio.h>
#include<stdlib.h>
int* createArray(int n)
{
	int* a;
	int* a = (int*)malloc(sizeof(int) * n);
	scanf_s("%d", &n);
	int i(1);
	for (; i <= n; i++)
	{
		a[i] = i;
		printf_s("%d", a[i]);
	}
	return 0;
}