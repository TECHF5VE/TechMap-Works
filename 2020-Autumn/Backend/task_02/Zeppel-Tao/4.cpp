#include <iostream>
using namespace std;

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
int main()
{
    int n = 0;
    text04(n);
    system("pause");
    return 0;
}