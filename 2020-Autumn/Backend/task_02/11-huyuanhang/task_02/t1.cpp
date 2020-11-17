#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> nums1, int m, vector<int> nums2, int n)
{
	cout << "nums1:";
	for (int i = 0; i < m; ++i)
	{

		cout << nums1[i] << " ";
	}cout << endl;
	cout << "nums2:";
	for (int i = 0; i < n; ++i)
	{

		cout << nums2[i] << " ";
	}cout << endl;
	for (int i = m, j = 0; i < m + n; ++i, ++j)
	{
		nums1[i] = nums2[j];
	}
	cout << "合并后：" << endl;
	for (int i = 0; i < m + n; i++)
	{
		for (int j = 0; j < m + n - i - 1; j++)
		{
			int temp = 0;
			if (nums1[j] > nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
		cout << nums1[i] << " ";
	}
	cout << endl;

}



int main()
{
	//以下是第一题的测试用例：
	cout << "第一题：" << endl;
	vector<int>nums1{ 1,2,3,0,0 };
	vector<int>nums2{ 5,6 };
	int m = 3, n = 2;
	merge(nums1, m, nums2, n);//第一题的测试用例。
//................................................................
}