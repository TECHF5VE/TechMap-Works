# task_03学习笔记：

## 二叉树的存储结构

```
typedef struct BiNode
{
   TElemType data;
   struct BiNode *Left,*Right;
}*BiTree,BiTNode;
```

## 二叉树的遍历

**1 先序遍历**

①访问根节点

②先序遍历左子树

③先序遍历右子树

```
void PreOrderTraversal(BiTree BT)
{
     if(BT)
     {
        cout<<BT->data;
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
     }
}
```

![](https://raw.githubusercontent.com/defeat5839/PicGo/master/20200414201132.png?token=ANS5YNBDDAIL4R7JBHPHQQS6SWULG)

①中序遍历左子树

②访问根节点

③中序遍历右子树

```
void InOrderTraversal(BiTree BT)
{
     if(BT)
     {
        InOrderTraversal(BT->Left);
        cout<<BT->data;
        InOrderTraversal(BT->Right);
     }
}
```

![中序遍历流程图](https://raw.githubusercontent.com/defeat5839/PicGo/master/20200413134915.png?token=ANS5YNDMYPKEJNS5H2RED2S6SP62A)

**3 后序遍历**

①后序遍历左子树

②后序遍历右子树

③访问根节点

```
void PostOrderTraversal(BiTree BT)
{
     if(BT)
     {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        cout<<BT->data;
     }
}
```

![后序遍历流程图](https://raw.githubusercontent.com/defeat5839/PicGo/master/20200413135512.png?token=ANS5YNCD2PV3SNME3AKVO2K6SP7QA)

**4  层序遍历**

①根节点入队，并用front指针标记

②队头出队，并将左右孩子拉进队列

③重复①②，直到队列为空

```
#include<queue>
void LevelOrderTraversal(BiTree BT)
{
  if(BT==NULL)  return;
  queue<BiNode*> q;
  q.push(BT);
  while(!q.empty())
  {
     BiNode *front=q.front();
     q.pop();
     cout<<front->data;
     if(front->Left)
     {
        q.push(front->Left);
     }
     if(front->Right)
     {
        q.push(front->Right);
     }
  }
}
```

![](https://raw.githubusercontent.com/defeat5839/PicGo/master/20200414202536.png?token=ANS5YNHXHIBMPGSPS2S6KK26SWWAA)

## 二叉树的建立

其实建立二叉树，也是利用了**递归**的原理。只不过在原来应该是打印结点的地方，改成了生成结点、给结点赋值的操作而已。

```
void CreatBiTree(BiTree &T)
{
   char ch;
   cin>>ch;
   if(ch=="#")
   {
      (*T)=NULL;
   }
   else
   {
      *T=new BiTNode;
      if(!*T)
      {
         exit(OVERFLOW);
      }
      (*T)->data=ch;
      CreatBiTree(&(*T)->Left);
      CreatBiTree(&(*T)->Right);
   }
}
```

注：对二叉树的使用，主要是调用一个指向根节点的指针来实现的。因为函数传参是单向值传递，所以想改变指针的值的话，则必须传递**二重指针**

## 二叉搜索树

（二叉排序树、二叉查找树）

1、二叉树为空

2、（1）非空左子树的所有键值**小于**其根结点的键值

（2）非空右子树的所有键值**大于**其根结点的键值

（3）左、右子树都是二叉搜索树

![](https://raw.githubusercontent.com/defeat5839/PicGo/master/20200415001134.png?token=ANS5YNF24JFP2YCUNNJN2AS6SXQPO)

#### 特别函数

```
//查找函数
Position Find(ElementType X,BiTree BST);//从二叉树中查找元素X，并返回所在结点的地址
Position FindMin(BiTree BST);//从二叉树中查找并返回最小元素所在结点的地址
Position FindMax(BiTree BST);//从二叉树中查找并返回最大元素所在结点的地址
//插入函数
BiTree Insert(ElementType X,BiTree BST);
//删除函数
BiTree Delete(ElementType X,BiTree BST);
```

#### 二叉搜索树的查找：Find

`查找的效率决定于树的高度`

（1）查找从**根结点**开始，如果树为空，返回NULL;

（2）如果搜索树非空，则根结点和X进行比较，

​      ①若X**小于**根结点键值，只需在**左子树**继续搜索；

​      ②若X**大于**根结点键值，只需在**右子树**继续搜索；

​      ③若两者结果是**相等**的，搜索完成，返回指向此结点的指针;

```
//尾递归...效率不高，尾递归都可以用循环来代替
Position Find(ElementType X,BiTree BST)
{
   if(!BST)  return NULL;//查找失败
   if(X>BST->data)
      return Find(x,BST->Right);
   else if(X<BST->data)
      return Find(x,BST->Light);
   else 
      return BST;
}
```

```
//循环  ...
Position Find(ElementType X,BiTree BST)
{
   while(BST)
   {
      if(X>BST->data)
         BST=BST->Right;
      else if(X<BST->data)
         BST=BST->Left;
      else 
         return BST;
   }
   return NULL;
}
```

**寻找最小值**

```
//用递归
Position FindMin(BiTree BST)
{
   if(!BST)  return NULL;
   else if(!BST->Left)
          return BST;//找到根结点并返回
   else
       return FindMin(BST->Left);//沿左分支继续查找
}

//用循环
Position FindMin(BiTree BST)
{
   if(BST)  
     while(BST->Left)
     {
        BST=BST->Left;//一直到最左
     }
     return BST; 
}
```

**寻找最大值**

```
//用递归
Position FindMax(BiTree BST)
{
   if(!BST)  return NULL;
   else if(!BST->Right)
          return BST;//找到根结点并返回
   else
       return FindMax(BST->Right);//沿左分支继续查找
}

//用循环
Position FindMin(BiTree BST)
{
   if(BST)  
     while(BST->Right)
     {
        BST=BST->Right;//一直到最右
     }
   return BST; 
}
```

### 二叉搜索树的插入

```
BiTree Insert(ElementType X,BiTree BST)
{
   if(!BST)//若树为空，返回一个结点的二叉搜索树
   {
      BST=new BiNode;
      BST->data=X;
      BST->Left=BST->Right=NULL;
   }
   else
   {
      if(X<BST->data)
      {
         BST->Left=Insert(X,BST->Left);
      }
      else if(X>BST->Right)
      {
         BST->Right=Insert(X,BST->Right);
      }
      //else X已经存在
   }
   return BST;
}
```

**删除函数**

分三种情况：

1、要删除的是**叶结点**：直接删除，并再修改其父结点指针--置为**NULL**

2、要删除的结点**只有一个孩子**结点：将其父结点的指针指向要删除结点的孩子结点

3、要删除的结点有左、右两颗子树：①取右子树的最小元素代替。②取左子树的最大元素代替。

```
BiTree Delete(ElementType X,BiTree BST)
{
   Position Temp;
   if(!BST)cout<<"要删除的元素未找到"<<endl;
   else if(X<BST->data)//左子树递归删除
       BST->Left=Delete(X,BST->Left);
   else if(X>BST->data)//左子树递归删除
       BST->Right=Delete(X,BST->Right);
   else//找到要删除的结点
       if(BST->Left&&BST->Right)//被删除的结点有左右两棵子树
         {
            Temp=FindMin(BST->Right);//在右子树中找到最小的元素填充到被删除的结点位置
            BST->data=Temp->data;
            BST->Right=Delete(X,BST->Right);/*在删除结点的右子树删除最小元素，因为填充到被删除结点的地方了*/
         } 
       else//被删除结点有一个或无子结点
        {
            Temp=BST;
            if(!BST->Left)   BST=BST->Right;//有右孩子或无孩子
            else if(!BST->Right)   BST=BST->Left;//有左孩子或无孩子
            delete Temp;
        }
   return BST;
}
```

补充：因为能力有限，任务5--实现一个简单的登录功能，并未能完成。