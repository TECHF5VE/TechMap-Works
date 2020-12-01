#include <iostream>
using namespace std;
void text02(int** matrix, int n)
{
 
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
int main()
{
    int n = 0;
    cout << "请输入n：";
    cin >> n;
    int** matrix;
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    text02(matrix, n);
    system("pause");
    return 0;
}