#include<stdio.h>
#include<stdlib.h>
int findNumberInArray(int* arr, int length, int target)
{
	int num(0);
	for (int i = 0; i < length; i++)
		if (*(arr + i) == target) num++;
	return num;
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
		printf_s("�������%d������", i + 1);
		scanf_s("%d", arr + i);
	}
	int target;
	printf_s("������Ҫ���ҵ�����");
	scanf_s("%d", &target);
	printf_s("�ظ�����Ϊ%d��", findNumberInArray(arr, length, target));
	return 0;
}


