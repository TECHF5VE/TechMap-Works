package task1;

public class User {
	private String user_name;
	private boolean logstate;
	private int passport;
	public User(int passport,String name) {   //�����û�
		this.setUser_name(name);
		this.passport=passport;
		this.logstate=false;
	}
	public void setUser_name(String user_name) {  //�����û���
		this.user_name = user_name;
	}	
	public boolean Check()              //����¼װ��
	{
		return logstate;
	}
	public boolean login(int passport)   //��¼����
	{
		if(!this.Check())
		{
			if(this.passport==passport)
				{
				this.logstate=true;
				System.out.println("��½�ɹ�");
				return this.logstate;
				}
			else {
				System.out.println("�������");
				return this.logstate;
			}		
		}
		else {
			System.out.println("�����ظ���¼");
			return false;
		}
	}
	public String getUser_name() {
		return user_name;
	}
}