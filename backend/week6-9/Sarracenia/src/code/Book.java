package code;
//完成图书的增删改查  不能重复添加相同id的书 ，修改图书名字，删除按图书id操作 查找按图书name/id操作。

import java.util.Scanner;
import code.*;

public class Book {
    private String name;
    private int ID;
    private boolean state;    //是否借出的状态
    private boolean state_initialize;    //是否初始化
    private Reader borrowreader;
    public Book() {
        state_initialize = false;
    }

    public Book(String name, int ID) {
        this.name = name;
        this.ID = ID;
        state = false;
        state_initialize = true;
        borrowreader=null;
    }

    public void newbook() {
        System.out.println("请输入ID");
        Scanner sc = new Scanner(System.in);
        int id = sc.nextInt();
        System.out.println("请输入书名");
        Scanner bc = new Scanner(System.in);
        String name = bc.nextLine();
        this.setID(id);
        this.setname(name);
        state = false;
        state_initialize = true;
        borrowreader=null;
    }

    public int getID()          //获取ID
    {
        return ID;
    }
    public Reader getReader()       //获取借书者
    {
        return borrowreader;
    }
    public void setID(int ID)                //设置ID
    {
        this.ID = ID;
    }

    public boolean changeID(int ID)  //修改ID
    {
        this.ID = ID;
        return true;
    }

    public void setname(String name) //设置书名
    {
        this.name = name;
    }

    public boolean getstate_initialize() //返回是否初始化
    {
        return this.state_initialize;
    }

    public void setstate_inirialize(boolean a)    //设置初始化值
    {
        this.state_initialize = a;
    }

    public String getname()     //获取书名
    {
        return name;
    }

    public boolean check()      //获取是否被借走
    {
        return state;
    }

    public boolean borrowbook(Reader reader) //借书
    {
        if (state) {
            System.out.println("已经借出");
            return false;
        }
        else {
            state = true;
            borrowreader=reader;
        }
        return true;
    }

    public boolean returnbook(Reader reader)  //还书
    {
        if (!state) {
            System.out.println("已经还毕");
            return false;
        } else state = false;
        borrowreader=null;
        return true;
    }
}
