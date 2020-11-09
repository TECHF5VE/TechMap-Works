#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1,3,5,4,32,6,8 };
	int* p = arr;
	for (int i = 0; i < 7; i++)
	{
		cout << *p << endl;
		p++;
	}
	system("pause");
	return 0;
}