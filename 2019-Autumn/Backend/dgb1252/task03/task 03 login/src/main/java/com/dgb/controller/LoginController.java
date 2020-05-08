package com.dgb.controller;

import com.dgb.pojo.User;
import com.dgb.service.UserService;
import com.dgb.util.SessionConstant;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.servlet.http.HttpSession;


@Controller
@RequestMapping("/user")
public class LoginController {
    @Autowired
    private UserService service;

    /**
     * 用户登录
     * @param username
     * @param password
     * @param attributes
     * @param session
     * @return
     */
    @PostMapping("/login")
    public String login(@RequestParam String username, @RequestParam String password, RedirectAttributes attributes, HttpSession session){
        User userByName = service.getUserByName(username, password);
        if (userByName==null){
            attributes.addFlashAttribute("msg","错误,请重新登录");
            return "redirect:/";
        }else {
            session.setAttribute(SessionConstant.USER_SESSION,userByName);
            return "redirect:/main";
        }
    }
}
