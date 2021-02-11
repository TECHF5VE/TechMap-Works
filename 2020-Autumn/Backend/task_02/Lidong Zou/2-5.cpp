#include<stdio.h>
#include<stdlib.h>
int** createArray(int n, int m)
{
	int** pp, * p;
	pp = &p;
	p = (int*)malloc(n * m * sizeof(int));
	if (p == NULL) exit(1);
	for (int i = 0; i < n * m; i++)
		*(p + i) = i + 1;
	return pp;
}
int main()
{
	printf_s("请输入数组的长宽（中间用逗号隔开）：");
	int n, m;
	scanf_s("%d,%d", &n, &m);
	for (int i = 0; i < n*m; i++)
	{
		printf_s("%d ", *(*createArray(n, m)+i));
		if((i+1)%m==0) printf_s("\n");
	}
	return 0;
}