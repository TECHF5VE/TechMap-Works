//
//  main.cpp
//  整合并排列两个数组
//
//  Created by 强宇琛 on 2019/11/4.
//  Copyright © 2019 强宇琛. All rights reserved.
//

#include <iostream>
using namespace std;
void bubblesort(int * arr,int length)//在函数中传入数组的方法是，传入数组首地址n，并用s指针接受首地址。
{
    for(int i=length;i>1;i--)
    {
        for (int j=0;j<length-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
   
}
int main() {
    int m=100,n=10,a=1,b=0;//m为arr1的内存大小，n是b数组的长度
    int arr1[m];
    int arr2[n];
    for(int i=0;i<10;i++)
    {
        arr1[i]=a;
        a+=2;
    }
    for(int j=0;j<n;j++)
    {
        arr2[j]=b;
        b+=2;
    }
    for(int p=10;p<10+n;p++)
    {
        arr1[p]=arr2[p-10];
        
    }
    bubblesort(arr1, 10+n);
    for(int i=0;i<10+n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    

    return 0;
}
