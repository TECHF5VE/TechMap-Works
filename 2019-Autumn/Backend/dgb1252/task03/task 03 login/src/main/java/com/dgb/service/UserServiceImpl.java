package com.dgb.service;

import com.dgb.dao.UserMapper;
import com.dgb.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService{

    @Autowired
    private UserMapper mapper;

    @Override
    public User getUserByName(String username,String password) {
        User userByName = mapper.getUserByName(username);
        if (userByName==null)return null;
        else if (!userByName.getPassword().equals(password))return null;
        else return userByName;
    }

    @Override
    public boolean insert(String username, String password, String email) {
        User userByName = mapper.getUserByName(username);
        if (userByName==null){
            mapper.insert(username, password, email);
            return true;
        }
        else return false;
    }


}
