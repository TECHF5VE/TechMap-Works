package com.xizhe.demo.controller;

import com.xizhe.demo.dto.Result;
import com.xizhe.demo.service.GradeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author admin
 * @version 1.0
 * @description: TODO
 * @date 2023/2/20 12:56
 */

@RestController
@RequestMapping("/class")
public class GradeController {

    @Autowired
    private GradeService gradeService;

    @GetMapping("/queryStudent")
    public Result queryExistByName(Integer id,String name) {
        return gradeService.queryExistByName(id,name);
    }

    @GetMapping("/sumPeople/{id}")
    public Result sum(@PathVariable Integer id) {
        return gradeService.sum(id);
    }

    @GetMapping("/sumSex/{id}")
    public Result sumSex(@PathVariable Integer id) {
        return gradeService.sumSex(id);
    }

    @GetMapping("/sumLastName/{id}")
    public Result sumLastName(@PathVariable Integer id) {
        return gradeService.sumLastName(id);
    }



}
