## 1
## 2
### 选择排序
```
#include <stdio.h> 
main()
{
	int nums[5],i,j,min,b;
	for(i=0;i<5;i++)
	scanf("%d",nums+i);
	for(i=0;i<5;i++)
	{
		min=i;
		for(j=i+1;j<5;j++)
		{
			if(nums[min]>nums[j])
			min=j;
		}
		if(min!=i)
		{
			b=nums[i];
			nums[i]=nums[min];
			nums[min]=b;
		}
	}
	for(i=0;i<5;i++)
	printf("%2d",nums[i]);
}
```
### 插入排序
```
#include <stdio.h> 
main()
{
	int nums[5],i,j,t;
	for(i=0;i<5;i++)
    scanf("%d",nums+i);
	for(i=1;i<5;i++)
	{
		t=nums[i];
		j=i-1;
		while(j>=0&&nums[j]>t)
		{
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1]=t;
	}
	for(i=0;i<5;i++)
        printf("%3d",nums[i]);
}
```
## 3
```
>>> dict = {'Name':'Alice','Age':20,'School':'UJS'}
>>> del dict['Age']
>>> dict["School"]="jiangsudaxue"
>>> dict["Class"]="1901"
>>> for item in dict.items():
	print(item)

	
('Name', 'Alice')
('School', 'jiangsudaxue')
('Class', '1901')

```
## 4
```
def triangles():
    p = [1]
    while True:
        p = [1] + [p[i] + p[i+1] for i in range(len(p)-1)] + [1]
```
2019.11.24 by lihanlong