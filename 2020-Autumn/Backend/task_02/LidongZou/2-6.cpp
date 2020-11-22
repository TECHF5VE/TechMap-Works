#include<stdio.h>
int combination(int n, int m)
{
	if (n == 1 && m == 1) return 1;
	else if (n == 1 && m == 0) return 1;
	else return combination(n - 1, m - 1) + combination(n - 1, m);
}
int main()
{
	printf_s("Enter a number:");
	int n, sum, t, i, a(0);
	scanf_s("%d", &n);
	if (n % 2 == 0)
	{
		sum = 0;
		for (i = 0; i <= n / 2; i++)
		{
			t = combination(n / 2, i);
			sum += t;
		}
	}

	else
	{
		for (i = 0; i <= n / 2; i++)
		{
			sum = 0;
			t = combination(n / 2, i);
			t += (t + 1);
			sum += t;
		}
	}
	printf_s("%d", sum);
	return 0;
}


