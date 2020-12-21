#include<iostream>
using namespace std;
int main()
{
	int** a, g(1), n;
	cout << "请输入n" << endl;
	cin >> n;
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = g;
			g++;
		}
	cout << "旋转前：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";

		}cout << endl;
	}//创了一个n*n的矩阵并输出；
	cout << endl;
	int** b, ** c;
	b = new int* [n], c = new int* [n];

	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
		c[i] = new int[n];
	}//申请b[n][n]动态数组；
	for (int j = 0; j < n; j++)
		for (int d = 0, r = (n - 1); d < n, r >= 0; d++, r--)
		{
			b[j][r] = a[d][j];

		}//矩阵九十度旋转；
	cout << "旋转后:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";

		}cout << endl;//输出旋转完成的数组；
	}for (int i = 0; i < n; i++)
	{
		delete[]a[i]; delete[]b[i];
	}
	delete[]a; delete[]b;
}