## 1.链表  
这两周考试有点多，先行提交，日后补上该题，请原谅。  
## 2.排序  
方法一(插入排序):
```
#include <stdio.h>
main()
{ 
    int  a[5]={5,2,3,1,4},i,j,t;
    printf("原先数列为:\n");
    for(i=0;i<5;i++)
    printf("%5d",a[i]);
    
    printf("\n");
    for(i=1;i<5;i++)
	{
      t=a[i];  
      for(j=i-1;a[j]>t&&j>=0;j--)
            {
            a[j+1]=a[j]; 
			}
	  a[j+1]=t;
    }
    printf("排序后的数列为:\n");
    for(i=0;i<5;i++)
       printf("%5d",a[i]);
       printf("\n");
}
```
方法二（选择排序）：
```
# include <stdio.h>
main()
{
	int a[5]={5,2,3,1,4},i,j,k,t;
	printf("原数列为:\n");
	for(i=0;i<5;i++)
	   {
	   	printf("%5d",a[i]);
	   }
	   printf("\n");
	for(i=0;i<4;i++)
	   {             
	    k=i;             
	   	for(j=i+1;j<5;j++)
	   	  if(a[j]<a[k])
	   	     k=j;
	   	     t=a[k];
			 a[k]=a[i];
			 a[i]=t;
	   }
	   printf("排序后的数列为:\n");
	   for(i=0;i<5;i++)
	     printf("%5d",a[i]);
	     printf("\n");
}
```

## 3.Python字典  
```  
>>> dict={'Name':'Alice','Age':20,'School':'UJS'}
>>> del dict['Age']
>>> dict['School']=jiangsudaxue
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'jiangsudaxue' is not defined
>>> dict['School']='jiangsudaxue'
>>> dict['Class']=1901
>>> dict
{'Name': 'Alice', 'School': 'jiangsudaxue', 'Class': 1901}
```  

## 4.杨辉三角  
```  
>>> def triangles():
	p = [1]
	while True:
		yield p
		p=[1]+[p[i]+p[i+1] for i in range (len(p)-1)]+[1]

		
>>> n=0
>>> for t in triangles():
	print(t)
	n=n+1
	if n==10:
		break

	
[1]
[1, 1]
[1, 2, 1]
[1, 3, 3, 1]
[1, 4, 6, 4, 1]
[1, 5, 10, 10, 5, 1]
[1, 6, 15, 20, 15, 6, 1]
[1, 7, 21, 35, 35, 21, 7, 1]
[1, 8, 28, 56, 70, 56, 28, 8, 1]
[1, 9, 36, 84, 126, 126, 84, 36, 9, 1]
```  