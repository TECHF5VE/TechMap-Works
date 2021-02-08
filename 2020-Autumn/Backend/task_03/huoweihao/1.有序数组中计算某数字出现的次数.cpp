#include<iostream>
using namespace std;
int findNumberInArray(int* arr, int length, int target) {
	int left = 0, right = length - 1, mid,count=0;

	while (right-left>1)
	{
		mid = (left + right)/2;
		if (arr[mid] > target)
			right = mid;
		else if (arr[mid] < target)
			left = mid;
		else
		{
			while (arr[left] != target)
				left++;
			while (arr[right] != target)
				right--;
			count = right - left + 1;
			break;
		}
	}
	return count;
}
int main()
{
	return 0;
}