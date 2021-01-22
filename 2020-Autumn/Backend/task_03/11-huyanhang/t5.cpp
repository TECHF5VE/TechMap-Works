#include <iostream>
#include <cmath>
using namespace std;
int countGoodTriplets(int* arr,int length,int a,int b,int c)
{
	int i,j,k;
	int count=0;
	for(int i=0;i<length-2;i++)	
	{
		for(int j=i+1;j<length-1;j++)
		{
			for(int k=j+1;k<length;k++)
			if(abs(arr[i]-arr[j])<=a&&abs(arr[j]-arr[k])<=b&&abs(arr[i]-arr[k])<=c)
			count++;
		}
	}
	return count;
}
int main()

{
	cout << "******以下为测试用例******" << endl; 
	int*arr,length=0;//在devc++上未报错，在vs上却报错，受教了。
	arr=new int[length];
	cout <<"请输入数组长度："; 
	cin>>length;
	for(int i=0;i<length;i++)
	{
		cin>>arr[i];
	}
	int a,b,c;
	cin>>a>>b>>c;
	cout <<countGoodTriplets( arr,length,a, b,c);
	
}
