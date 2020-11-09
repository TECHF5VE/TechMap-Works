#include <iostream>
#include <iomanip>
using namespace std;
void turnaround(int arr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}
void change(int arr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][2 - j];
			arr[i][2 - j] = temp;
		}
	}
}
int main()
{
	int arr[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	cout << "ÅÅÁÐÇ°£º" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] ;
		}
		cout << endl;
	}
	turnaround (arr);
	change(arr);

	cout << "ÅÅÐòºó£º" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}