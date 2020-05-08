package com.dgb.controller;


import com.dgb.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

@Controller
public class RegisterController {
    @Autowired
    private UserService service;

    /**
     * 用户注册
     * @param username
     * @param password
     * @param email
     * @param attributes
     * @return
     */
    @PostMapping("/user/register")
    public String register(@RequestParam String username, @RequestParam String password, @RequestParam String email, RedirectAttributes attributes){
        boolean flag = service.insert(username, password, email);
        if (flag){
            attributes.addFlashAttribute("msg","注册成功,请登录");
            return "redirect:/";
        }else {
            attributes.addFlashAttribute("msg","用户名已存在,请重新注册");
            return "redirect:/register";
        }
    }
}
