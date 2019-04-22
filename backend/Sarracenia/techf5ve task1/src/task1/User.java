package task1;

public class User {
	private String user_name;
	//private int user_id;
	private boolean logstate;
	private int passport;
	public User(int passport,String name) {   //创建用户
		this.setUser_name(name);
		this.passport=passport;
		this.logstate=false;
	}
	public void setUser_name(String user_name) {  //设置用户名
		this.user_name = user_name;
	}	
	public boolean Check()              //检查登录装填
	{
		return logstate;
	}
	
	public boolean login(int passport)   //登录功能
	{
		if(!this.Check())
		{
			if(this.passport==passport)
				{
				this.logstate=true;
				System.out.println("登陆成功");
				return this.logstate;
				}
			else {
				System.out.println("输入错误");
				return this.logstate;
			}
			
		}
		else {
			System.out.println("请勿重复登录");
			return false;
		}
	}
	public String getUser_name() {
		return user_name;
	}
	

}
