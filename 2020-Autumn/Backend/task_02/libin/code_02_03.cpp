#include<iostream>
using namespace std;
int main()
{
	int a[] = { 1,2,3,4,5,6 };
	for (int i = 0; i < 6; i++)
	{
		cout << *(a + i) << " ";
	}//遍历已有数组；
}