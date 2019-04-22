package task1;
import task1.book;
import task1.User;

import java.util.*;

//实现功能：图书管理 实现图书的增删改查

//图书类里面有书名，ID，是否借出 三个成员变量。
//用户类里面有用户名 密码两个成员变量 默认用户名为admin 密码为123456

//要求用户可以通过用户名密码登陆图书管理系统 未登录或验证失败的时候不能进入管理系统

public class start {

    static int a=0;
    public void checkbook(List<book> books,User admin)    //查  按ID查找图书
    {
    	if(admin.Check())
		{
    		System.out.println("请输入ID");
    		Scanner sc = new Scanner(System.in); 
            int id = sc.nextInt();
        	book a=new book();
        	a.setID(id);
			for(int n=0;n<books.size();n++)
			{
				book b=books.get(n);
				if(a.getID()==b.getID())
				{
					System.out.println("查找成功");
					System.out.println("书名"+b.getname());
					if(b.check()) System.out.println("被借走了");
					else System.out.println("未被借走");
					return;
				}
				//System.out.println("查找失败");
			}
			System.out.println("查找失败");
		}
		else {
			System.out.println("请登录后获取权限");
		}
    }
	public void addbook(book a,List<book> books,User admin)       //增   上架图书
	{
		if(admin.Check())
		{
			if(a.getstate_initialize())
				{books.add(a);
				System.out.println("添加上架新书成功！");
				}
			else System.out.println("该书尚未设置好 无法上架");
		}
		else {
			System.out.println("请登录后获取权限");
		}
	}
	public void delete(List<book> books,User admin)       //删  按ID删除
	{
		if(admin.Check())
		{
    		System.out.println("请输入ID");
    		Scanner sc = new Scanner(System.in); 
            int id = sc.nextInt();
        	book a=new book();
        	a.setID(id);
			for(int n=0;n<books.size();n++)
			{
				book b=books.get(n);
				if(a.getID()==b.getID())
				{
					books.remove(b);
					System.out.println("删除成功");
					return;
				}

			}
			System.out.println("无此书 删除失败");
		}
		else {
			System.out.println("请登录后获取权限");
		}
	}
	public void changebook(List<book> books,User admin)       
	{
		if(admin.Check())
		{
    		System.out.println("请输入ID");
    		Scanner sc = new Scanner(System.in); 
            int id = sc.nextInt();
        	book a=new book();
        	a.setID(id);
			for(int n=0;n<books.size();n++)
			{
				book b=books.get(n);
				if(a.getID()==b.getID())
				{
					books.remove(b);
					System.out.println("请输入书名");
			        Scanner bc = new Scanner(System.in);
			        String name=bc.nextLine();
			        b.setname(name);
					books.add(b);
					System.out.println("修改成功");
					return;
				}

			}
			System.out.println("无此书 修改失败");
		}
		else {
			System.out.println("请登录后获取权限");
		}
	}
	public static void main(String[] args) {
		start system =new start();
		User admin = new User(123456,"admin");
		List<book> books = new ArrayList<>() ;
		while(true)
		{
			System.out.println("请输入密码:");
			Scanner sc = new Scanner(System.in); 
	         int passport = sc.nextInt();
	        admin.login(passport);
	        while(admin.Check())
	        {
	        	System.out.println("进入图书馆里系统，1.上架新书 2.删除图书 3.修改图书信息 4.查找图书 5.登出");
		         int choice = sc.nextInt();
		         if(choice==1)
		         {
		        	 book a=new book();
		        	 a.newbook();
		        	 system.addbook(a, books, admin);
		         }
		         if(choice==4)
		         {
		        	 system.checkbook(books, admin);
		         }
		         if(choice==2)
		         {
		        	 system.delete(books,admin);
		         }
		         if(choice==3)
		         {
		        	 system.changebook(books, admin);
		         }
		         if(choice==5)
		         {
		        	 return;
		         }
	        }
		}
	
	}

}
