#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i, j=0;
	for (i = m;i < m + n;i++)
	{
		nums1[i] = nums2[j];
		j++;//当i=m+n时,停止赋值;
	}//合并数组;
	for (i = 0;i < m + n - 1;i++)
	{
		for (j = 0;j < m + n - 1 - i;j++)
		{
			int temp;
			if (nums1[j] > nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}//冒泡排序;
}
void main(){
	int arr1[] = { 1,2,3,0,0,0 }, i;
	int arr2[] = { 4,6,7 };
	merge(arr1, 3, 3, arr2, 3, 3);//传递数组地址,数组规模;
	for (i = 0;i < 6;i++)
	{
		printf("%d ", arr1[i]);
	}
}







#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
	int i, j;
	for (i = 0;i < matrixSize;i++)
	{
		for (j = i + 1;j < matrixSize;j++)
		{
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	for (i = 0;i < matrixSize;i++)
	{
		for (j = 0;j < matrixSize / 2;j++)
		{
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrixSize - 1 - j];
			matrix[i][matrixSize - 1 - j] = temp;
		}
	}
	return;
}
int main() {
	int** arr;
	int i, j, t = 3;
	int* colmat = (int*)malloc(t * sizeof(int));
	arr = (int**)malloc(t * sizeof(int));
	for (i = 0;i < t;i++)
	{
		*(arr + i) = (int*)malloc(t * sizeof(int));
	}
	printf("\n");
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	rotate(arr, 3, colmat);
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d,\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
	for (i = 0;i < t;i++)
	{
		free(arr[i]);
	}
	free(arr);
	free(colmat);
}





#include<stdio.h>
#include<stdlib.h>
void travelsall(int* a, int n) {
	int i;
	for (i = 0;i <= n - 1;i++)
	{
		printf("%d ", *(a + i));
	}
}
void main() {
	int s[8] = { 1,2,3,4,5,6,7,8 };
	travelsall(s, 8);
}






#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int* creatArray(int n)
{
	int* array, i, *pt;
	array = (int*)malloc(n * sizeof(int));
	for (i = 0;i < n;i++)
	{
		array[i] = i + 1;
	}
	pt = array;
	return pt;
	free(array);
}
void main() {
	int *p, i;
	p=creatArray(8);
	for (i = 0;i < 8;i++)
	{
		printf("%d ", *(p + i));
	}
}






#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int** creatArray(int m,int n)
{
	int i, j;
	int** array, ** pt;
	array = (int**)malloc(m * sizeof(int));
	for (i = 0;i < m;i++)
	{
		array[i] = (int*)malloc(n * sizeof(int));
	}
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	pt = array;
	return pt;
}
void main() {
	int** p, i, j;
	p=creatArray(3, 3);
	for (i = 0;i <3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}


}
for (i = 0;i < m;i++)
	{
		free(array[i]);
	}
	free(array);
