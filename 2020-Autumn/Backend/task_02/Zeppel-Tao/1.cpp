#include <iostream>
using namespace std;

void addBtoA(int arrA[], int arrB[])     // 使数组B加入A中
{
	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arrA[i] == 0)
		{
			arrA[i] = arrB[j];
			j++;
		}
	}
}
void bubble(int arrA[], int lenA) //冒泡排序
{
	for (int i = 0; i < lenA; i++)
	{
		for (int j = 0; j < lenA - 1; j++)
		{
			if (arrA[j] > arrA[j + 1])
			{
				int temp = arrA[j];
				arrA[j] = arrA[j + 1];
				arrA[j + 1] = temp;
			}
		}
		cout << arrA[i] << endl;
	}
}
int main()
{
	int arrA[9] = { 1,2,5,7,9 };
	int arrB[4] = { 2,5,6,10 };
	int lenA = sizeof(arrA) / sizeof(arrA[0]);
	addBtoA(arrA, arrB);
	bubble(arrA, lenA);

	system("pause");
	return 0;
}