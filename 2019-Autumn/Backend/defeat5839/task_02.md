---
title: 链表
tags: 链表,,小白
grammar_cjkRuby: true
---
## 时间复杂度
**常见的时间复杂度量级有**：
常数阶O(1)
对数阶O(logN)
线性阶O(n)
线性对数阶O(nlogN)
平方阶O(n²)
立方阶O(n³)
K次方阶O(n^k)【n的k次方，符号不会敲】
指数阶(2^n)

**上面从上至下依次的时间复杂度越来越大，执行的效率越来越低。**

![enter description here][1]


#### 链表：结构体变量与结构变量连接在一起
### 1.动态创建链表：动态内存申请+模板化设计
### 2.创建节点
typedef // 是自定义数据类型
#### 头插法
#### 尾插法
### 3.插入节点
(1)前插法（插入q）（时间复杂度为o（n)
(2)后插法(插入q）（时间复杂度为o（1）


### 4.删除节点
(1)删除r 的后继    (时间复杂度o（1））
                  
(2) 删除r的本身（时间复杂度为o（n））
                
(3)按值删除
                    
### 5.打印遍历链表
           p-next->data;
           p=p->next//向下移动一个节点
### 6.单链表的查找
（1）按值查找(x)
（2）按序号查找(i)
# 作业代码
### 作业一：
 ```#include<iostream>
   #include<algorithm>
   using namespace std;
   int main()
   {
    int m = 5, n = 4;
	int a[9] = { 1,3,5,7,9};
	int b[4] = { 2,4,6,8 };
	for (int i = 0; i < n; i++)
	{
		a[i + m] = b[i];
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m+n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a, a + (m + n));
	for (int i = 0; i < m + n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}
```
### 作业二：
```#include<iostream>
using namespace std;
struct arr
{
	int data;
	struct arr* next;
};
typedef struct arr LNode;
void creatlist(LNode*& head, int a[], int n)  // 建表
{
	LNode* s;
	head = new LNode;
	head->next = NULL;
	for (int i = n-1; i >= 0; --i)
	{
		LNode* s = new LNode;
		s->next = NULL;
		s->data = a[i];
		s->next = head->next;
		head->next = s;

	}
}
void show(LNode* C) // 显示表
{
	while (C->next!=NULL) {
		cout << C->next->data<<" ";
		C = C->next;
	}
	cout << endl;
}
int main()
{
	int a[5], i;
	cout << "请输入五个数： ";
	for (i = 0; i < 5; ++i)
		cin >> a[i];
	LNode* l = NULL;
	cout << "用链表输出为： ";
	creatlist(l, a, 5);
	show(l);
	system("pause");
}
```
### 作业三：
```#include<iostream>
using namespace std;
struct arr
{
	int data;
	struct arr* next;
};
typedef struct arr node;
void creatlist(node* head)
{
	head->next = NULL;
	int data;
	cout << "请输入数据建立链表  以0结束  ";
	cin >> data;
	while (data != 0)
	{
		node* p;
		p = new node;
		p->data = data;//输送数据给新节点的data
		head->next = p;
		head = p;
		p->next = NULL;
		cin >> data;
	}
}
void show(node* head)
{
	node* p;
	p = head;
	while (p->next != NULL)
	{
		cout << p->next->data << " ";
		p = p->next;
	}
}
node* merage(node* la, node* lb)//合并两个有序链表
{
	node* pa, * pb, * pc;
	pa = la->next;
	pb = lb->next;
	pc = la;
	free(lb);
	while (pa&&pb)
	{
		if (pa->data<=pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

	}
	if (pa)
	{
		pc->next = pa;
	}
	else
	{
		pc->next = pb;
	}
	return la;
}
int main()
{
	node* la = new node;
	node* lb = new node;
	creatlist(la);//创建第一个有序链表
	creatlist(lb);//创建第二个有序链表
	show(la);//表示第一个链表
	cout << endl;
	show(lb);//第二个链表
	merage(la, lb);//合并两个有序链表
	cout << endl;
	show(la);//最终合并
	system("pause");
	return 0;
}
```
### 作业四(反转）
```
#include<iostream>
using namespace std;
struct arr
{
	int data;
	struct arr* next;
};
typedef struct arr node;
node*creatlist(node* head)
{
	int data1;
	char flag1;
	head->next=NULL;
	cout << "请输入数据建立链表  以0结束    ";
	cin >> data1;
	while (data1!=0)
	{
		node*p = new node;
		p->data =data1;//输送数据给新节点的data
		p->next = head->next;
		head->next = p;
		cin >> data1;
	}
	return head;
}
void show(node* head)
{
	node* p=NULL;
	p = head;
	do{
		cout << p->next->data;
		p = p->next;
	}while (p->next != NULL);
	
}
int main()
{
	node* head=new node;
	creatlist(head);
	show(head);
	system("pause");
	return 0;
}
```
## 总结与感想：链表挺难的。               


  [1]: ./images/1573518358406.jpg "1573518358406.jpg"