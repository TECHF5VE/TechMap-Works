#include<iostream>
using namespace std;
int main()
{
	int* a, n;
	cout << "请输入n" << endl;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cout << a[i] << " ";
	}//创一个长度为n的数组并赋值至n且输出；
	delete[]a;
}