package services;
import function.AddBook;
import function.ChangeBook;
import function.DeleteBook;
import function.FindBook;

import java.util.Scanner;

public class Users {
    public static void main(String[] args) {
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
            AddBook a = new AddBook();
            DeleteBook b=new DeleteBook();
            ChangeBook c=new ChangeBook();
            FindBook d=new FindBook();
            int t;
            Scanner sd = new Scanner(System.in);
            t = sd.nextInt();
            switch (t) {
                case 1:
                   a.addbook();
                    break;
                case 2:
                    b.delete();
                    break;
                case 3:
                    c.change();
                    break;
                case 4:
                    d.find();
            }
        } else {
            System.out.println("用户名或密码错误！");
        }
    }
}


