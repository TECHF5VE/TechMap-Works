#include<iostream>
#include<vector>
using namespace std;
void traversal(int arr[], int n)
{
	int* p = arr;
	for (int i = 0; i < n; i++)
	{
		cout << *p << " ";
		p++;
	}
}
//第三题，指针遍历数组

int main()
{
	//以下是第三题的测试用例：
	cout << "第三题：" << endl;
	int arr[5] = { 1,2,3,4,5 };
	traversal(arr, 5);
	cout << endl;//第三题
	//....................................................................
}