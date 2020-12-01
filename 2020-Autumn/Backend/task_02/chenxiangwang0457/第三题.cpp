#include<stdio.h>
#include<stdlib.h>
void travelsall(int* a, int n) {
	int i;
	for (i = 0; i <= n - 1; i++)
	{
		printf("%d ", *(a + i));
	}
}
void main() {
	int s[8] = { 1,2,3,4,5,6,7,8 };
	travelsall(s, 8);
}

