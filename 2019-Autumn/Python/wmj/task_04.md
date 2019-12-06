1、将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
```
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode newHead = new ListNode(-1);

        ListNode tmpHead = newHead;

        while(l1 != null &&l2 != null){

            if(l1.val >= l2.val){

                tmpHead.next = l2;

                tmpHead = tmpHead.next;

                l2 = l2.next;

            }else{

                tmpHead.next = l1;

                tmpHead = tmpHead.next;

                l1 = l1.next;

            }

        }

        if(l1 != null){

            tmpHead.next = l1;

        }

        if(l2 != null){

            tmpHead.next = l2;

        }

        return newHead.next;

    }
```
2、编写一个学生类, 要求有一个计数器的功能, 统计总共实例化了多少个学生.  
```
class Student:
    count = 0

    def init(self, name, sex, age):
        self.name = name
        self.sex = sex
        self.age = age
        Student.count += 1

    def learn(self):
        print("%s is learning" % self.name)


stu1 = Student('james', 'male', 32)
print(stu1.count)
print(stu1.dict)
stu2 = Student('enbede', 'male', 23)
print(stu2.count)
print(stu2.dict)
print(Student.count)
print(Student.dict)
```
3、解释 staticmethod（静态方法）和 classmethod（类方法）并举例
classmethod(类方法)  
1.定义时使用classmethod装饰器装饰的方法  
2.使用时通过类名调用  
作用：  
1.可以创建对象或者简洁的创建对象  
2.对外提供简单易用的接口  
```
  class Person:
      def eat(self):
          print("我爱你")
      @classmethod
      def test(cls):
          print(cls)
          print('这是类方法')

      # 创建对象，或者简洁的创建对象
      @classmethod
      def create(cls):
          p = cls()
          p.age = 3
          return p

  p1 = Person()
  p1.eat()

  # 通过类名调用
  Person.test()
  # 创建或简洁的创建对象
  p2 = Person.create()
  print(type(p2))  

```
staticmethod（静态方法）  
使用staticmethod装饰器装饰的方法(方法没有cls参数)  
通过类名进行调用  
```
class Person:
    @staticmethod
    def test():
        print('static method test')
    # 创建对象
    @staticmethod
    def create():
        p = Person()
        return p
    
Person.test()
p = Person.create()
print(p)   
```
4、定义点（point）类,包含点的坐标x和y；通过继承点类派生出线段（line)类；通过线段（line）类的组合定义三角形（triangle）类 ，计算三角形的面积
```
#include<iostream>
#include<Cmath>
using namespace std;
class Triangle
{
public:
inline void setA(double x);
inline void setB(double y);
inline void setC(double z);
inline double getA();
inline double getB();
inline double getC();
double perimeter(void);
double area(void);
bool isTriangle();
private:
double a,b,c;
};
inline void Triangle::setA(double x)
{
a=x;
}
inline void Triangle::setB(double y)
{
b=y;
}
inline void Triangle::setC(double z)
{
c=z;
}
inline double Triangle::getA()
{
return a;
}
inline double Triangle::getB()
{
return b;
}
inline double Triangle::getC()
{
return c;
}
double Triangle::area(void)
{
double p;
p=(a+b+c)/2;
return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::perimeter(void)
{
return a+b+c;
}
bool Triangle::isTriangle()
{
return (((a+b)>c&&a-b<c)||((a+c)>b&&(a-c)<b)||((b+c)>a&&(b-c)<a));
}
int main()
{
Triangle tril;
double x,y,z;
cout<<"请输入三角形的三边:";
cin>>x>>y>>z;
tril.setA(x);
tril.setB(y);
tril.setC(z);
if(tril.isTriangle())
{
cout<<"三条边为:"<<tril.getA()<<','<<tril.getB()<<','<<tril.getC()<<endl;
cout<<"三角形的周长为:"<<tril.perimeter()<<'\t'<<"面积为:"<<tril.area()<<endl;
}
else
cout<<"不能构成三角形"<<endl;
return 0;
}
```
5.（补） 用链表来表示两个非负的整数。它们是按照逆序的方式存储的，每个节点只能存储 一位数字。将这两个数相加起来，返回一个新的链表来表示它们的和。
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         if(l1==null){//因为l1是基准链表，要是l1到尾部了，l2就算还有，直接返回l2的剩余部分
            return l2;
        }
        if(l2==null){//这里l2到尾部了，l1需要进行判断，尾部是否大于10，要去进位。
        //比如l1:9,9 .l2:9 一次运算过后l2到尾部,l1变为8,10,这时候依然当做l2有个0去进位
            if(l1.val>=10){
                l2 = new ListNode(0);
                l2.next = null;
            }else{
                 return l1;
            }
           
        }
        
        int temp = l1.val+l2.val;
        l1.val = temp%10;
        if(temp>=10){  //说明l1应该进位
            if(l1.next==null){//要是l1没有下一位，则new一个节点进行连接
                l1.next = new ListNode(1); 
            }else{
                l1.next.val++; //l1有下一个节点，直接下一个节点的值加一
            }
        }       
        
        l1.next = addTwoNumbers(l1.next,l2.next);//用于重新连接携带新的值的每个l1节点
        
        return l1;
    }
}
```
Made by wmj  
12.01    
Through BiliBili