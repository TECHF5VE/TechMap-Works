#include<iostream>

using namespace std;

int a[201], b[101];

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
	for (int i = 1; i <= m; i++) cin >> a[i];
	cout << "\n�������������b��";
	for (int i = 1; i <= n; i++) cin >> b[i];

	//����ͷ�� 
	int k = 0;
	while (b[++k] < a[k]) {
		for (int i = m; i >= k; i--) a[i + 1] = a[i];
		a[k] = b[k];
	}
	//�������� b 
	for (int i = k; k <= n; k++) {
		for (; a[i]<=b[k]&&i<total; i++);
		for (int t = m + k; t > i; t--) a[t] = a[t - 1];
		a[i] = b[k];
		i++;
	}

	//����ϲ�������� a
	cout << a[1];
	for (int i = 2; i <= total; i++)
		cout << ' ' << a[i];
	cout << endl;

	return 0;
}