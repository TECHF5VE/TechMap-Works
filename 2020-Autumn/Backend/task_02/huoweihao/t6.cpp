#include<iostream>
using namespace std;
//6.½×ÌİÎÊÌâ
int ladder(int n)
{
    if (n == 1 || n == 2)
        return n;
    else
        return ladder(n - 1) + ladder(n - 2);
}
int main()
{

	return 0;
}