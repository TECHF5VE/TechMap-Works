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

int main()
{
    int* arr, length;
    length = 5;
    int arr1[5] = { 2,10,5,4,1 };
    arr = new int[length];
    for (int i = 0; i < length; i++)
        arr[i] = arr1[i];
    cout <<"******以下是测试用例：******"<<endl;
    cout <<"原数组为："; 
   for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
        cout <<endl;
    MergeSort(arr, length);
     cout <<"排序后数组为："; 
   for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
        cout <<endl;
}
