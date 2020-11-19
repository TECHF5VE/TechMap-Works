#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int m = 0;
	int n = 0;
	cout << "请输入行数: " << endl;
	cin >> m;
	cout << "请输入列数: " << endl;
	cin >> n;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++)

	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = i * n + j+1;  
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
