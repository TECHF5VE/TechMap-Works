#include<iostream>
using namespace std;
bool searchMatrix(int** matrix, int m, int n, int target) 
{  
    int StateLine = 0;
    int StateCol =n - 1;
    while (StateCol >= 0 && StateLine < m)
    {
        if (matrix[StateLine][StateCol] == target)
            return true;
        else if (matrix[StateLine][StateCol] > target)
            StateCol--;
        else if (matrix[StateLine][StateCol] < target)
            StateLine++;
    }
    return false;
}


void release(int** array, int n) {               
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete[] array;
}

int main()
{
    const int m = 5;
    const int n = 5;
    int arr[m][n] =
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int** nums;
    int a = 5;
    int b = 5;
    nums = new int* [a];
    for (int i = 0; i < a; i++) {
        nums[i] = new int[b];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            nums[i][j] = arr[i][j];
    }
    cout << "******以下是测试用例*******" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    int target;
    cout << "Please input your target:";
    cin >> target;
    cout << "Result:" << searchMatrix(nums, a, b, target);
    
    release(nums, b);


    return 0;

    
}
