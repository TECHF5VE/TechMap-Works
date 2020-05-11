/*
任务作业1： 通过给定的一段字符串依次输入建立一颗二叉树
            并使用递归前序、中序、后序遍历这棵二叉树。

任务作业2： 给定一个二叉树，层序遍历它。 
            -说明:层序遍历即逐层从左到右遍历一个二叉树。

任务作业4： 在不改变一棵二叉树中其他节点中序遍历顺序的条件下
            删除二叉树中指定的任意节点。
*/

#include<iostream>
#include<queue>
using namespace std;
typedef struct BiNode
{
	char data;
	struct BiNode* Left, * Right;
}*BiTree;

void CreatBiTree(BiTree &T)//创建树
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
void PreOrderTraversal(BiTree BT)//先序遍历
{
	if (BT)
	{
		cout << BT->data;
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

void InOrderTraversal(BiTree BT)//中序遍历
{
	if (BT)
	{
		InOrderTraversal(BT->Left);
		cout << BT->data;
		InOrderTraversal(BT->Right);
	}
}
void PostOrderTraversal(BiTree BT)//后序遍历
{
	if (BT)
	{
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		cout << BT->data;
	}
}

void LevelOrderTraversal(BiTree BT)//层序遍历
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
BiTree find_InOrderTraversal(BiTree BT)//中序寻找
{
	if (!BT)  return NULL;
	else if (!BT->Left)
		return BT;//找到根结点并返回
	else
		return find_InOrderTraversal(BT->Left);//沿左分支继续查
}
BiTree Delete(BiTree BT, char X)//       删除指定结点
{
	BiTree Temp;
	if (!BT)cout << "要删除的元素未找到" << endl;
	else if (X != BT->data)//左子树递归删除
		BT->Left = Delete(BT->Left, X);
	else if (X != BT->data)//左子树递归删除
		BT->Right = Delete(BT->Right, X);
	else//找到要删除的结点
		if (BT->Left && BT->Right)//被删除的结点有左右两棵子树
		{
			Temp = find_InOrderTraversal(BT->Right);//在右子树中找到最小的元素填充到被删除的结点位置
			BT->data = Temp->data;
			BT->Right = Delete(BT->Right, Temp->data);/*删除填充结点*/
		}
		else//被删除结点有一个或无子结点
		{
			Temp = BT;
			if (!BT->Left)   BT = BT->Right;//有右孩子或无孩子
			else if (!BT->Right)   BT = BT->Left;//有左孩子或无孩子
			delete Temp;
		}
	return BT;
}

int main() {
	BiTree T=NULL;
	cout << "创建一颗树，用“#”表示空树:" << endl;
	CreatBiTree(T);
	cout << "先序递归遍历：" << endl;
	PreOrderTraversal(T);
	cout << endl;
	cout << "中序递归遍历：" << endl;
	InOrderTraversal(T);
	cout << endl;
	cout << "后序递归遍历：" << endl;
	PostOrderTraversal(T);
	cout << endl;
	cout << "层序遍历：" << endl;
	LevelOrderTraversal(T);
	cout << endl;
	char x;
	cout << "请输入要删除的结点：";
	cin >> x;
	T = Delete(T, x);
	cout << "删除后，中序遍历：" << endl;
	InOrderTraversal(T);
	system("pause");
	return 0;
}

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
