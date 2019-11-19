#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
}*p,*r;

Node* rever(Node* pp) {
	if (pp == NULL||pp->next == NULL) return pp;
	Node* p_i=rever(pp->next);
	pp->next->next= pp;
	pp->next = NULL;
	return p_i;
}

Node* link_creat(int n) {
	Node* head = new Node;
	r = head;
	for (int i = 0; i < n; i++) {
		p = new Node;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return head;
}
void link_output(Node* pp) {
	for (; pp->next != NULL; pp = pp->next) cout << pp->data << "→";
	cout << pp->data << endl;
}

int main() {
	//初始化
	cout << "请输入一个数n，以初始化链表长度\nn=";
	int n;
	cin >> n;
	cout << "请初始化链表：";
	Node * head = link_creat(n);

	//显示原链表
	link_output(head->next);

	//反转并输出
	link_output(rever(head->next));
	return 0;
}