#include <iostream>
using namespace std;
//第一道
void text01(int m, int n, int q, int* arrA, int* arrB)
{
	int i, j;
	i = m - 1;
	j = n - 1;
	while (i >= 0 && j >= 0)
	{
		if (arrA[i] >= arrB[j]) //从后向前排序，将较大的值赋给A。
		{
			arrA[i + j + 1] = arrA[i];
			i--;
		}
		else
		{
			arrA[i + j + 1] = arrB[j];
			j--;
		}
	}
    while (j >= 0)//当B中有剩余的值时，将剩余的值赋到A中
              //若剩余的是A中的值，则直接在数组A中
    {
        arrA[j] = arrB[j];
    }
}
//第二道
void text02(int** matrix, int n)
{
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    cout << "翻转前:" << endl;
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < n; j++)
        {

            matrix[i][j] = i * n + j + 1;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - i - 1][j];
            matrix[n - i - 1][j] = temp;

        }
    }
    //对角线翻转
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    cout << "翻转后:" << endl;
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < n; j++)
        {

            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
//第三道
void text03(int* a, int n)
{
    int size = 10000;
    int* arr = new int[size];
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }
}
//第四道
int* text04(int n)
{
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return arr;
}
//第五道
int** text05(int m,int n)
{
    int m = 0;
    int n = 0;
    cout << "请输入排数: ";
    cin >> m;
    cout << "请输入列数: ";
    cin >> n;
    int** arr = new int* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)

    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i * n + j;  //若使用指针则为*(*(arr+i)+j) cin >> arr[i][j]  
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
//第六道
int climbstairs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else {
        return climbstairs(n - 1) + climbstairs(n - 2); //使用递归
    }
}
