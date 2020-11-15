#include <stdio.h>
#include <malloc.h>

void main() {
    //1.合并两个有序数组
    void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
    int nums1[] = { 1,2,3,0,0,0 };
    int nums2[] = { 2,3,4 };
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 6; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n\n");


    //2.旋转矩阵
    void rotate(int** matrix, int matrixSize);
    int matrix[][3] = { {1,2,3},{4,5,6},{7,8,9}};
    int* a[3];
    a[0] = matrix[0];
    a[1] = matrix[1];
    a[2] = matrix[2];
    rotate(a, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    //3.遍历数组
    void through_array(int* matrix, int matrixSize);
    int matrix_[] = { 1,2,3,4,5 };
    through_array(matrix_, 5);
    printf("\n");


    //4.生成动态数组
    int* create_array(int n);
    int* array = create_array(6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", *(array+i));
    }
    printf("\n\n");


    //5.生成动态二维数组
    int** create_array2(int m, int n);
    int** arrray2 = create_array2(3,4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *(*(arrray2+i)+j));
        }
        printf("\n");
    }
    printf("\n");


    //6.爬楼梯(动态规划)
    int climbStairs1(int n);
    printf("%d\n\n", climbStairs1(10));

    //6.爬楼梯(递归)
    int climbStairs2(int n);
    printf("%d\n\n", climbStairs2(10));

    //7.个人blog
    //http://101.200.209.16/

}


//1.合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int j = m - 1, k = n - 1;
    for (int i = nums1Size - 1; i >= 0; i--) {
        if (j < 0) {
            nums1[i] = nums2[k];
            k--;
        }
        else if (k < 0) {
            nums1[i] = nums1[j];
            j--;
        }
        else {
            if (nums1[j] > nums2[k]) {
                nums1[i] = nums1[j];
                j--;
            }
            else {
                nums1[i] = nums2[k];
                k--;
            }
        }
    }
}


//2.旋转矩阵
void rotate(int** matrix, int matrixSize) {
    int tmp1;
    int tmp2;
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = i; j < matrixSize - 1 - i; j++) {
            tmp1 = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - j][i];
            tmp2 = matrix[j][matrixSize - 1 - i];
            matrix[j][matrixSize - 1 - i] = tmp1;
            tmp1 = matrix[matrixSize - 1 - i][matrixSize - 1 - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - j] = tmp2;
            matrix[matrixSize - 1 - j][i] = tmp1;
        }
    }
}


//3.遍历数组
void through_array(int* matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        printf("%d ", *(matrix + i));
    }
    printf("\n");
}


//4.生成动态数组
int* create_array(int n) {
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 1; i <= n; i++) {
        *(ans + i - 1) = i;
    }
    return ans;
}


//5.生成动态二维数组
int** create_array2(int m, int n) {
    int** ans = (int**)malloc(m * sizeof(int*));
    int k = 1;
    for (int i = 0; i < m; i++) {
        ans[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            ans[i][j] = k;
            k++;
        }
    }
    return ans;
}


//6.爬楼梯

//动态规划
int climbStairs1(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int a = 1;
    int b = 2;
    int c = 0;
    int t;
    for (int i = 2; i < n; i++) {
        c = a + b;
        t = b;
        b = c;
        a = t;
    }
    return c;
}

//递归
int climbStairs2(int n) {
    int sum = 0;
    if (n - 1 > 0) {
        sum += climbStairs2(n - 1);
    }
    if (n - 2 > 0) {
        sum += climbStairs2(n - 2);
    }
    if (n - 1 == 0) {
        sum++;
    }
    if (n - 2 == 0) {
        sum++;
    }
    return sum;
}