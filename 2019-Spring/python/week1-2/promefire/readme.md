# python学习

​       这次任务中，开始用input想输入几个数字`1,2,3`，但输出后都成了一个字符串`'1,2,3'` ,查了一下在python3中input功能会将用户输入的内容作为“字符串”来对待，在python2中是作为表达式来对待，

另注：python3中没有`raw_input`函数

#### 1、input()

输入的为字符串

```
x=input()                  //字符串
xx=int(input())            //转化为int型
```

#### 2、空格的使用

​	之前学习python用的是交互命令行，对空格要求不高，导致多处出现错误。

这次改用pycharm，导致多处出现错误，发现对空格要求很严格，代码摘抄如下：

* 等号左右要有空格

```
d['school'] = 'DPS school'
```

* 逗号后     、

```
print(x, ":", d[x]）
```



还有一些规范用法：

* 函数后空两行

![IMG](C:\Users\lenovo\Desktop\IMG_4029(20190414-100353).jpg)



#### 3、文件的打开

   打开方式：`open` 、`with open` 

​    注：用`open`打开要注意用`close()` 关闭



   

  

### 以下是之前学习python的笔记



#### 1. python对大小写敏感

#### 用全部大写的变量名来表示常量

#### 2.list 与 tuple

 list  --[]                                ;				tuple  --（）;

list元素可更改；                                            tuple元素不可变

```
classmate[-1]                     		//最后一位元素

classmate.append                 		//在末尾加

                  .insert[i]             //插入到指定位置

                  .pop[i]                //删除指定位置元素                                                            

  classmate[i]                            //更改直接赋值      

```

​                                                                                                                                         2019.03.25 23:19

#### 3. if...elif(else if 的简写)...else

#### 4.循环

```
1、
for x in range(101):                         //以冒号结尾
	sum=sum+x
	print(sum)
```



```
2、
sum=0
n=99
while n>0:
	sum=sum+n
	n=n-1
	print(sum)
```



#### 5、dict（字典） Key-value

```
>>>d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}     //定义使用{}
>>>d['Michael'] 								//查找使用[]
95
```

 数据放入dict中(1.初始化)2.

> 插入数据

```
>>>d['Adam'] = 67

>>>d['Adam']

67

```

> 删除数据

```
d.pop('key')
```

> 遍历数据  

```
for x in d:
	print(x, ':', d[x])
```



判断Key是否存在于字典中

一是通过`in`判断key是否存在： 

```
'Bob' in d
d.get('Bob')

```

二是通过dict提供的`get()`方法，如果key不存在，可以返回`None`，或者自己指定的value：

```
>>> d.get('Thomas')
>>> d.get('Thomas', -1)
-1
```

> key  必须是不可变的，可以是字符串、整数；list可变不能使用

#### 6、set

形式  d([ a,b,c])

> 过滤list中的重复元素

```
>>> s1 = set([1, 2, 3])
>>> s2 = set([2, 3, 4])
>>> s1 & s2
{2, 3}
>>> s1 | s2
{1, 2, 3, 4}                               //可以取交集 并集
>>>s1.add(6)                               //添加元素
>>>s1.remove(1)							//删除元素
```

```
字符串
a='abc'
b=a.replace('a','A')                        //替换
>>>a
'abc'
>>>b
'Abc'
```

​                                                                                                                                       2019/3/28

#### 7、函数

定义函数

> ​	`def` +函数名+（）：

> ​        `pass` 占位符  用于空函数

参数检查 内联函数`isinstance()`

```
 def compare(age):
>	if isinstance(age,(int,float):                  //变量age的类型不是其后tuple中的类型
     //if not isinstance(age,int)                //必须是int类型
 		if age>=18:
			return age-18,age,age+5
		else:
			pass
```

#### 8、切片（slice）

```
>>>n=list(range(100))
>>>n[1:3]
[2,3,4]
>>>n[-3:-1]                              //取出数不包括n[-1]
>>> n[:10:2]
[0, 2, 4, 6, 8]
>>> n[::5]
[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95]
>>> 
```

n[:20:5]   前二十个元素每个五个取一个

n[::5]____所有元素每隔五个取一个

<font color=red>切片可对list,tuple操作，也可对字符串操作</font>

```
>>> 'ABCDEFG'[:3]
'ABC'
>>> 'ABCDEFG'[::2]
'ACEG'
```

​                                                                          

​                                         2019/4/1 23：31



