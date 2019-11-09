//
//  main.cpp
//  递归反转链表
//
//  Created by 强宇琛 on 2019/11/7.
//  Copyright © 2019 强宇琛. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int a;
    struct node *next;
};
struct node* createlist(int n)
{
    struct node*head=new struct node;
    struct node*pre=head;
    for(int i=0;i<n;i++)
    {
        struct node *p=new struct node;
        cout<<"请输入第"<<i+1<<"个数据"<<endl;
        cin>>p->a;
        pre->next=p;
        pre=pre->next;
        p->next=NULL;
    }
    cout<<"创建完毕"<<endl;
    return head;
}
void reverse(struct node*head,int high,int low)
{
    if(low<=high)
    {
        struct node*temphigh=head;
        struct node*templow=head;
        for(int i=0;i<low;i++)
        {
            templow=templow->next;
        }
        for(int i=0;i<high;i++)
        {
            temphigh=temphigh->next;
        }
        int p=templow->a;
        templow->a=temphigh->a;
        temphigh->a=p;
        reverse(head,--high,++low);
    }
    
}
struct node* reverse(struct node*head,int high)
{
    reverse(head,high,1);
    return head;
}
void print(struct node*head)
{
    struct node*pre=head;
    while(pre->next!=NULL)
    {
        cout<<pre->next->a<<" ";
        pre=pre->next;
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    struct node*head=createlist(5);
    reverse(head,5);
    print(head);
    return 0;
}
