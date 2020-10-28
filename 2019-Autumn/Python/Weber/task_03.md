#第一题
```
#include<iostream>
#include<cmath>
using namespace std;
struct ListNode //结点结构体
{
	int data;//数据域
	ListNode* next;//指针域
	ListNode();
	ListNode(int x);//带参数构造函数
};
ListNode::ListNode()
{
	data = NULL;
	next = NULL;
}
ListNode::ListNode(int x)
{
	data = x;
	next = NULL;
}
class LinkList  //链表类
{
protected:
	ListNode* head;
	int length;
public:
	LinkList();
	LinkList(int a[], int n);//有参数的构造函数
	friend void addTwoNumbers(LinkList L1, LinkList L2);
};
LinkList::LinkList()
{
	head = NULL;
	length = 0;
}
//带参数构造函数的具体实现
LinkList::LinkList(int a[], int n)
{
	ListNode* p;
	p = head = new ListNode;
	for (int i = 0; i < n; i++)
	{
		p->next = new ListNode(a[i]);
		p = p->next;
	}
}
//两个单链表反向相加结果以单链表形式反向输出
void addTwoNumbers(LinkList L1, LinkList L2)
{
	int x(0), y(0);
	ListNode* p;
	ListNode* q;
	p = L1.head->next;
	q = L2.head->next;
	while (p != NULL && q != NULL)
	{
		x += p->data;
		p = p->next;
		y += q->data;
		q = q->next;
	}
	int z;
	z = x + y;
	int N(0), m(10);
	while (z / m)
	{
		++N;
		m = 10 * m;
	}
	int a[20];
	for (int i = 0; i < N; i++)
	{
		 a[i] =(z / pow(m, i)) % 10;
	
	}
	LinkList L3(a,N);
	ListNode* r = L3.head->next;
	cout << "两个链表相加后得到的新链表为：";
	while (r != NULL)
	{
		cout << r->data << " ";
	}
}
int main()
{
	int a[] = { 2, 4, 3 };
	int b[] = { 5, 6, 4 };
	LinkList listA(a,3) ;
	LinkList listB(b,3) ;
	addTwoNumbers(listA, listB);
	system("pause");
	return 0;
}
```
#第二题
```
/*选择排序*/
void SelectionSort(int a[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (a[min] > a[j])
			{
				int temp;
				temp = a[min];
				a[min] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
}
/*插入排序*/
void InsertSort(int a[], int len)
{
	int begin(1);
	int i(0);
	while (begin < len)
	{
		int temp = a[begin];
		for (i = begin - 1; i = 0; i--)
		{
			if (temp <= a[i])
			{
				a[i + 1] = temp;
					break;
			}
			a[i + 1] = a[i];
		}
		if (i < 0)
			a[0] = temp;
			begin++;
	}
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
}
```
#第三题
```
dict={'Name':'Alice','Age':'20','School':'UJS'}
del dict['Age']
dict['School']='jiangsudaxue'
dict['Class']=1901
for key,value in dict.items():
    print(key,value)
```
#第四题
```
def triangles():
    L=[1]
    while True:
            yield L
            L=[1]+[L[i-1]+L[i] for i in range(1,len(L))]+[1]


```
