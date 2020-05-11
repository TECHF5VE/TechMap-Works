/*
任务作业 3  给你 a 和 b 这两棵二叉搜索树，请你返回这两棵二叉树上所有整数的升序序列。
			时间复杂度为O(m+n)的算法
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
BiTree insert( BiTree &BST,int x)//插入节点，用于创建树
{
	if (!BST)//若树为空，返回一个结点的二叉搜索树
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
		//else x已经存在
	}
	return BST;
}
BiTree CreatTree( BiTree& BST)//创建树
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
void Inordertraversal_storage(BiTree BST, queue<int> &s)//将树的值储存到队列中
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
	cout << "创建第一棵树，输入-1结束创建" << endl;
	CreatTree(t1);
	cout << "创建第二棵树，输入-1结束创建" << endl;
	CreatTree(t2);
	Inordertraversal_storage(t1, s1);//将树的值储存到队列中
	Inordertraversal_storage(t2, s2);
	cout << "合并升序输出：" << endl;
	MergedoubleTree(s1, s2);
	system("pause");
	return 0;
}
