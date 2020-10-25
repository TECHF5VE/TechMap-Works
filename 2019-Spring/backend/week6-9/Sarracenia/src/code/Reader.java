package code;
import java.util.Scanner;
public class Reader extends User {
    public Reader(int passport, String name)
    {
        super(passport, name);
    }
    public Reader(){}
    public Reader login(Myarrylist<Reader> userlist)
    {
        if(userlist.size()>0)
        System.out.println("请输入用户名");
        Scanner sc =new Scanner(System.in);
        String name_login=sc.nextLine();
        Reader reader_check=null;
        for(int n = 0; n < userlist.size(); n++)
        {
            if(userlist.get(n).getUser_name().equals(name_login))
            {
                reader_check=userlist.get(n);
            }
        }
        if(reader_check==null) {
            System.out.println("error:该用户不存在");
            return null;
        }
        System.out.println("请输入密码");
        Scanner sc2 =new Scanner(System.in);
        int passport=sc.nextInt();
        if (reader_check.login(passport))
        return reader_check;
        else return null;
    }
    public void returnbook(Myarrylist<Book> books)
    {
        if (Check()) {
            int x=0;
            System.out.println("已借图书：");
            for (int n = 0; n < books.size(); n++) {
                Book b = books.get(n);
                if(b.getReader()!=null)
                if (b.getReader().equals(this)) {
                    System.out.println("ID:" + b.getID() + "  书名" + b.getname());
                    x++;
                }
            }
            if(x==0)
            {
                System.out.print("无");
                System.out.println("您没有借书");
                return;
            }
            else
            {
                System.out.println("您已借"+x+"本图书");
            }
            System.out.println("请输入所还书的ID");
            Scanner sc = new Scanner(System.in);
            int id = sc.nextInt();
            Book a = new Book();
            a.setID(id);
            for (int n = 0; n < books.size(); n++) {
                Book b = books.get(n);
                if (a.getID() == b.getID()) {
                    System.out.println("查找成功");
                    System.out.println("书名" + b.getname());
                        if (b.check()) {
                            if(b.getReader().equals(this))
                            {b.returnbook(this);
                            System.out.println("还书成功");}
                            else System.out.println("您并未借此书");
                    }
                    else {
                        System.out.println("此书未被借走 还书失败");

                    }
                    return;
                }
            }
            System.out.println("查找失败");
        } else {
            System.out.println("请登录后获取权限");
        }
    }
    public void borrowbook(Myarrylist<Book> books)
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
                    System.out.println("查找成功");
                    System.out.println("书名" + b.getname());
                    if (b.check())
                        System.out.println("书此前已被借走 借书失败");
                    else {
                        System.out.println("书未被借走");
                        if(b!=null)
                        b.borrowbook(this);
                        System.out.println("借书成功");
                    }
                    return;
                }
            }
            System.out.println("查找失败");
        } else {
            System.out.println("请登录后获取权限");
        }

    }
}
