#include<iostream>
#include<ctime>
using namespace std;
int main() {
	int m, n, * a, * b;
	cout << "��ֱ������һ����������Ԫ�ظ���" << endl;
	cin >> m >> n;
	a = new int[m + n];
	cout << "����������a��" << m << "��Ԫ��" << endl;
	for (int i = 0; i <(m+n); i++)
	{
		if (i < m)
			cin >> a[i];
		else
			a[i] = 0;
	}
	b = new int[n];
	cout << "����������b��" << n << "��Ԫ��" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = m, t = 0; i < (m + n) && t < n; i++ && t++)
		a[i] = b[t];//��ֵ��
	int temp;
	for (int i = 0; i < (m + n); i++)
		for (int j = 0; j < (m + n); j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}//����
	for (int i = 0; i < (m + n); i++)
		cout << a[i] << " ";//����ϲ������飻
	delete[]a; delete[]b;
}//first;