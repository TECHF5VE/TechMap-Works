package com.company;
import java.util.Scanner;

public class Users {
    public static void main(String[] aargs) {
        String username = "admin";
        int password = 123456;
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入名字：");
        String str = scanner.next();
        System.out.print("请输入密码：");
        int pas = scanner.nextInt();
        if (str.equals(username) && pas == password) {
            System.out.println("登陆成功！");
            System.out.println("请输入操作选项：1.添加图书，2.删除图书，3.查找图书,4.修改图书。");
            BookList blist = new BookList();
            int t;
            Scanner sd = new Scanner(System.in);
            t = sd.nextInt();
            switch (t) {
                case 1:
                    blist.addbook();
                    break;
                case 2:
                    blist.delete();
                    break;
                case 3:
                    blist.find();
                    break;
                case 4:
                    blist.change();
            }
        } else {
            System.out.println("用户名或密码错误！");
        }
    }
}


