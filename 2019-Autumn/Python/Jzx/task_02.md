# task_02.md
## 1: 
```python
>>> a = input()
2
>>> b = 1
>>> print(a+b)
```
input()输入值类型为str,所以变量a为字符串类型，而b为整数型,a+b出现类型错误。
应将a转为整数型后相加。
更改后如下:  
```python
>>> a = input()
2
>>> b = 1
>>> print(int(a)+b)
3
```
## 2:
```python
>>> a = 'abc'
>>> b = a
>>> a = 'def'
>>> print(b)
abc
```
## 3:
```python
>>> 7/3
2.3333333333333335
>>> 7//3
2
>>> 7.0//3
2.0
```
> 7/3与7//3的区别  
 + / 除法计算永远返回浮点数 
 + // 除法，称为地板除，两个整数的除法仍然是整数  
> 7//3与7.0//3的区别  
 + 7为整数型，7.0为浮点数型
> 原因  
 + // 除法的返回类型与参与计算的数据类型有关　　
## 4:
```python
>>> a = 1
>>> b = 2
>>> a,b = b,a
>>> print(a,b)
2 1
```
>原因
 + 变量并不存储值，只指向内存地址.
 + a,b = b,a 将a指向b的值2，将b指向a的值1
## 5:
```python
>>> a= 600
>>> x = id(a)
>>> del a
>>> b = 700
>>> y = id(b)
>>> x == y
True
```
```python
// 实测
>>> a = 600
>>> x = id(a)
>>> del a
>>> b = 10
>>> y = id(b)
>>> x == y
False
```
### 发现大数与小数的内存地址存在差异而且两个相邻小数的内存地址相差32  
> 代码如下:
```python
>>> print(id(1))
140707510579456
>>> print(id(2))
140707510579488
>>> print(id(3))
140707510579520
......
```
> + python中存在内置[array](https://docs.python.org/3/library/array.html)存储了从-5到256的整数，当整数值大于256时，新分配内存地址给这个整数。
> + 600和700均大于256，所以为600分配内存地址并将变量a指向该地址，删除a后，同时删除600的内存地址，给700分配内存地址，并使b指向该地址，所以id(a)==id(b)可为Ture.　　
## 6:
```python
>>> i = 1
>>> i = i + 1       # 自增
>>> i = i - 1       # 自减
```
## 7:
```python
>>> a = [1,2]
>>> b = [1,2]
>>> a == b
True
>>> a is b
False
>>> print(id(a))
2222463865416
>>> print(id(b))
2222463865928
```
 == 和 is 都是python标准操作符中的比较操作符，官方文档中 == 的 meaning 是 equal，而 is 的 meaning 是 object identity。== 比较对象的值(value),is 比较对象的地址(id)。a 与 b 的 value 相等而id不相等。
## 8:
```python
>>> str1 = "Let's go"
>>> print(str1)
Let's go
```
## 9:
> + 第一种  
```python
>>> str2 = 'techf5ve'
>>> str2[6:8]
've'
```
> + 第二种
```python
>>> str2 = 'techf5ve'
>>> str2[-2:]
've'
```