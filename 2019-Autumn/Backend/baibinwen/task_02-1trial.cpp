#include<iostream>

using namespace std;

const int MAXNUM = 65536;

int a[201];
typedef int A[102];
A b, c;

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
	for (int i = 1; i <= m; i++) cin >> c[i];
	c[m + 1] = MAXNUM;
	cout << "\n请给定有序数组b：";
	for (int i = 1; i <= n; i++) cin >> b[i];
	b[n + 1] = MAXNUM;

	//将c和b装入a
	int i = 1, j = 1, k = 0;
	while(k<total) {
		while (c[i] <= b[j]) a[++k] = c[i++];
		while (b[j] < c[i]) a[++k] = b[j++];
	}

	//输出合并后的数列a
	cout << a[1];
	for (int i = 2; i <= total; i++)
		cout << ' ' << a[i];
	cout << endl;

	return 0;
}
