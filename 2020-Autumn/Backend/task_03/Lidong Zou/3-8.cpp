#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int maximumGap(int* nums, int length)
{
	int max(*nums), t(0), n;
	for (int i = 1; i < length; i++)
		if (*(nums + i) > max)
		{
			max = *(nums + i);
			t = i;
		}
	n = *(nums + t);
	*(nums + t) = *(nums + length - 1);
	*(nums + length - 1) = n;
	return max;
}
int main()
{
	int length, * arr, * p;
	printf_s("����������ĳ��ȣ�");
	scanf_s("%d", &length);
	if (length == 1) printf_s("����Ԫ��֮�����Ĳ�ֵΪ0");
	else
	{
		arr = (int*)malloc(length * sizeof(int));
		if (arr == NULL) exit(1);
		p = (int*)malloc(length * sizeof(int));
		if (p == NULL) exit(2);
		for (int i = 0; i < length; i++)
		{
			printf_s("�������%d�����ݣ�", i + 1);
			scanf_s("%d", arr + i);
		}
		for (int i = 0; i < length; i++)
			*(p + i) = maximumGap(arr, length - i);
		int x(fabs(*(p + 1) - *p));
		for (int i = 2; i < length - 1; i++)
			if (fabs(*(p + i) - *(p + i - 1)) > x) x = fabs(*(p + i) - *(p + i - 1));
		printf_s("����Ԫ��֮�����Ĳ�ֵΪ%d", x);
		return 0; 
	}
}