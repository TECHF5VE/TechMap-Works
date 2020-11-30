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
int main()
{

	return 0;
}