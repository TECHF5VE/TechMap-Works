# include <stdio.h> 
# include <stdlib.h>
typedef struct student{
	int score;
	struct student *next;
	*creat(int n);
} LinkList;
void creat(LinkList *&head,int n){
	LinkList  *node, *end;//定义头节点，普通节点，尾部节点；
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		node->score=0;
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	
}
void change(LinkList *list,int n,int aaa) {//n为第n个节点
	LinkList *t = list;
	int i = -1;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
	
		t->score=aaa;
	}
	else {
		puts("节点不存在");
	}
}
void delet(LinkList *list, int n) {
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t->next;
		free(t);
	}
	else {
		puts("节点不存在");
	}
}
void insert(LinkList *list, int n) {
LinkList *t = list, *in;
int i = 0;
while (i < n && t != NULL) {
t = t->next;
i++;
}
if (t != NULL) {
in = (LinkList*)malloc(sizeof(LinkList));
printf("输入要插入的值");
scanf("%d", &in->score);
in->next = t->next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
t->next = in;//填充t节点的指针域，把t的指针域重新指向in
}
else {
puts("节点不存在");
}
}
void print(LinkList *list){

		LinkList *h = list;
        while (h->next != NULL) {
		h = h->next;
		printf("%d  ", h->score);
	}
}
int getelem(LinkList *list, int pos)
{
    student *p = list; //声明一个结点p，指向头结点

    int i = 0;

    while(p && i < pos)   
    {
        p = p->next;
        ++i;
    }
    if(!p || i > pos)
    {
       // cout << "第" << pos << "个元素不存在" << endl;
    }
    int getData = p->score;
    return getData;
} 
int main(){
	//第一题 
{ 
	int a[7]={1,3,5,7,9,11,13};
	int b[7]={2,3,5,7,11,13,17};
	int c[7+7-1]={0};
	int aa=0,bb=0,cc=0;
	for (;cc<=7+7-1;cc++)
		{
		if (bb==8)goto here2;
		if (aa==8)goto here1;			
		if(a[aa]<=b[bb])
			{							
				c[cc]=a[aa];
				aa++;
			}
		else{									
				c[cc]=b[bb];
				bb++;						
			}		
		}  
	here1:
	for (cc--;cc<=7+7-1+1;cc++){		
		c[cc]=b[bb];
		bb++;
	};
		here2:	
		for (cc--;cc<=7+7-1+1;cc++){			
		c[cc]=a[aa];
		aa++;
	}; 
		
	for (cc=0;cc<=7+7-1;cc++)//输出数组 
		{
			printf("%d ",c[cc]);
		}
}		
	//第二题(先构造相等长度的链表，再替换 
	{		printf("\n");
	int a[10]={0,1,2,3,4,5,6,7,8,9}; 
	int len = sizeof(a)/sizeof(a[0]);

	LinkList  *lstt= NULL;
	creat(lstt,len);	
	for(int i=0 ;i<10;i++)
	{ 
	change(lstt,i,a[i]);
	} 
	print(lstt);

}
	//第三题
{	printf("\n");	
	LinkList  *ls1= NULL; 
	LinkList  *ls2= NULL;
		LinkList  *ls3= NULL;
	int aaa[4]={1,2,3,5};
	int j=0;
	creat(ls1,4);
	for(;j<4;j++)
	{ 
	change(ls1,j,aaa[j]);
	} 
	print(ls1);
	printf("\n");
	int bbb[4]={2,4,7,8};
	int k=0;
	creat(ls2,4);
	for(;k<4;k++)
	{ 
	change(ls2,k,bbb[k]);
	} 
	print(ls2);
	printf("\n");
	creat(ls3,8);
	int ccc[8]={0,0,0,0,0,0,0,0};
{ int aaaaa=0,bbbbb=0,ccccc=0;
	
	for (;ccccc<4+4;ccccc++)
		{
		if (bbbbb==4)goto here222;
		if (aaaaa==4)goto here111;			
		if(aaa[aaaaa]<=bbb[bbbbb])
			{							
				ccc[ccccc]=aaa[aaaaa];
				aaaaa++;
			}
		else{									
				ccc[ccccc]=bbb[bbbbb];
				bbbbb++;						
			}		
		}  
	here111:
	for (;ccccc<=4+4-1+1;ccccc++){		
		ccc[ccccc]=bbb[bbbbb];
		bbbbb++;
	};
		here222:	
		for (;ccccc<=4+4-1+1;ccccc++){			
		ccc[ccccc]=aaa[aaaaa];
		aaaaa++;
	}; 
		
	for (ccccc=0;ccccc<4+4;ccccc++)//输出数组 
		{
			printf("%d ",ccc[ccccc]);
		}
}
	
}	
	return 0;
}
