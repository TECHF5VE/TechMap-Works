#include<stdio.h>
#include<stdlib.h>
bool findNumberIn2DArray(int** matrix, int n, int m, int target)
{
	int a(0);
	for (int i = 0; i < m; i++)
		if (*(*matrix + n * i) <= target && *(*matrix + n * i + m - 1) >= target)
			for (int j = n * i; j <= n * i + m - 1; j++)
				if (*(*matrix + j) == target) a = 1;
	if (a == 1) return true;
	else return false;
}
int main()
{
	int n, m;
	printf_s("请输入数组的长宽（中间用逗号分隔）：");
	scanf_s("%d,%d", &n, &m);
	int* p;
	p = (int*)malloc(n * m * sizeof(int));
	if (p == NULL) exit(1);
	printf_s("请输入数据（要求：每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序）\n");
	for (int i = 0; i < n * m; i++)
	{
		printf_s("第%d个数为：", i + 1);
		scanf_s("%d", p + i);
	}
	int target;
	printf_s("请输入你的目标：");
	scanf_s("%d", &target);
	int** pp;
	pp = &p;
	if (findNumberIn2DArray(pp,n,m,target) != 1)
		printf_s("false");
	else printf_s("true");
	return 0;
}