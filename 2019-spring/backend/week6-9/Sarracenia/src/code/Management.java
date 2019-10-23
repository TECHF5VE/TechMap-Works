package code;
import  code.Myarrylist;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Management {
    /*
    public boolean checkbook2(Myarrylist<Book> books, int id) // 检查是否重复输入id
    {
        int id2=0;
        for (int n = 0; n < books.size(); n++) {
            Book b = books.get(n);
            b.getID();
            System.out.println("asddwasd"+id);
            if (id == id2) System.out.println("abc");
            if(books.get(n)==null)
                return false;
            if (id == b.getID()) {
                System.out.println("该id已经被使用过");
                return true;
            }
        }
        return false;
    }

    public void checkbook(Myarrylist<Book> books, User admin) // 查 按ID查找图书
    {
        if (admin.Check()) {
            System.out.println("请输入ID");
            Scanner sc = new Scanner(System.in);
            int id = sc.nextInt();
            Book a = new Book();
            a.setID(id);
            for (int n = 0; n < books.size(); n++) {
                Book b = books.get(n);
                if (a.getID() == b.getID()) {
                    System.out.println("查找成功");
                    System.out.println("书名" + b.getname());
                    if (b.check())
                        System.out.println("被借走了");
                    else
                        System.out.println("未被借走");
                    return;
                }
                // System.out.println("查找失败");
            }
            System.out.println("查找失败");
        } else {
            System.out.println("请登录后获取权限");
        }
    }

    public void addbook(User admin, Myarrylist<Book> books) {
        Book a = new Book();
        a.newbook();
        while (this.checkbook2(books, a.getID())) {
            a.newbook();
        }
        this.addbook(a, books, admin);
    }

    public void addbook(Book a, Myarrylist<Book> books, User admin) // 增 上架图书
    {
        if (admin.Check()) {
            if (a.getstate_initialize()) {
                books.add(a);
                System.out.println("添加上架新书成功！");
            } else
                System.out.println("该书尚未设置好 无法上架");
        } else {
            System.out.println("请登录后获取权限");
        }
    }

    public void delete(Myarrylist<Book> books, User admin) // 删 按ID删除
    {
        if (admin.Check()) {
            System.out.println("请输入ID");
            Scanner sc = new Scanner(System.in);
            int id = sc.nextInt();
            Book a = new Book();
            a.setID(id);
            for (int n = 0; n < books.size(); n++) {
                Book b = books.get(n);
                if (a.getID() == b.getID()) {
                    books.remove(b);
                    System.out.println("删除成功");
                    return;
                }
            }
            System.out.println("无此书 删除失败");
        } else {
            System.out.println("请登录后获取权限");
        }
    }

    public void changebook(Myarrylist<Book> books, User admin) {
        if (admin.Check()) {
            System.out.println("请输入ID");
            Scanner sc = new Scanner(System.in);
            int id = sc.nextInt();
            Book a = new Book();
            a.setID(id);
            for (int n = 0; n < books.size(); n++) {
                Book b = books.get(n);
                if (a.getID() == b.getID()) {
                    books.remove(b);
                    System.out.println("请输入书名");
                    Scanner bc = new Scanner(System.in);
                    String name = bc.nextLine();
                    b.setname(name);
                    books.add(b);
                    System.out.println("修改成功");
                    return;
                }

            }
            System.out.println("无此书 修改失败");
        } else {
            System.out.println("请登录后获取权限");
        }
    }*/
    public void start() {
        Administrator admin = new Administrator(123456, "admin");//用户注册+admin和reader判别登录
        Reader reader;
        Myarrylist<Reader> userlist = new Myarrylist<Reader>(Reader.class);
        Management system = new Management();
        Myarrylist<Book> books = new Myarrylist(Book.class);
        while (true) {
            if (userlist.size() > 0) {
                System.out.println("您是要以什么身份登录：1.管理员 2.读者");
                Scanner scanner_choice2 = new Scanner(System.in);
                int choice2=scanner_choice2.nextInt();
                if(choice2==1)
                {
                    admin.login();
                    admin_operate(admin, books, userlist);
                }
                else if(choice2==2)
                {
                    //读者操作+登录
                    reader=new Reader().login(userlist);
                    while(reader==null)
                    {
                        System.out.println("读者身份登录失败 重新登录");
                        reader=new Reader().login(userlist);
                    }
                    reader_operate(reader,books,userlist);

                }
            }
            if (userlist.size() == 0) {
                System.out.println("请使用管理员身份登录，添加读者用户后进行各种管理操作");
                admin.login();
                admin_operate(admin, books, userlist);
            }
            if  (quit_system())  {
                return;
            }
            }
        }


    public void admin_operate(Administrator admin, Myarrylist<Book> books,Myarrylist<Reader> userlist) {
        while (admin.Check()) {
            System.out.println("进入图书管理员系统，1.上架新书 2.删除图书 3.修改图书信息 4.查找图书 5.注册用户 6.删除用户 7.修改用户密码 8.返回上一级系统");
            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            if (choice == 1) {
                admin.addbook(books);
            }
            if (choice == 2) {
                admin.delete(books);
            }
            if (choice == 3) {
                admin.changebook(books);
            }
            if (choice == 4) {
                admin.checkbook(books);
            }
            if (choice == 5) {
                //reader用户注册
                admin.newReader(userlist);
            }
            if (choice == 6) {
                //先确保用户list不为空
                if(userlist.size()==0)
                    System.out.println("没有Reader用户无法进行删除操作");
                else admin.deleteReader(userlist);
            }
            if (choice == 7) {
                //先确保用户list不为空
                //修改用户密码
                if(userlist.size()==0)
                    System.out.println("没有Reader用户无法进行删除操作");
                else
                    admin.changeReader(userlist);
            }
            if (choice == 8) {
                admin.logout();
                return;
            }
        }
    }
    public void reader_operate(Reader reader, Myarrylist<Book> books,Myarrylist<Reader> userlist)
    {
        while (reader.Check()) {
            System.out.println("进入读者系统 1.查找图书 2.借书 3.还书  4.返回上一级系统");
            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            if (choice == 1) {
                reader.checkbook(books);
            }
            if (choice == 2) {
                reader.borrowbook(books);
            }
            if (choice == 3) {
                reader.returnbook(books);
            }
            if (choice==4)
            {
                reader.logout();
                return;
            }
        }
    }



        public boolean quit_system()//确定要退出返回true 不退出返回false
    {
        System.out.println("是否退出系统  是则输入1，否输入0");
        Scanner scanner_choice=new Scanner(System.in);
        int choice=scanner_choice.nextInt();
        if(choice==1)
            return true;
        else
            return false;
    }


}

/*while (reader.Check()) {
                System.out.println("进入图书管理员系统，1.借书 2.还书 3.退出");
                Scanner sc = new Scanner(System.in);
                int choice = sc.nextInt();
                if (choice == 1) {
                    admin.addbook(books);
                }
                if (choice == 4) {
                    admin.checkbook(books);
                }
                if (choice == 2) {
                    admin.delete(books);
                }
                if (choice == 3) {
                    admin.changebook(books);
                }
                if (choice == 6) {
                    return;
                }
}*/