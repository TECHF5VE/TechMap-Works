#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int* creatArray(int n)
{
	int* array, i, * pt;
	array = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		array[i] = i + 1;
	}
	pt = array;
	return pt;
	
}
void main() {
	int* p, i;
	p = creatArray(8);
	for (i = 0; i < 8; i++)
	{
		printf("%d ", *(p + i));
	}

}




