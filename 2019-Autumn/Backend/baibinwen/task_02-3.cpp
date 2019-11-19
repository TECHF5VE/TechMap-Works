#include<iostream>

using namespace std;

const int MAXNUM = 65536;

struct Node {
	int data;
	Node* front, * next;
}*p, * r;

Node* Node_creat(int m) {
	Node* head_a = new Node;
	head_a->front = NULL;
	r = head_a;
	for (int i = 1; i <= m; i++) {
		p = new Node;
		cin >> p->data;
		p->next = NULL;
		p->front = r;
		r->next = p;
		r = p;
	}
	p = new Node;
	p->data = MAXNUM;
	p->next = NULL;
	p->front = r;
	r->next = p;
	r = p;
	return head_a;
}

void Node_insert(int n, Node* pp) {
	p = new Node;
	p->data = n;
	p->next = pp;
	p->front = pp->front;
	pp->front->next = p;
	pp->front = p;
}

int main() {
	//给定两个有序数列 
	cout << "输入两个数m、n以初始化链表a、链表b的元素个数(注：m、n均不要超过100)" << endl;
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	cout << "请给定有序链表a：";
	Node* head_a = Node_creat(m);
	cout << "请给定有序链表b：";
	Node* head_b = Node_creat(n);

	//处理头部 
	Node* p_b = head_b->next,*p_a=head_a->next;
	while (p_b->data < p_a->data) {
		Node_insert(p_b->data, p_a);
		p_b = p_b->next;
	}
	//插入数列 b 
	for (; p_b->next!= NULL; p_b = p_b->next) {
		for (;p_a->data <= p_b->data ; p_a = p_a->next);
		Node_insert(p_b->data, p_a);
	}

	//输出合并后的数列 a
	cout << "\n合并后的链表：";
	p_a = head_a->next;
	cout << p_a->data;
	for (p_a=p_a->next; p_a->next!=NULL; p_a = p_a->next)
		cout << "→" << p_a->data;
	cout << endl;

	return 0;
}