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
	printf_s("����������Ĵ�С��");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf_s("�������%d������", i + 1);
		scanf_s("%d", &a[i]);
	}
	int* p(a);
	traversal1(p, n);
	return 0;
}

