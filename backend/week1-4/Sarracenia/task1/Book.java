package task1;

import java.util.Scanner;

public class Book {
	private String name;
	private int ID;
	private boolean state;    //�Ƿ�����״̬
	private boolean state_initialize;    //�Ƿ��ʼ��
	public Book()
	{	
	}
	public Book(String name,int ID)
	{
		this.name=name;
		this.ID=ID;
		state=false;		
		state_initialize=true;
	}
	public void newbook()
	{
		System.out.println("������ID");
		Scanner sc = new Scanner(System.in); 
        int id = sc.nextInt();
		System.out.println("����������");
        Scanner bc = new Scanner(System.in);
        String name=bc.nextLine();
        this.setID(id);
		this.setname(name);
		state=false;		
		state_initialize=true;
	}
	public void setID(int ID)				//����ID
	{
		this.ID=ID;
	}
	public int getID()          //��ȡID
	{
		return ID;
	}
	public boolean changeID(int ID)  //�޸�ID
	{
		this.ID=ID;
		return true;
	}
	public void   setname(String name) //��������
	{
		this.name=name;
	}
	public boolean getstate_initialize() //�����Ƿ��ʼ��
	{
		return this.state_initialize;
	}
	public void setstate_inirialize(boolean a)    //���ó�ʼ��ֵ
	{
		this.state_initialize=a;
	}
	public String getname()     //��ȡ����
	{
		return name;
	}
	public boolean check()      //��ȡ�Ƿ񱻽���
	{
		return state;
	}
	public boolean borrowbook() //����
	{
		if(state)
			{
			 System.out.println("�Ѿ����");
			 return false;
			}
		else state=true;
		return true;
	}
	public boolean returnbook()  //����
	{
		if(!state)
		{
		 System.out.println("�Ѿ�����");
		 return false;
		}
	else state=false;
	return true;
	}
}