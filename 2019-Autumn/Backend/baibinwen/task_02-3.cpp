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
	//���������������� 
	cout << "����������m��n�Գ�ʼ������a������b��Ԫ�ظ���(ע��m��n����Ҫ����100)" << endl;
	int m, n;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	cout << "�������������a��";
	Node* head_a = Node_creat(m);
	cout << "�������������b��";
	Node* head_b = Node_creat(n);

	//����ͷ�� 
	Node* p_b = head_b->next,*p_a=head_a->next;
	while (p_b->data < p_a->data) {
		Node_insert(p_b->data, p_a);
		p_b = p_b->next;
	}
	//�������� b 
	for (; p_b->next!= NULL; p_b = p_b->next) {
		for (;p_a->data <= p_b->data ; p_a = p_a->next);
		Node_insert(p_b->data, p_a);
	}

	//����ϲ�������� a
	cout << "\n�ϲ��������";
	p_a = head_a->next;
	cout << p_a->data;
	for (p_a=p_a->next; p_a->next!=NULL; p_a = p_a->next)
		cout << "��" << p_a->data;
	cout << endl;

	return 0;
}