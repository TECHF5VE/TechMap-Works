#include <iostream>
using namespace std;

int main()
{
    int size = 100;
    int* arr = new int[size];
    int n = 0;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = i;
        cout << arr[i] << endl;
    }
    system("pause");
    return 0;
}