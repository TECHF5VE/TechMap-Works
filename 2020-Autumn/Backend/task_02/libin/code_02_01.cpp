#include<iostream>
#include<ctime>
using namespace std;
int main() {
	int m, n, * a, * b;
	cout << "请分别输入第一，二个数组元素个数" << endl;
	cin >> m >> n;
	a = new int[m + n];
	cout << "请输入数组a的" << m << "个元素" << endl;
	for (int i = 0; i <(m+n); i++)
	{
		if (i < m)
			cin >> a[i];
		else
			a[i] = 0;
	}
	b = new int[n];
	cout << "请输入数组b的" << n << "个元素" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = m, t = 0; i < (m + n) && t < n; i++ && t++)
		a[i] = b[t];//赋值；
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
		}//排序；
	for (int i = 0; i < (m + n); i++)
		cout << a[i] << " ";//输出合并的数组；
	delete[]a; delete[]b;
}//first;