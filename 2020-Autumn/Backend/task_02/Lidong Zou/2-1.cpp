#include<stdio.h>
#include<stdlib.h>
void merge(int* a, int m, int* b, int n)
{
	int i = m - 1, j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (a[i] >= b[j])
		{
			a[k--] = a[i];
			i--;
		}
		else
		{
			a[k--] = b[j];
			j--;
		}
	}
	while (j >= 0)
	{
		a[k--] = b[j];
		j--;
	}
}
int main()
{
	int a[] = { 1,2,3,0,0,0 };
	int b[] = { 2,5,6 };
	merge(a, 3, b, 3);
	for (int i = 0; i < 6; i++)
		printf("%d", a[i]);
	system("pause");
	return 0;
}
