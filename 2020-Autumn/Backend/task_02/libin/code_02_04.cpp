#include<iostream>
using namespace std;
int main()
{
	int* a, n;
	cout << "������n" << endl;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cout << a[i] << " ";
	}//��һ������Ϊn�����鲢��ֵ��n�������
	delete[]a;
}