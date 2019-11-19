#include<iostream>

using namespace std;

int a[201], b[101];

int main() {
	//给定两个有序数列 
	cout << "输入两个数m、n以初始化数组a、数组b的元素个数(注：m、n均不要超过100)" << endl;
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	int total = n + m;
	cout << "\n请给定有序数组a：";
	for (int i = 1; i <= m; i++) cin >> a[i];
	cout << "\n请给定有序数组b：";
	for (int i = 1; i <= n; i++) cin >> b[i];

	//处理头部 
	int k = 0;
	while (b[++k] < a[k]) {
		for (int i = m; i >= k; i--) a[i + 1] = a[i];
		a[k] = b[k];
	}
	//插入数列 b 
	for (int i = k; k <= n; k++) {
		for (; a[i]<=b[k]&&i<total; i++);
		for (int t = m + k; t > i; t--) a[t] = a[t - 1];
		a[i] = b[k];
		i++;
	}

	//输出合并后的数列 a
	cout << a[1];
	for (int i = 2; i <= total; i++)
		cout << ' ' << a[i];
	cout << endl;

	return 0;
}