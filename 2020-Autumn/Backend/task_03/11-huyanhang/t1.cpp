#include<iostream>
using namespace std;

int search(int* array, int size, int target, int flag)
{
    int left = 0, right = size - 1;
    int mid = 0, last = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] > target) {
            right = mid - 1;
        }
        else if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            last = mid;
            if (flag == 0) {
               
                right = mid - 1;
            }
            else if (flag == 1) {
              
                left = mid + 1;
            }
        }
    }
    return last;
}
int CountInArray(int* array, int size, int target)
{
    int first = search(array, size, target, 0);
    int last = search(array, size, target, 1);
    if (first == -1) {
        return 0;
    }
    return last - first + 1;
}
int main()
{
	cout << "******以下为测试用例******" << endl;
	const int length = 5;
	int arr[length] = { 0,0,1,3,3 };
	cout << "数组为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
	int* nums, n;
	n = length;
	nums = new int[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = arr[i];
	}
	int target;
	cout << "target:";
	cin >> target;
	int count = 0;
	count= CountInArray(nums, n, target);
	cout << "出现的次数为：" << count;


}
