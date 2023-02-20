package com.xizhe.demo.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.xizhe.demo.dto.Result;
import com.xizhe.demo.entity.Grade;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:52
 */
public interface GradeService extends IService<Grade> {
    /**
     * 查询班级里是否有某一个学生
     * @param id 班级id
     * @param name 学生姓名
     * @return
     */
    Result queryExistByName(Integer id, String name);


    /**
     * 统计班级人数
     * @param id 班级id
     * @return
     */
    Result sum(Integer id);

    /**
     * 统计性别人数以及比例
     * @param id 班级id
     * @return
     */
    Result sumSex(Integer id);

    /**
     * 统计姓氏与人数
     * @param id 班级id
     * @return
     */
    Result sumLastName(Integer id);
}
