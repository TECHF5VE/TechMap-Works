#include<iostream>
using namespace std;

void Merge(int* arr, int length)
{
    int* temp;
    temp = new int[length];
    int b = 0;
    int mid = length / 2;
    int first = 0, second = mid;

    while (first < mid && second < length)
    {
        if (arr[first] <= arr[second])
            temp[b++] = arr[first++];
        else
            temp[b++] = arr[second++];
    }

    while (first < mid)
        temp[b++] = arr[first++];
    while (second < length)
        temp[b++] = arr[second++];
    for (int i = 0; i < length; i++)
        arr[i] = temp[i];
}

void MergeSort(int* arr, int length)
{
    if (length <= 1)
        return;
    if (length > 1)
    {
        MergeSort(arr, length / 2);
        MergeSort(arr + length / 2, length - length / 2);
        Merge(arr, length);
    }
}
int maximumGap(int* nums,int length)
{
	if (length<2)
	return 0;
	else{
	MergeSort( nums, length);
	int i=0;
	int count=nums[i+1]-nums[i];
	for(i=1;i<length;i++)
	{
		if(count<=nums[i+1]-nums[i])
		count=nums[i+1]-nums[i];	
	}
	return count;
    }
}
int main()
{
    int length= 5;
    int arr[5] = { 2,10,5,4,1 };
    cout << "******以下是测试用例：******" << endl;
    cout << "原数组为：";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << maximumGap(arr, length);
}
