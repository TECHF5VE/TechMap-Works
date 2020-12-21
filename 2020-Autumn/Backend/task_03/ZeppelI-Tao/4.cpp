#include <iostream>
using namespace std;
void moveZeroes(int* nums, int length) 
{
	int k = length - 1;
	int sum0 = 0;
	for (int i = 0; i < length-1 ; i++)
	{
		if (nums[i] == 0)
		{
			for (int j = i; j < length - i - 1; j++)
			{
				nums[j] = nums[j + 1];
			}
			sum0++;
		}
		
	}
	for (int j = 0;j < sum0; j++)
	{
		nums[k] = 0;
		k--;
	}
}
int main()
{
	int* arr = new int[5]{ 0,1,0,3,12 };
	moveZeroes(arr,5);
	for (int i = 0; i <5 ; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}
//void moveZeroes(int* nums, int length){
//code
//}
//ÊäÈë: nums = [0, 1, 0, 3, 12], length = 5

//Êä³ö : [1, 3, 12, 0, 0]
