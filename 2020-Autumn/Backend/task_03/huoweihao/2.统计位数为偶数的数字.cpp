#include<iostream>
using namespace std;
int findNumbers(int* nums, int length) {
	int count = 0,n;
	for (int i = 0; i < length; i++)
	{
		n = 1;
		while (nums[i] /= 10)
			n++;
		if (n % 2 == 0)
			count++;
	}
	return count;
}
int main()
{
	return 0;
}