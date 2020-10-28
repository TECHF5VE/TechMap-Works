package code;

import java.util.Scanner;
public class Administrator extends User {
    Administrator(int passport, String name)
    {
        super(passport, name);
    }
    public boolean checkbook2(Myarrylist<Book> books, int id) // 检查是否重复输入id
    {
        for (int n = 0; n < books.size(); n++) {
            Book b = books.get(n);
            if(books.get(n)==null) //books未初始化
                return false;
            if (id == b.getID()) {
                System.out.println("该id已经被使用过");
                return true;
            }
        }
        return false;
    }
    public void addbook(Myarrylist<Book> books) {
        Book a = new Book();
        a.newbook();
        while (this.checkbook2(books, a.getID())) {
            a.newbook();
        }
        this.addbook(a, books);
    }

    public void addbook(Book a, Myarrylist<Book> books) // 增 上架图书
    {
        if (Check()) {
            if (a.getstate_initialize()) {
                books.add(a);
                System.out.println("添加上架新书成功！");
            } else
                System.out.println("该书尚未设置好 无法上架");
        } else {
            System.out.println("请登录后获取权限");
        }
    }

    public void delete(Myarrylist<Book> books) // 删 按ID删除
    {
        if (Check()) {
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

    public void changebook(Myarrylist<Book> books) { //修改书名
        if (Check()) {
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
    }

    public void newReader(Myarrylist<Reader> userlist)
    {
        Scanner sc =new Scanner(System.in);
        System.out.println("创建新用户");//TODO:加入不可以输入重复用户名
        System.out.println("请输入用户名");
        String name=sc.nextLine();
        System.out.println("请输入密码");
        Integer x=sc.nextInt();
        userlist.add(new Reader(x,name));
        System.out.println("添加成功");
    }
    public void deleteReader(Myarrylist<Reader> userlist)
    {
        Scanner sc =new Scanner((System.in));
        System.out.println("删除用户");
        System.out.println("请输入用户名");
        String name=sc.nextLine();
        for(int n = 0; n < userlist.size(); n++)
        {
            if(userlist.get(n).getUser_name().equals(name))
            {
                userlist.remove(userlist.get(n));
                System.out.println("删除成功");
                return;
            }
        }
        System.out.println("用户不存在 删除失败");
    }
    public void changeReader(Myarrylist<Reader> userlist)//修改用户密码
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入用户名");
        String name=sc.nextLine();
        for(int n = 0; n < userlist.size(); n++)
        {
            if(userlist.get(n).getUser_name().equals(name))
            {
                Reader reader_change=userlist.get(n);
                System.out.println("请输入新密码：");
                Integer x=sc.nextInt();
                reader_change.setUser_passport(x);
                return;
            }
        }
        System.out.println("该用户不存在");
    }

}
