#include<stdio.h>
int sum(0);
int fac(int n)
{
	if (n == 1) return sum + 1;
	else if (n == 0) return sum;
	else
	{
		sum += n;
		n -= 2;
		return fac(n);
	}
}
int main()
{
	printf_s("������̨�׵���Ŀ��");
	int n;
	scanf_s("%d", &n);
	printf_s("һ����%d�ַ�����", fac(n));
	return 0;
}