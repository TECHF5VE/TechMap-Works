#include<iostream>

using namespace std;

const int MAXNUM = 65536;

int a[201];
typedef int A[102];
A b, c;

int main() {
	//���������������� 
	cout << "����������m��n�Գ�ʼ������a������b��Ԫ�ظ���(ע��m��n����Ҫ����100)" << endl;
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int total = n + m;
	cout << "\n�������������a��";
	for (int i = 1; i <= m; i++) cin >> c[i];
	c[m + 1] = MAXNUM;
	cout << "\n�������������b��";
	for (int i = 1; i <= n; i++) cin >> b[i];
	b[n + 1] = MAXNUM;

	//��c��bװ��a
	int i = 1, j = 1, k = 0;
	while(k<total) {
		while (c[i] <= b[j]) a[++k] = c[i++];
		while (b[j] < c[i]) a[++k] = b[j++];
	}

	//����ϲ��������a
	cout << a[1];
	for (int i = 2; i <= total; i++)
		cout << ' ' << a[i];
	cout << endl;

	return 0;
}
