#include<iostream>
using namespace std;
bool findNumberIn2DArray(int** matrix, int n, int m, int target) {
	int i = n - 1, j = 0;
	while (i >= 0 && j < m)
	{
		if (matrix[i][j] > target)
			i--;
		else if (matrix[i][j] < target)
			j++;
		else
			return 1;
	}
	return 0;
}
int main()
{
	return 0;
}