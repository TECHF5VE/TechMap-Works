//
//  main.cpp
//  整合排列链表
//
//  Created by 强宇琛 on 2019/11/4.
//  Copyright © 2019 强宇琛. All rights reserved.
//

#include <iostream>
using namespace std;
struct note
{
    int i;
    struct note *next;
};
struct note* creatlist(int n)
{
    struct note *head=new struct note;
    struct note *former=head;
    for(int i=0;i<n;i++)
    {
        struct note *p=new struct note;
        cout<<"请输入列表中第"<<i+1<<"个数据"<<endl;
        cin>>p->i;
        former->next=p;
        former=p;
        p->next=NULL;
    }
    cout<<"录入完毕"<<endl;
    return head;
}



struct note* combine(struct note*head1,struct note*head2,int n,int m)
{
    struct note*head=new struct note;
    struct note *pre=head;
    struct note*temp1=head1->next;
    struct note*temp2=head2->next;
        for(int i=0;i<n;i++)
    {
        struct note *p=new struct note;
        p->i=temp1->i;
        temp1=temp1->next;
        pre->next=p;
        pre=p;
        p->next=NULL;
        
    }

    for(int i=0;i<m;i++)
    {
        
        struct note*p=new struct note;
        p->i=temp2->i;
        temp2=temp2->next;
        pre->next=p;
        pre=p;
        p->next=NULL;
        
    }
    return head;
}
struct note* sort(struct note*head,int a)
{
    struct note*pre=head->next;
    for(int i=a;i>1;i--)
    {
       for(int j=0;j<a-1;j++)
       {
           if(pre->i>pre->next->i)
           {
               int temp=pre->next->i;
               pre->next->i=pre->i;
               pre->i=temp;
           }
           pre=pre->next;
       }
        pre=head->next;
    }
    return head;
}
void print(struct note*head,int a)
{
    struct note*temp=head->next;
    for(int i=0;i<a;i++)
    {
        cout<<temp->i<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {

    struct note*list1=creatlist(3);
    struct note*list2=creatlist(4);
    struct note *head=combine(list1, list2, 3, 4);
    print(sort(head,7),7);
    //cout<<head->next->i<<endl;;
    return 0;
}
