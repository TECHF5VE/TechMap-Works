#include <iostream>
using namespace std;

int climbstairs(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else {
		return climbstairs(n - 1) + climbstairs(n - 2); //Ê¹ÓÃµÝ¹é
	}
}
int main()
{
	int n = 0;
	cin >> n;
	cout << climbstairs(n) << endl;;
	return 0;
}