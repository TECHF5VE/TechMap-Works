#include<iostream>
using namespace std;
void sort(int* arr, int low, int high) {
	if (low >= high)
		return;
	int i = low, j = high;
	int index = arr[i];        
	while (i < j)
	{	
		while (i < j)
		{
			if (arr[j] < index)
			{
				arr[i] = arr[j];
				i++;
				break;
			}
			j--;
		}
		while (i < j)
		{
			if (arr[i] > index)
			{
				arr[j] = arr[i];
				j--;
				break;
			}
			i++;
		}
	}
	arr[i] = index;
	sort(arr, low, i - 1);
	sort(arr, j + 1, high);
}
int main()
{
	return 0;
}