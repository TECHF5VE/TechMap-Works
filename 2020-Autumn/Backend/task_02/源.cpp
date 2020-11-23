#include<iostream>
using namespace std;
//1.合并数组
void merge(int* a, int m, int* b, int n) 
{
    int len = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0)
    {
        if (a[m] >= b[n])
            a[len--] = a[m--];
        else
            a[len--] = b[n--];
    }
    while (n >= 0)
        a[len--] = b[n--];
}
//2.旋转矩阵
void rotate(int** matrix, int n)
{
    for (int i = 0; i < n / 2; i++)
        for (int j = 0, k; j < n - 2 * i - 1; j++)
        {
            k = matrix[i][i + j];
            matrix[i][j + i] = matrix[n - 1 - i - j][i];
            matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
            matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
            matrix[i + j][n - 1 - i] = k;
        }
}
//3.遍历数组
void traversal1(int* a, int n) 
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << "	";
}
//4.一维动态数组
int* create_array(int n)
{
    int* ip = new int[n];
    for (int i = 0; i < n; i++)
        ip[i] = i + 1;
    return ip;
}
//5.二维动态数组
int** createArray(int n, int m) {
    int** pp = new int* [m];
    int k{ 0 };
    for (int i = 0; i < m; i++)
    {
        pp[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            pp[i][j] = ++k;
    return pp;
}
//6.阶梯问题
int ladder(int n)
{
    if (n == 1 || n == 2)
        return n;
    else
        return ladder(n - 1) + ladder(n - 2);
}
