#include <iostream>
using namespace std;

int** text05(int m, int n)
{
    int m = 0;
    int n = 0;
    cout << "����������: ";
    cin >> m;
    cout << "����������: ";
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
            arr[i][j] = i * n + j;  //��ʹ��ָ����Ϊ*(*(arr+i)+j) cin >> arr[i][j]  
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
int main()
{
    int m = 0;
    int n = 0;
    text05(m, n);
    system("pause");
    return 0;
}