#include <iostream>
using namespace std;
//��һ��
void text01(int m, int n,int* arrA, int* arrB)
{
	int i, j;
	i = m - 1;
	j = n - 1;
	while (i >= 0 && j >= 0)
	{
		if (arrA[i] >= arrB[j]) //�Ӻ���ǰ���򣬽��ϴ��ֵ����A��
		{
			arrA[i + j + 1] = arrA[i];
			i--;
		}
		else
		{
			arrA[i + j + 1] = arrB[j];
			j--;
		}
	}
	while (j >= 0)//��B����ʣ���ֵʱ����ʣ���ֵ����A��
			  //��ʣ�����A�е�ֵ����ֱ��������A��
	{
		arrA[j] = arrB[j];
	}
}
int main()
{
	int arrA[7] = { 1, 2, 3, 8, 0, 0, 0 };
	int arrB[3] = { 2,5,6 };
	text01(4, 3, arrA,arrB);
	for (int i = 0; i < 7; i++)
	{
		cout << arrA[i] << "  ";
	}

	system("pause");
	return 0;
}