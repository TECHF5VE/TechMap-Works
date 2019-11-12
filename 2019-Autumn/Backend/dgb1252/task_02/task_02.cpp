#include<iostream>
using namespace std;
void merge(int arr1[], int m, int arr2[], int n)
{
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
		arr1[k--] = arr1[i] >= arr2[j] ? arr1[i--] : arr2[j--];
	while (j >= 0)
		arr1[k--] = arr2[j--];
}//�ϲ�����
typedef struct node {
	int c;
	node* next;
}node1;
node* creatlist(int arr[], int n)
{
	node* head = new node;
	node* pre = head;
	for (int i = 0; i < n; i++)
	{
		node* p = new node;
		p->c = arr[i];
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}//��������
node* creatlist(int n)
{
	node* head = new node;
	node* pre = head;
	for (int i = 0; i < n; i++)
	{
		node* p = new node;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}//��������
void reverselist(node* head1, node* head2)
{
	node* p1 = head1;
	p1 = head1->next;
	node* pre = head1;
	while (p1->next != NULL)
	{
		pre = p1;
		p1 = p1->next;
	}//�õ���һ����������һ���ڵ�
	head2->next->c = p1->c;
	head2 = head2->next;
	delete p1;
	pre->next = NULL;
	if (head2->next == NULL)return;
	reverselist(head1, head2);
}//��ת����
void deletelist(node* head)
{
	node* p = head;
	while (head->next != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
	delete head;
}//ɾ������
void printlist(node* head)
{
	node* p = head;
	p = p->next;
	while (p != NULL)
	{
		cout << p->c << '\t';
		p = p->next;
	}
}//��ӡ����
node* mergelist_sort(node* head1, node* head2)
{
	node* p1 = head1;
	p1 = p1->next;
	node* p2 = head2;
	p2 = p2->next;
	node* head3 = new node;
	node* pre = head3;
	while (p1 != NULL && p2 != NULL)
	{
		node* p3 = new node;
		if (p1->c < p2->c)
		{
			p3->c = p1->c;
			p1 = p1->next;
		}
		else
		{
			p3->c = p2->c;
			p2 = p2->next;
		}
		pre->next = p3;
		pre = p3;
		p3->next = NULL;
		if (p1 == NULL)
		{
			for (; p2 != NULL; p2 = p2->next) { node* p3 = new node; p3->c = p2->c; pre->next = p3; pre = p3; p3->next = NULL; }
			break;
		}
		if (p1 == NULL)
		{
			for (; p1 != NULL; p1 = p1->next) { node* p3 = new node; p3->c = p1->c; pre->next = p3; pre = p3; p3->next = NULL; }
			break;
		}
	}
	return head3;
}//���ù鲢�ϲ���������
int main()
{
	////1.ʵ��ʱ��O(m+n),�ռ�O(1);
	int arr1[5] = { 1,3,5 };
	int arr2[2] = { 2,4 };
	merge(arr1, 3, arr2, 2);
	for (int i = 0; i < 5; i++)cout << arr1[i] << '\t';
/*///////2.������ת��Ϊ������
	int a[8]{ 1,4,2,5,1,4,3,8 };
	node* head = creatlist(a, 8);
	printlist(head);
	deletelist(head);*/
/*////3.��������������ϲ���һ���µ�����������

	int a[4] = { 1,2,3,5 }, b[4]{ 2,4,7,8 };
	node* heada = creatlist(a, 4);
	node* headb = creatlist(b, 4);
	node* headc = mergelist_sort(heada, headb);
	printlist(headc);
	deletelist(heada);
	deletelist(headb);
	deletelist(headc);
	*/

/*///4.�õݹ鷴תһ��������

	int a[8]{ 1,4,2,5,1,4,3,8 };
	node* head1 = creatlist(a, 8);
	node* head2 = creatlist(8);
	reverselist(head1, head2);
	printlist(head2);
	deletelist(head2);
	*/
	return 0;
}