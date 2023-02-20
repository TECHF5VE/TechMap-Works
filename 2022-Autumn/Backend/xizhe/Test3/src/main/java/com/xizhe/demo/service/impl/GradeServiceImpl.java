package com.xizhe.demo.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.xizhe.demo.dto.Result;
import com.xizhe.demo.entity.Student;
import com.xizhe.demo.mapper.GradeMapper;
import com.xizhe.demo.service.GradeService;
import com.xizhe.demo.service.StudentService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.xizhe.demo.entity.Grade;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:54
 */
@Service
public class GradeServiceImpl extends ServiceImpl<GradeMapper,Grade> implements GradeService {

    @Autowired
    private StudentService studentService;

    @Override
    public Result queryExistByName(Integer id, String name) {
        Grade c = this.baseMapper.selectById(id);
        if (c == null) {
            return Result.fail("班级不存在");
        }
        if(StrUtil.isBlank(name)) {
            return Result.fail("学生姓名非法");
        }
        List<Student> list = studentService.query().eq("name", name).eq("class_id", id).list();
        return Result.ok(list);
    }

    @Override
    public Result sum(Integer id) {
        Grade c = this.baseMapper.selectById(id);
        if (c == null) {
            return Result.fail("班级不存在");
        }
        Integer count = studentService.query().eq("class_id", id).count();
        return Result.ok(count);
    }

    @Override
    public Result sumSex(Integer id) {
        Grade c = this.baseMapper.selectById(id);
        if (c == null) {
            return Result.fail("班级不存在");
        }
        Map<String,List<Student>> classMap = studentService.query().eq("class_id", id)
                .list().stream().collect(Collectors.groupingBy(Student::getSex));
        Map<String,Integer> map = new HashMap<>();
        map.put("男", Optional.ofNullable(classMap.get("男")).flatMap( l -> Optional.of(l.size())).orElse(0));
        map.put("女",Optional.ofNullable(classMap.get("女")).flatMap( l -> Optional.of(l.size())).orElse(0));
        return Result.ok(map);
    }

    @Override
    public Result sumLastName(Integer id) {
        Grade c = this.baseMapper.selectById(id);
        if (c == null) {
            return Result.fail("班级不存在");
        }
        Map<Object,List<Student>> classMap = studentService.query().eq("class_id", id)
                .list().stream().collect(Collectors.groupingBy(student -> student.getName().charAt(0)));
        Map<Character,Integer> map = new HashMap<>();
        for (Map.Entry<Object, List<Student>> entry : classMap.entrySet()) {
            Character key = (Character) entry.getKey();
            int size = entry.getValue().size();
            map.put(key,size);
        }
        return Result.ok(map);
    }


}
