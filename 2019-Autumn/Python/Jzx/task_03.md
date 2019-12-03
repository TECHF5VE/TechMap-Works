# 1.
```C++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* l3 = new ListNode(0);
    ListNode* m = l1, *n = l2, *o = l3;
    int cup = 0;
    while (m != NULL || n != NULL)
	{
        int x = (m != NULL) ? m->val : 0;
        int y = (n != NULL) ? n->val : 0;
        int sum = x + y + cup;
        cup = sum / 10;
        o->next = new ListNode(sum % 10);
        o = o->next;
   		if (m != NULL)m = m->next;
        if (n != NULL)n = n->next;
    }
        if (cup>0)
		{
            o->next = new ListNode(cup);
            o = o->next;
        }
        return l3->next;
}
```
# 2.
## 1.选择排序
```C++
#include<iostream>
using namespace std;
int main()
{
	int MinIndex,a[] = { 5,2,3,1,4 };
	for (int i = 0; i < 4; i++)
	{
		int mid;
		MinIndex = i;
		for (int j = i+1; j < 5; j++)
		{
			if (a[MinIndex] > a[j])
			{
				MinIndex = j;
			}
		}
		mid = a[i];
		a[i] = a[MinIndex];
		a[MinIndex] = mid;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
```
## 2.插入排序
```C++
#include<iostream>
using namespace std;
int main()
{
	int MinIndex,a[] = { 5,2,3,1,4 };
	for (int j = 1; j < 5; j++)
	{

		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
```
# 3.
```python
>>> dict = {'Name':'Alice','Age':20,'School':'UJS'}
>>> print(dict)
>>> {'Name': 'Alice', 'Age': 20, 'School': 'UJS'}
>>> dict.pop('Age')
>>> 20
>>> print(dict)
>>> {'Name': 'Alice', 'School': 'UJS'}
>>> dict['School'] = "jiangsudaxue"
>>> print(dict)
>>> {'Name': 'Alice', 'School': 'jiangsudaxue'}
>>> dict['Class'] = 1901
>>> print(dict)
>>> {'Name': 'Alice', 'School': 'jiangsudaxue','Class':1901}
>>> for key,value in dict.items():
...     print("%s:%s" % (key,value))
...
Name:Alice
School:jiangsudaxue
Class:1901
```
# 4.
```python
def triangles():
    L = [1]
    while True:
        yield L
        L.append(0)
        L = [L[i-1]+L[i] for i in range(len(L))]
```