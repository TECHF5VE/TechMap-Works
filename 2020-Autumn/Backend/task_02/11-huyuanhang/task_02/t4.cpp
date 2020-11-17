#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int  n;
	cin >> n;
	int* p;
	p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << p[i]<< " ";
	}
	delete[]p;
	system("pause");

	return 0;
}