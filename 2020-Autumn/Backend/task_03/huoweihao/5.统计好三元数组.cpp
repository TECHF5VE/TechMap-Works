#include<iostream>
using namespace std;
int countGoodTriplets(int* arr, int length, int a, int b, int c) {
	int count = 0;
	for (int i = 0; i < length - 3; i++)
		for (int j = i + 1; j < length - 2; j++)
			for (int k = j + 1; k < length - 1; k++)
				if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
					count++;
	return count;
}
int main()
{
	int n[]{ 3,0,1,1,9,7 }, * arr{ n };
	cout << countGoodTriplets(arr, 6, 7, 2, 3);
	return 0;
}