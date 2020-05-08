package com.dgb.service;

import com.dgb.pojo.User;


public interface UserService {
    User getUserByName(String username,String password);
    boolean insert(String username,String password,String email);
}
