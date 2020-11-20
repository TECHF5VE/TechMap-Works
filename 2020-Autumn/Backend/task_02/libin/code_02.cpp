#include<iostream>
#include<ctime>
using namespace std;
void merge(int* a, int m, int* b, int n) {
	a = new int[m + n];
	srand(time(0));
	for (int i = 0; i < m; i++)
		a[i] = rand() % 10;
	b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = rand() % 10;//分别定义合并前的a，b两数组并随机赋值；
	for (int i = m, t = 0; i < (m + n) && t < n; i++ && t++)
		a[i] = b[t];
	for (int i = 0; i < (m + n); i++)
		cout << a[i] << " ";
	cout << endl;
}//first;
void rotate(int n) {
	int** a, g(1);
	a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = g;
			g++;
		}
	cout << "旋转前：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";

		}cout << endl;
	}//创了一个n*n的矩阵并输出；
	cout << endl;
	int** b, ** c;
	b = new int* [n], c = new int* [n];

	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
		c[i] = new int[n];
	}//申请b[n][n]动态数组；
	for (int j = 0; j < n; j++)
		for (int d = 0, r = (n - 1); d < n, r >= 0; d++, r--)
		{
			b[j][r] = a[d][j];

		}//矩阵九十度旋转；
	cout << "旋转后:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";

		}cout << endl;//输出旋转完成的数组；
	}
}//seconed;
void traversall(int* a, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}cout << endl;//遍历已有数组；
}//third;
void creatArray(int n)
{

	int* a;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cout << a[i] << " ";
	}cout << endl;//创一个长度为n的数组并赋值至n；
}//forth;

void creatbig(int m, int n) {

	int** a, g(1);
	a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			a[i][j] = g;
			g++;
		}//为m*n长度的数组赋值至m*n；没用第三次嵌套；
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";

		}cout << endl;
	}cout << endl;
}//fifth;
int pit(int j) {

	int x1 = 1, x2 = 2, x3;
	if (j == 1)
		x3 = x1;
	else if (j == 2)
		x3 = x2;
	else
		for (int i = 0; i < (j - 2); i++)
		{
			x3 = x1 + x2;
			x1 = x2; x2 = x3;
		}return x3;//大佬爬楼梯的办法；
}//sixth;
int main()
{
	int m, n, j;
	cout << "请输入m，n" << endl;
	cin >> m >> n;
	cout << "first:" << endl;
	int* a = NULL, * b = NULL;
	merge(a, m, b, n); cout << endl;//1
	cout << "second:" << endl;
	rotate(n); cout << endl;//2
	cout << "third:" << endl;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	traversall(a, n); cout << endl;//3
	cout << "forth:" << endl;
	creatArray(n); cout << endl;//4
	cout << "fifth:" << endl;
	creatbig(m, n); cout << endl;//5
	cout << "sixth:" << endl;
	cout << "请输入阶数 ";
	cin >> j; cout << endl;
	cout << "有方法" << pit(j) << "种";//6
}