#include<stdio.h>
#include<stdlib.h>
int* createArray(int n)
{
	int* p;
	p = (int*)malloc(n * sizeof(int));
	if (p == NULL) exit(1);
	for (int i = 0; i < n; i++)
		*(p + i) = i + 1;
	return p;
}
int main()
{
	printf_s("����������Ķ�̬����Ĵ�С��");
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		printf_s("%d ", *(createArray(n) + i));
	return 0;
}
