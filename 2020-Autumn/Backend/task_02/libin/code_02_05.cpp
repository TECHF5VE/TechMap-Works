#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int** a, g(1), m, n;
	cout << "请输入行，列" << endl;
	cin >> m >> n;
	a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = g;
			g++;
		}//为m*n长度的数组赋值至m*n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";

		}cout << endl;
	}for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
}