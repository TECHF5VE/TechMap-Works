# 1.
```c++
ListNode* Merge(ListNode* Listhead1, ListNode* Listhead2)
{
	if (Listhead1 == NULL)
		return Listhead2;
	if (Listhead2 == NULL)
		return Listhead1;
	ListNode* head, * p1, * p2;
	if (Listhead1->data < Listhead2->data)
	{
		head = Listhead1;
		p1 = Listhead1->next;
		p2 = Listhead2;
	}
	else
	{
		head = Listhead2;
		p1 = Listhead1;
		p2 = Listhead2->next;
	}
	ListNode* mid = head;
	while (p1 && p2)
	{
		if (p1->data <= p2->data)
		{
			mid->next = p1;
			mid = p1;
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			mid->next = p2;
			mid = p2;
			p2 = p2->next;
		}
	}
	if (p1)
		mid->next = p1;
	if (p2)
		mid->next = p2; 
	return head;
}
```

# 2.

```c++
#include <iostream>
#include <string>
using namespace std;
class student {
public:
    static int count;
    student() { ++count; }
    student(string ID = "", string name = "", int age = 0) :
        m_ID(ID), m_name(name), m_age(age) {++count;}
    ~student() { --count; }
    void getData() {
        cout << m_ID << ' ' << m_name << ' ' << m_age << ' ';
    }
    void setData(string ID = "", string name = "", int age = 0) {
        if (ID != "") m_ID = ID;
        if (name != "") m_name = name;
        if (age != 0) m_age = age;
    }
    void showCount() {
        cout << "计数值：" << count << endl;
    }
private:
    string m_ID;
    string m_name;
    int m_age = 0;
};
```
```python
class student(object):
    count=0
    def __init__(self,name,age):
        self.name=name
        self.age=age
        student.count+=1
    def print(self):
        print(self.__name)
        print(self.__age)
    def getName(self):
        print(self.__name)
    def fetSex(self):
        print(self.__age)
    def setName(self,name):
        self.__name=name
    def setSex(self,age):
        self.__age=age
```

# 3.

#### 静态方法：

1. 静态方法与函数类似，和函数的唯一区别是静态方法定义在类命名空间中，函数定义在全局命名空间。
2. 静态方法不需要绑定类似cls，self这样的特殊参数，但此方法中无法调用任何类和对象的属性和方法。
3. 静态方法需要使用@staticmethod修饰。
4. 静态方法的调用，既可以使用类名，也可以使用对象名。

```python
class student(object):
    country = 'china'

    @staticmethod
    #静态方法
    def getCountry():
        return student.country

print student.getCountry()
```



#### 类方法：

1. 类对象具有的方法，需要用修饰器@classmethod来标识其为类方法。
2. 第一个参数必须是类对象，一般以cls作为第一个参数。
3. 能够通过实例对象和类对象访问。
4. 能够对类属性进行修改

```python
class student(object):
    country = 'china'

    #类方法，用classmethod来进行修饰
    @classmethod
    def getCountry(cls):
        return cls.country
    @classmethod
    def setCountry(cls,country)
    	cls.country=country

p = People()
print p.getCountry()    #可以用过实例对象引用
print People.getCountry()    #可以通过类对象引用

p.setCountry('Canada')	  #修改类属性
```

# 4.

```C++
#include<iostream>
using namespace std;
class Point
{
public:
	Point()
	{
		X = 0;
		Y = 0;
	}
	Point(double x, double y)
	{
		X = x;
		Y = y;
	}
private:
	double X, Y;
};
class Line:public Point
{
public:
	Line()
	{
		X1 = 0; X2 = 0; Y1 = 0; Y2 = 0;
	}
	Line(double x1, double y1, double x2, double y2) :Point(0, 0), P1(x1, y1), P2(x2, y2)
	{
		X1 = x1; Y1 = y1; X2 = x2; Y2 = y2;
	}
	double lineLen()
	{
		return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
	}
private:
	Point P1, P2;
	double X1, X2, Y1, Y2;
};
class Tringle:public Line
{
public:
	Tringle():L1(0,0,0,0),L2(0,0,0,0),L3(0,0,0,0)
	{
		X1 = 0; X2 = 0; X3 = 0; Y1 = 0; Y2 = 0; Y3 = 0;
	}
	Tringle(double x1, double x2, double x3, double y1, double y2, double y3):Line(0,0,0,0),L1(x1,y1,x2,y2),L2(x2,y2,x3,y3),L3(x1,y1,x3,y3)
	{
		X1 = x1; X2 = x2; X3 = x3;
		Y1 = y1; Y2 = y2; Y3 = y3;
	}
	double TriArea()
	{
		double a = L1.lineLen();
		double b = L2.lineLen();
		double c = L3.lineLen();
		double r = (a + b + c) / 2;
		return sqrt(r * (r - a) * (r - b) * (r - c));
	}
private:
	Line L1, L2, L3;
	Point P1, P2, P3;
	double X1, X2, X3, Y1, Y2, Y3;
};
int main()
{
	Tringle x = Tringle(1, 1, 2, 2, 1, 2);
	cout << x.TriArea();
	return 0;
}
```

