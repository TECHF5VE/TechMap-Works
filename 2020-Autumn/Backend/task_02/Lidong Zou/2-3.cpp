#include<stdio.h>
int traversal1(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf_s("%d ", *(a + i));
	return 0;
}
int main()
{
	int a[20];
	int n;
	printf_s("请输入数组的大小：");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf_s("请输入第%d个数：", i + 1);
		scanf_s("%d", &a[i]);
	}
	int* p(a);
	traversal1(p, n);
	return 0;
}

