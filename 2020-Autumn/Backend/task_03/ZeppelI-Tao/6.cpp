#include <iostream>
using namespace std;
//ʹ�ÿ�������ķ�����������ʱ�临�ӶȲ�����n^2
void quickSort(int arr[], int left, int right)
{
	if (left >= right) //�ж��Ƿ�������������������
	{
		return;
	}
	int i, j, k;
	i = left;
	int base = arr[i];   //���û�׼�������ڻ�׼����ֵ�������Ҳ�
	j = right;           //С�ڻ�׼���ֵ��������� 
	while (i < j)        
	{   //�����û�׼��λ�����ʱ����������Ҳ࿪ʼ����
		while (arr[j] >= base && i < j)
		{
			j--;                        //���ұ߿�ʼ�����������ֵ��������С�����ֵ�㱣��
		}
		while (arr[i] <= base && i < j)
		{
			i++;
		}
		if (i < j)               //�����ұ�����ֵ������ʹ�û�׼�����Ҿ�ΪС��||�������ֵ
		{
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	arr[left] = arr[i];    //��׼����λ
	arr[i] = base;
	quickSort(arr, left, i - 1);   //�ݹ����
	quickSort(arr, i + 1, right);  //�ݹ��ұ�
}
int main()
{
	int arr[10] = { 3,15,8,6,22,48,1,96,71,0 };
	quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}