#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int countGoodTriplets(int* arr, int length, int a, int b, int c)
{
	int n(0);
	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
			if (fabs(*(arr + i) - *(arr + j)) <= a)
				for (int k = j + 1; k < length; k++)
					if (fabs(*(arr + j) - *(arr + k)) <= b && (fabs(*(arr + i) - *(arr + k)) <= c))
						n++;
	return n;
}
int main()
{
	int length;
	printf_s("�����������С��");
	scanf_s("%d", &length);
	int* arr;
	arr = (int*)malloc(length * sizeof(int));
	if (arr == NULL) exit(1);
	for (int i = 0; i < length; i++)
	{
		printf_s("�������%d�����ݣ�", i + 1);
		scanf_s("%d", arr + i);
	}
	int a, b, c;
	printf_s("��ֱ�����a,b,c����ֵ���м��ö��ŷָ�����");
	scanf_s("%d,%d,%d", &a, &b, &c);
	printf_s("һ����%d������Ԫ�顣", countGoodTriplets(arr, length, a, b, c));
	return 0;
}