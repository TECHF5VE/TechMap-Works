package dao;

import bean.User;
import util.DBUtil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class UserDAOImp implements UserDAO {
    @Override
    public User findUser(User user) throws Exception {
        Connection connection=null;
        PreparedStatement statement=null;
        ResultSet resultSet=null;
        connection=DBUtil.get_connection();
        System.out.println("开始找");
        statement=connection.prepareStatement("SELECT * FROM login_user WHERE name=? AND password=? ");
        //statement=connection.prepareStatement("SELECT * FROM login_user WHERE name LIKE 'admi%';");
        statement.setString(1,user.getName());
        statement.setString(2,user.getPassword());
        resultSet=statement.executeQuery();
        User user_new=null;
        if(resultSet.next())
        {
            user_new=new User();
            System.out.println(resultSet.getString("name"));
            System.out.println(resultSet.getString("password"));
            user_new.setName(resultSet.getString("name"));
            user_new.setPassport(resultSet.getString("password"));
            //user_new.setId(resultSet.getInt("id"));
        }
        return user_new;
    }

    @Override
    public void addUser(User user) throws Exception {

    }
}
