package dao;
import bean.User;
public interface UserDAO {
public void addUser(User user) throws Exception;
public User findUser(User user) throws Exception;
}
