package com.xizhe.demo.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.xizhe.demo.entity.Student;
import com.xizhe.demo.mapper.StudentMapper;
import com.xizhe.demo.service.StudentService;
import org.springframework.stereotype.Service;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:53
 */

@Service
public class StudentServiceImpl extends ServiceImpl<StudentMapper, Student> implements StudentService {
}
