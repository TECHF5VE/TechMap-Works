/*
������ҵ1�� ͨ��������һ���ַ����������뽨��һ�Ŷ�����
            ��ʹ�õݹ�ǰ�����򡢺��������ö�������

������ҵ2�� ����һ��������������������� 
            -˵��:����������������ұ���һ����������

������ҵ4�� �ڲ��ı�һ�ö������������ڵ��������˳���������
            ɾ����������ָ��������ڵ㡣
*/

#include<iostream>
#include<queue>
using namespace std;
typedef struct BiNode
{
	char data;
	struct BiNode* Left, * Right;
}*BiTree;

void CreatBiTree(BiTree &T)//������
{
	char ch;
	cin >> ch;

	if (ch == '#')
	{
		(T) = NULL;
	}
	else
	{
		T = new BiNode;
		if (!T)
		{
			exit(OVERFLOW);
		}
		(T)->data = ch;
		CreatBiTree(T->Left);
		CreatBiTree(T->Right);
	}
}
void PreOrderTraversal(BiTree BT)//�������
{
	if (BT)
	{
		cout << BT->data;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

void InOrderTraversal(BiTree BT)//�������
{
	if (BT)
	{
		InOrderTraversal(BT->Left);
		cout << BT->data;
		InOrderTraversal(BT->Right);
	}
}
void PostOrderTraversal(BiTree BT)//�������
{
	if (BT)
	{
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		cout << BT->data;
	}
}

void LevelOrderTraversal(BiTree BT)//�������
{
	if (BT == NULL)  return;
		queue<BiNode*> q;
	q.push(BT);
	while (!q.empty())
	{
		BiNode* front = q.front();
		q.pop();
		cout << front->data;
		if (front->Left)
		{
			q.push(front->Left);
		}
		if (front->Right)
		{
			q.push(front->Right);
		}
	}
}
BiTree find_InOrderTraversal(BiTree BT)//����Ѱ��
{
	if (!BT)  return NULL;
	else if (!BT->Left)
		return BT;//�ҵ�����㲢����
	else
		return find_InOrderTraversal(BT->Left);//�����֧������
}
BiTree Delete(BiTree BT, char X)//       ɾ��ָ�����
{
	BiTree Temp;
	if (!BT)cout << "Ҫɾ����Ԫ��δ�ҵ�" << endl;
	else if (X != BT->data)//�������ݹ�ɾ��
		BT->Left = Delete(BT->Left, X);
	else if (X != BT->data)//�������ݹ�ɾ��
		BT->Right = Delete(BT->Right, X);
	else//�ҵ�Ҫɾ���Ľ��
		if (BT->Left && BT->Right)//��ɾ���Ľ����������������
		{
			Temp = find_InOrderTraversal(BT->Right);//�����������ҵ���С��Ԫ����䵽��ɾ���Ľ��λ��
			BT->data = Temp->data;
			BT->Right = Delete(BT->Right, Temp->data);/*ɾ�������*/
		}
		else//��ɾ�������һ�������ӽ��
		{
			Temp = BT;
			if (!BT->Left)   BT = BT->Right;//���Һ��ӻ��޺���
			else if (!BT->Right)   BT = BT->Left;//�����ӻ��޺���
			delete Temp;
		}
	return BT;
}

int main() {
	BiTree T=NULL;
	cout << "����һ�������á�#����ʾ����:" << endl;
	CreatBiTree(T);
	cout << "����ݹ������" << endl;
	PreOrderTraversal(T);
	cout << endl;
	cout << "����ݹ������" << endl;
	InOrderTraversal(T);
	cout << endl;
	cout << "����ݹ������" << endl;
	PostOrderTraversal(T);
	cout << endl;
	cout << "���������" << endl;
	LevelOrderTraversal(T);
	cout << endl;
	char x;
	cout << "������Ҫɾ���Ľ�㣺";
	cin >> x;
	T = Delete(T, x);
	cout << "ɾ�������������" << endl;
	InOrderTraversal(T);
	system("pause");
	return 0;
}

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
