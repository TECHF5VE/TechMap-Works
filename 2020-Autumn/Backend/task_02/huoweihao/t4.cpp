#include<iostream>
using namespace std;
//4.һά��̬����
int* create_array(int n)
{
    int* ip = new int[n];
    for (int i = 0; i < n; i++)
        ip[i] = i + 1;
    return ip;
}
int main()
{

	return 0;
}