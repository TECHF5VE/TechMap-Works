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

	//�����ǵ�����Ĳ�������
	cout << "�����⣺" << endl;
	int number, c_number;
	cin >> number;
	c_number = climbstairs(number);
	cout << "��¥�ݵİ취�У�" << c_number << "��" << endl;
	//......................................................................
}