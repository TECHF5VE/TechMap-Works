//
//  main.cpp
//  数组转链表
//
//  Created by 强宇琛 on 2019/11/4.
//  Copyright © 2019 强宇琛. All rights reserved.
//

#include <iostream>
using namespace std;
#define m 10
struct note
{
    int i;
    struct note *next;
};
note* ChangeToList(int n,int arr[])//n是节点个数
{
    struct note*head=new note;
    struct note*former=head;//定义了一个头。
    for(int i=0;i<n;i++)
    {
        struct note *p = new note;
        p->i=arr[i];
        former->next=p;
        former=p;
    }
    return head;
}
void dowork(int n,note*p)
{
    for(int i=0;i<n;i++)
    {
        cout<<p->i<<" ";
        p=p->next;
    }
    cout<<endl;
}


int main() {
    
    int a[m]={1,2,3,4,5,6,7,8,9,10};
    /*for(int i=0;i<10;i++)
    {
        a[i]=j;
        j++;
    }*/
    
    dowork(m,ChangeToList(m,a)->next);
    return 0;
}
