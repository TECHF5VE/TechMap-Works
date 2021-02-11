#include<stdio.h>
#include<stdlib.h>
int sort(int* arr, int length)
{
	int max(*arr), t(0), n;
	for(int i=1;i<length;i++)
		if (*(arr + i) > max)
		{
			max = *(arr + i);
			t = i;
		}
	n = *(arr + t);
	*(arr + t) = *(arr + length - 1);
	*(arr + length - 1) = n;
	return max;
}

int main()
{
	int length, * arr;
	printf_s("请输入数组的长度：");
	scanf_s("%d", &length);
	arr = (int*)malloc(length * sizeof(int));
	if (arr == NULL) exit(1);
	for (int i = 0; i < length; i++)
	{
		printf_s("请输入第%d个数据：", i + 1);
		scanf_s("%d", arr + i);
	}
	for (int i = 0; i < length; i++)
		printf_s("%d ", sort(arr, length - i));
	return 0;
}