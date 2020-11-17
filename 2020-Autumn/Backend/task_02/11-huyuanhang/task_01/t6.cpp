#include<iostream>

using namespace std;


int climbstairs(int n)
{
	if (n == 1)return 1;
	else if (n == 2)return 3;
	else
	{
		return climbstairs(n - 1) + climbstairs(n - 2);
	}
}


int main()
{

	//以下是第六题的测试用例
	cout << "第六题：" << endl;
	int number, c_number;
	cin >> number;
	c_number = climbstairs(number);
	cout << "爬楼梯的办法有：" << c_number << "种" << endl;
	//......................................................................
}