#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i, j = 0;
	for (i = m; i < m + n; i++)
	{
		nums1[i] = nums2[j];
		j++;//��i=m+nʱ,ֹͣ��ֵ;
	}//�ϲ�����;
	for (i = 0; i < m + n - 1; i++)
	{
		for (j = 0; j < m + n - 1 - i; j++)
		{
			int temp;
			if (nums1[j] > nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}//ð������;
}
void main() {
	int arr1[] = { 1,2,3,0,0,0 }, i;
	int arr2[] = { 4,6,7 };
	merge(arr1, 3, 3, arr2, 3, 3);//���������ַ,�����ģ;
	for (i = 0; i < 6; i++)
	{
		printf("%d ", arr1[i]);
	}
}


