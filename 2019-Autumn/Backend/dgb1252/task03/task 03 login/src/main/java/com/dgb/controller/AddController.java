package com.dgb.controller;


import com.dgb.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.HashMap;
import java.util.Map;

@Controller
public class AddController {
    @Autowired
    private BookService service;

    /**
     * description: 用户添加喜爱的书
     * @param uid
     * @param bid
     * @param attributes
     * @return
     */
    @PostMapping("{uid}/Book/{bid}")
    public String addBook(@PathVariable Integer uid, @PathVariable Integer bid, RedirectAttributes attributes){
        Map<String,Integer> map=new HashMap<>();
        map.put("uid",uid);
        map.put("bid",bid);
        int i = service.insertBook(map);
        if (i>0){
            attributes.addFlashAttribute("msg","添加成功");
        }else {
            attributes.addFlashAttribute("msg","已添加该书,请添加其他书");
        }
        return "redirect:/Book";
    }
}
