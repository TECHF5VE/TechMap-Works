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
	printf_s("����������ĳ����м��ö��ŷָ�����");
	scanf_s("%d,%d", &n, &m);
	int* p;
	p = (int*)malloc(n * m * sizeof(int));
	if (p == NULL) exit(1);
	printf_s("���������ݣ�Ҫ��ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������\n");
	for (int i = 0; i < n * m; i++)
	{
		printf_s("��%d����Ϊ��", i + 1);
		scanf_s("%d", p + i);
	}
	int target;
	printf_s("���������Ŀ�꣺");
	scanf_s("%d", &target);
	int** pp;
	pp = &p;
	if (findNumberIn2DArray(pp,n,m,target) != 1)
		printf_s("false");
	else printf_s("true");
	return 0;
}