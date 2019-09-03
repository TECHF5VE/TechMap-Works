package service;

import bean.User;
import dao.UserDAOImp;

public class UserServiceImp implements UserService {
    UserDAOImp userDAO=new UserDAOImp();
    @Override
    public User findUser(User user) throws Exception {
        return userDAO.findUser(user);
    }
}
