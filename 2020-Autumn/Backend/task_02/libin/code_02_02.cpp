#include<iostream>
using namespace std;
int main()
{
	int** a, g(1), n;
	cout << "������n" << endl;
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
	cout << "��תǰ��" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";

		}cout << endl;
	}//����һ��n*n�ľ��������
	cout << endl;
	int** b, ** c;
	b = new int* [n], c = new int* [n];

	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
		c[i] = new int[n];
	}//����b[n][n]��̬���飻
	for (int j = 0; j < n; j++)
		for (int d = 0, r = (n - 1); d < n, r >= 0; d++, r--)
		{
			b[j][r] = a[d][j];

		}//�����ʮ����ת��
	cout << "��ת��:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";

		}cout << endl;//�����ת��ɵ����飻
	}for (int i = 0; i < n; i++)
	{
		delete[]a[i]; delete[]b[i];
	}
	delete[]a; delete[]b;
}