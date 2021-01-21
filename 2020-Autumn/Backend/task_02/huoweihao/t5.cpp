#include<iostream>
using namespace std;
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
int main()
{

	return 0;
}