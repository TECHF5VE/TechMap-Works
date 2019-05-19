package Library;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Management {
    public boolean checkbook2(List<Book> books, int id) // 检查是否重复输入id
    {
        for (int n = 0; n < books.size(); n++) {
            Book b = books.get(n);
            if (id == b.getID()) {
                System.out.println("该id已经被使用过");
                return true;
            }
        }
        return false;
    }

    public void checkbook(List<Book> books, User admin) // 查 按ID查找图书
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

    public void addbook(User admin, List<Book> books) {
        Book a = new Book();
        a.newbook();
        while (this.checkbook2(books, a.getID())) {
            a.newbook();
        }
        this.addbook(a, books, admin);
    }

    public void addbook(Book a, List<Book> books, User admin) // 增 上架图书
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

    public void delete(List<Book> books, User admin) // 删 按ID删除
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

    public void changebook(List<Book> books, User admin) {
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
    }

    public void start() {
        Management system = new Management();
        User admin = new User(123456, "admin");
        List<Book> books = new ArrayList<>();
        while (true) {
            admin.login();
            while (admin.Check()) {
                System.out.println("进入图书馆里系统，1.上架新书 2.删除图书 3.修改图书信息 4.查找图书 5.登出");
                Scanner sc = new Scanner(System.in);
                int choice = sc.nextInt();
                if (choice == 1) {
                    system.addbook(admin, books);
                }
                if (choice == 4) {
                    system.checkbook(books, admin);
                }
                if (choice == 2) {
                    system.delete(books, admin);
                }
                if (choice == 3) {
                    system.changebook(books, admin);
                }
                if (choice == 5) {
                    return;
                }
            }
        }
    }
}


