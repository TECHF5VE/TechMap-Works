package Library;

import java.util.Scanner;

public class User {
    private String user_name;            //用户名
    private boolean logstate;            //登录状态
    private int passport;                //密码

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
                System.out.println("输入错误");
                return this.logstate;
            }
        } else {
            System.out.println("请勿重复登录");
            return false;
        }
    }
}
