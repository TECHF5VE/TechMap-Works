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
//�����⣬ָ���������

int main()
{
	//�����ǵ�����Ĳ���������
	cout << "�����⣺" << endl;
	int arr[5] = { 1,2,3,4,5 };
	traversal(arr, 5);
	cout << endl;//������
	//....................................................................
}