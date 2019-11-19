#include<iostream>
#include<cstring>

using namespace std;

struct Node {
	int data;
	Node* next;
}*p,*r;

Node* a_to_link(int* a,int m) {
	Node *head = new Node;
	head->next = NULL;
	r = head;
	for (int i = 1; i <= m; i++) {
		p = new Node;
		p->data = a[i];
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return head;
}

int main() {
	//给定有序数列a
	int a[101];
	memset(a, 0, sizeof(a));
	cout << "输入一个数m以初始化数组a的元素个数(注：m不要超过100)" << endl;
	int m;
	cout << "m=";
	cin >> m;
	cout << "\n请给定有序数组a：";
	for (int i = 1; i <= m; i++) cin >> a[i];

	//用链表储存
	Node *p_t=a_to_link(a,m);

	//遍历输出链表
	Node* p_i = p_t->next;
	for (; p_i->next!= NULL; p_i = p_i->next) cout << p_i->data << "→";
	cout << p_i->data << endl;
	return 0;
}