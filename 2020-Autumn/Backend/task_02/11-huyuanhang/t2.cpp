#include<iostream>
#include<vector>
using namespace std;


void rotate(vector<vector<int>>origin)
{
	int n = origin.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			swap(origin[i][j], origin[j][i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			swap(origin[i][j], origin[i][n - 1 - j]);
		}
	}
	int i, j;

	for (i = 0; i < origin.size(); i++)
	{
		for (j = 0; j < origin[0].size(); j++)
			cout << origin[i][j] << " ";
		cout << endl;
	}

}
//�ڶ��⣺��ת����

int main()
{


	//�����ǵڶ���Ĳ���������
	cout << "�ڶ��⣺" << endl;
	vector<vector<int>>a
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	rotate(a);//�ڶ���
//....................................................................
}