package com.company;
import java.util.ArrayList;
import java.util.Scanner;

class BookList {
    private String id;
    private String name;
    private String borrow;

    public BookList(String id, String name, String borrow) {
        super();
        this.id = id;
        this.name = name;
        this.borrow = borrow;
    }

    public BookList() {

    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String getBorrow() {
        return borrow;
    }

    public void setBorrow(String borrow) {
        this.borrow = borrow;
    }

    //    public String toString() {
//        return "Book:" + getId() + getName() + getBorrow();
//    }
//List<Integer> list=new ArrayList<Integer> ();
    public void main(String[] args) {
        ArrayList bookArray;
        bookArray = new ArrayList();

    }
//        ArrayList d;
//
//        {
//            d = new ArrayList();
//        }
//        BookList s1 = new BookList("g0682", "化学", "否");
//        BookList s2 = new BookList("p6487", "大物", "否");
//        BookList s3 = new BookList("j879l", "高数", "否");
//        bookArray.add(s1);
//        bookArray.add(s2);
//        bookArray.add(s3);
//

    final int SIZE = 10000000;
    BookList[] booklist = new BookList[SIZE];
    int count = 0;

    //添加图书
    public void addbook() {

        if (count < SIZE) {
            System.out.println("当前共有:" + count + "本书!");
            Scanner scan = new Scanner(System.in);
            System.out.println("请输入图书id：");
            String bookId = scan.next();
            System.out.println("请输入图书名：");
            String bookName = scan.next();
            System.out.println("请输入借出状态：");
            String bookBorrow = scan.next();
            BookList book = new BookList(getId(), getName(), getBorrow());
            booklist[count] = book;
            count++;
            System.out.println("添加成功！");
        } else {
            System.out.println("暂时不能添加！");
        }

    }


    //删除图书
    public void delete() {
        Scanner scan = new Scanner(System.in);
        while (true) {
            System.out.println("请输入按哪种方法删除图书：1、id，2、书名。");
            int choose = scan.nextInt();
            if (choose == 1) {
                System.out.println("请输入要删除第几本书：");
                int id = scan.nextInt();
                id = findId(id);
                if (id > -1) {
                    for (int i = id; i < count - 1; i++)//用for循环的形式实现对数组的删除
                        booklist[i] = booklist[i + 1];
                    count--;
                    System.out.println("删除成功！");
                } else {
                    System.out.println("输入错误！");
                }
            } else {
                System.out.println("请输入您要删除的书名：");
                String name = scan.next();
                int id = findName(name);
                if (id > -1) {
                    for (int j = id; j < count - 1; j++)//用for循环的形式实现对数组的删除
                    {
                        booklist[j] = booklist[j + 1];
                    }
                    count--;
                    System.out.println("删除成功！");
                } else {
                    System.out.println("未查找到您想要的书名");
                }
            }


    }
}
//查找图书
            public void find () {



                    Scanner scanen = new Scanner(System.in);
                    while(true)
                    {
                        System.out.println("请输入按哪种方法查找图书：1、序号,2、书名。");
                        int choosee= scanen.nextInt();
                        if(choosee == 1)
                        {
                            System.out.println("请输入要查找第几本书：");
                            int number = scanen.nextInt();
                            int id = findId(number);

                    if(id > -1)
                    {
                        System.out.println("你要查找的书名为："+booklist[id].getId()+booklist[id].getName()+"是否借出："+booklist[id].getBorrow());
                    }
                    else
                    {
                        System.out.println("输入错误！");
                    }
            }
            else if(choosee == 2)
            {
                System.out.println("请输入您要查找的书名：");
                String name = scanen.next();
                int id = findName(name);
                if(id > -1)
                {
                    System.out.println("查找成功，您查找到的书为第"+(id+1)+"本书！"+"书名为："+booklist[id].getId()+booklist[id].getName()+" 是否借出："+booklist[id].getBorrow());
                }


            }
                        else{
                            System.out.println("输入错误！");
                        }
        }

    }
//修改图书
            public void change () {
                Scanner fc = new Scanner(System.in);
                while(true)
                    {
                        System.out.println("请输入按哪种方法修改图书：1、id,2、书名.");
                        int choose = fc.nextInt();
                        if(choose == 1)
                        {
                            System.out.println("请输入要修改第几本书：");
                            int number = fc.nextInt();
                            int id = findId(number);
                            if(id > -1)
                            {
                                System.out.println("原书名为："+booklist[id].getName()+" 请输入你要修改为什么书名：");
                                String str = fc.next();
                                System.out.println("请输入是否借出：");
                                String borroe = fc.next();
                                booklist[id].setName(str);
                                booklist[id].setBorrow(borroe);
                                System.out.println("修改成功！");
                            }
                            else
                            {
                                System.out.println("输入错误！");
                            }
                        }



                }
            }

    int findId(int number)
    //按序号查找，返回id
    {
        if (number <= count) {
            int id = number - 1;
            return id;
        } else
            return -1;

    }
    int findName(String name)//按书名查找，返回id
    {
        int id = -1;
        for(int i = 0; i < count; i++)
        {
            if(booklist[i].getName().equals(name))
            {
                id = i;
                break;
            }
            else if(i<count)
                continue;
            else
            {
                System.out.println("未查找到您想要的书名");
                break;
            }
        }
        return id;
    }
}








