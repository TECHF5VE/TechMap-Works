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
	//������������a
	int a[101];
	memset(a, 0, sizeof(a));
	cout << "����һ����m�Գ�ʼ������a��Ԫ�ظ���(ע��m��Ҫ����100)" << endl;
	int m;
	cout << "m=";
	cin >> m;
	cout << "\n�������������a��";
	for (int i = 1; i <= m; i++) cin >> a[i];

	//��������
	Node *p_t=a_to_link(a,m);

	//�����������
	Node* p_i = p_t->next;
	for (; p_i->next!= NULL; p_i = p_i->next) cout << p_i->data << "��";
	cout << p_i->data << endl;
	return 0;
}