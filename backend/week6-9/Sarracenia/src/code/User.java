package code;

import java.util.Scanner;

public class User {
    private String user_name;            //用户名
    private boolean logstate;            //登录状态
    private int passport;                //密码
    public User(){}
    public User(int passport, String name) {   //创建用户
        this.setUser_name(name);
        this.passport = passport;
        this.logstate = false;
    }
    public String getUser_name() {
        return user_name;
    }
    public void setUser_name(String user_name) {  //设置用户名
        this.user_name = user_name;
    }
    public void setUser_passport(Integer user_passport){this.passport=user_passport;}
    public boolean Check()              //检查登录状态
    {
        return logstate;
    }

    public void login() {
        System.out.println("请输入密码:");
        Scanner sc = new Scanner(System.in);
        int passport = sc.nextInt();
        this.login(passport);
    }

    public boolean login(int passport)   //登录功能
    {
        if (!this.Check()) {
            if (this.passport == passport) {
                this.logstate = true;
                System.out.println("登陆成功");
                return this.logstate;
            } else {
                System.out.println("密码输入错误");
                return this.logstate;
            }
        } else {
            System.out.println("请勿重复登录");
            return false;
        }
    }
    public void logout()        //退出账号
    {
        this.logstate=false;
    }

    public void checkbook(Myarrylist<Book> books) // 查 按ID查找图书
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
                    if (b.check()) {
                        System.out.println("被读者用户"+b.getReader().getUser_name()+"借走了");
                    }
                    else
                        System.out.println("未被借走");
                    return;
                }
            }
            System.out.println("查找失败");
        } else {
            System.out.println("请登录后获取权限");
        }
    }
}
