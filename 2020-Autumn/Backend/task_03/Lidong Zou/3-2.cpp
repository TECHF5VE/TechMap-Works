#include<stdio.h>
#include<stdlib.h>
int findNumbers(int* nums, int length)
{
	int n(0);
	for (int i = 0; i < length; i++)
		if (*(nums + i) % 2 == 0) n++;
	return n;
}
int main()
{
	int length;
	printf_s("����������Ĵ�С��");
	scanf_s("%d", &length);
	int* nums;
	nums = (int*)malloc(length * sizeof(int));
	if (nums == NULL) exit(0);
	for (int i = 0; i < length; i++)
	{
		printf_s("�������%d�����ݣ�", i + 1);
		scanf_s("%d", nums + i);
	}
	printf_s("λ��Ϊż���ĸ���Ϊ%d",findNumbers(nums, length));
	return 0;
}






		