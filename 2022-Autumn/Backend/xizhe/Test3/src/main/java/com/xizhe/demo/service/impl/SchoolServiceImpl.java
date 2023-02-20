package com.xizhe.demo.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.xizhe.demo.entity.School;
import com.xizhe.demo.mapper.SchoolMapper;
import com.xizhe.demo.service.SchoolService;
import org.springframework.stereotype.Service;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:54
 */

@Service
public class SchoolServiceImpl extends ServiceImpl<SchoolMapper, School> implements SchoolService {
}
