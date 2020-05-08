package com.dgb.controller;

import com.dgb.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.HashMap;
import java.util.Map;

@Controller
public class DeleteController {

    @Autowired
    private BookService service;

    /**
     * 删除某用户喜爱的书
     * @param bid
     * @param id
     * @return
     */
    @RequestMapping("/{id}/Book/{bid}")
    public String delete(@PathVariable Integer bid, @PathVariable Integer id){
        Map<String,Integer> map=new HashMap<>();
        map.put("uid",id);
        map.put("bid",bid);
        service.deleteBook(map);
        return "redirect:/"+id+"/Book";
    }
}
