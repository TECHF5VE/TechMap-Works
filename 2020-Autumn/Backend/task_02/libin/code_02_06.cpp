#include<iostream>
using namespace std;
int main()
{
	int x1 = 1, x2 = 2, x3, j;
	cout << "请输入阶数" << endl;
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
	cout << "一共有爬法" << x3 << "种" << endl;
}