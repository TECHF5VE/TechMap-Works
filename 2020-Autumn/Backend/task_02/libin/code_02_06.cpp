#include<iostream>
using namespace std;
int main()
{
	int x1 = 1, x2 = 2, x3, j;
	cout << "���������" << endl;
	cin >> j;
	if (j == 1)
		x3 = x1;
	else if (j == 2)
		x3 = x2;
	else
		for (int i = 0; i < (j - 2); i++)
		{
			x3 = x1 + x2;
			x1 = x2; x2 = x3;
		}
	cout << "һ��������" << x3 << "��" << endl;
}