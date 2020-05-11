/*
������ҵ 3  ���� a �� b �����ö��������������㷵�������ö������������������������С�
			ʱ�临�Ӷ�ΪO(m+n)���㷨
*/
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
typedef struct BiNode
{
	int data;
	struct BiNode* left, * right;
}*BiTree;
BiTree insert( BiTree &BST,int x)//����ڵ㣬���ڴ�����
{
	if (!BST)//����Ϊ�գ�����һ�����Ķ���������
	{
		BST = new BiNode;
		BST->data = x;
		BST->left = BST->right = NULL;
	}
	else
	{
		if (x < BST->data)
		{
			BST->left = insert(BST->left,x);
		}
		else if (x > BST->data)
		{
			BST->right = insert( BST->right,x);
		}
		//else x�Ѿ�����
	}
	return BST;
}
BiTree CreatTree( BiTree& BST)//������
{
	int k=0;
	cin >> k;
	do
	{
		insert(BST, k);
		cin >> k;
	} while (k != -1);
	return BST;
}
void Inordertraversal_storage(BiTree BST, queue<int> &s)//������ֵ���浽������
{
	if (BST)
	{
		Inordertraversal_storage(BST->left,s);
		s.push(BST->data);	
		Inordertraversal_storage(BST->right,s);
	}
}
void MergedoubleTree(queue<int> s1, queue<int> s2)//
{
	vector<int> arry;
	while (!s1.empty() || !s2.empty())
	{

		if (s1.front() <= s2.front())
		{
			arry.push_back(s1.front());
			s1.pop();
		}
		else
		{
			arry.push_back(s2.front());
			s2.pop();
		}
		if (s1.empty())
		{
			while (!s2.empty())
			{
				arry.push_back(s2.front());
				s2.pop();
			}
		}
		if (s2.empty())
		{
			while (!s1.empty())
			{
				arry.push_back(s1.front());
				s1.pop();
			}
		}
	}
	for (int i = 0; i < arry.size(); i++)
	{
		cout << arry[i] << " ";
	}
}
int main()
{
	queue<int> s1;
	queue<int> s2;
	BiTree t1=NULL; 
	BiTree t2 = NULL; 
	int n = 0;
	cout << "������һ����������-1��������" << endl;
	CreatTree(t1);
	cout << "�����ڶ�����������-1��������" << endl;
	CreatTree(t2);
	Inordertraversal_storage(t1, s1);//������ֵ���浽������
	Inordertraversal_storage(t2, s2);
	cout << "�ϲ����������" << endl;
	MergedoubleTree(s1, s2);
	system("pause");
	return 0;
}
