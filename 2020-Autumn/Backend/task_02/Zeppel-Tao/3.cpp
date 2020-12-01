#include <iostream>
using namespace std;
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
int main()
{

    system("pause");
    return 0;
}