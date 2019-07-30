package code;
import java.lang.reflect.Array;
import java.util.*;
import java.lang.*;
public class Myarrylist<T>
        {
         //实现对数组的基本操作(增加，删除，修改等)，动态扩容的，即当增加到一定数量的时候，底层代码要自动实现对数组容量的扩容。
            private int maxsize; //实际数组长度
            private int size;    //目前使用数组长度-1
            private T[] data;
            Class<T> type;        //存下当前的类型
            Myarrylist(int initialsize,Class<T> type)//构造函数1 给定初始长度
            {
                if(initialsize>0)
                {
                    size=0;
                    maxsize=initialsize;
                    this.type=type;
                    data=(T[]) Array.newInstance(type, maxsize);
                }
                else
                    System.out.println("initialsize error ");
            }
            public Myarrylist(Class<T> type)//构造函数 默认初始长度为10
            {

                    size=0;
                    maxsize=10;
                    data=(T[]) Array.newInstance(type, maxsize);


            }
            private void array_copy(int pastsize,int aftersize)  //copy数组
            {
                T[] newarry =(T[]) Array.newInstance(type, aftersize);
                for(int i=0;i<pastsize;i++)
                {
                    newarry[i]=data[i];
                }
                data=newarry;
            }
            private void array_expansion()  //数组扩容 长度变为1.5倍
            {
                array_copy(maxsize,maxsize*2/3);
                maxsize=maxsize*2/3;
            }
            private boolean checkarray()  //检查数组是否满
            {
                return size+1==maxsize;
            }
            public boolean add(T x)        //增加至数组末尾
            {
                if(checkarray())
                    array_expansion();
                if(size>=0) {
                    data[size++] = x;
                    return true;
                }
                else return false;
            }
            public boolean remove(int x)    //删除数组第x个数
            {
                if(x>=0 && x<=size)
                {   for(int i=x;i<size;i++)
                    {
                        data[i]=data[i+1];
                    }
                    data[size]=null;
                    size--;
                    return true;
                }
                else return false;
            }
            public T get(int x)      //查找第n个
            {
                if(x>=0 && x<=size)
                return (T) data[x];
                else
                {
                    System.out.println("error");
                    return null;
                }
            }
            public boolean remove(T a)
            {
                int b=-1;
                for(int i=0;i<=size;i++)
                {
                    if(data[i]==a)
                      b=i;
                }
                if(b==-1)
                    return false;
                else {
                    for(int i=b;i<size;i++)
                {
                    data[i]=data[i+1];
                }
                    data[size]=null;
                    size--;
                    return true;}
            }
            public int size()
            {
                return size;
            }
            //public boolean change(T a,int x)


        }

