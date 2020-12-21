#include <iostream>
#include <cmath>
using namespace std;


int countGoodTriplets(int* arr, int length, int a,  int b, int c) 
{
	int sum = 0;
	for (int i = 0; i < length - 2; i++)
	{
		for (int j = i+1; j < length - 1; j++)
		{
			for (int k = j + 1; k < length; k++)
			{
				if ((i + j + k ) > length)
				{
					continue;
				}
				else
				{
					int tempa = arr[i] - arr[j];
					int tempb = arr[j] - arr[k];
					int tempc = arr[i] - arr[k];
					if ((abs(arr[i] - arr[j]) < a || abs(arr[i] - arr[j]) == a) && (abs(arr[j] - arr[k]) < b || abs(arr[j] - arr[k]))&&(abs(arr[i] - arr[k])<c ||abs(arr[i] - arr[k]) == c))
					{
						sum++;
					}
				}
			}
		}
	}
	return sum;
}
int main()
{
	int arr[] = { 3, 0, 1, 1, 9, 7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int a, b, c = 0;
	cout << "请输入a b c的值" << endl;
	cin >> a >> b >> c;
	cout << countGoodTriplets(arr, length, a, b, c);
	system("pause");
	return 0;
}
//如果三元组(arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。
//0 <= i < j < k < arr.length
//	| arr[i] - arr[j]| <= a
//	| arr[j] - arr[k]| <= b
//	| arr[i] - arr[k]| <= c
//	其中 | x | 表示 x 的绝对值。
//
//	样例：
//	输入：arr = [3, 0, 1, 1, 9, 7], a = 7, b = 2, c = 3
//	输出：4
//	解释：一共有 4 个好三元组：[(3, 0, 1), (3, 0, 1), (3, 1, 1), (0, 1, 1)] 。
//
//	参考提交函数格式
//	int countGoodTriplets(int* arr, int length, int a, int* arr, int lengthb, int c) {
//	//code
//}