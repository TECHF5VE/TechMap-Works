package com.dgb.dao;

import com.dgb.pojo.User;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;


@Mapper
@Repository
public interface UserMapper {
    /**
     * description: 根据username查询用户
     * @param username
     * @return 用户类
     */
    User getUserByName(String username);

    /**
     * description: 注册
     * @param username
     * @param password
     * @param email
     */
    void insert(String username,String password,String email);
}
