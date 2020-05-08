package com.dgb.controller;

import com.dgb.util.SessionConstant;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.servlet.http.HttpSession;

@Controller
public class CancellationController {
    /**
     * 注销用户
     * @param session
     * @param attributes
     * @return
     */
    @RequestMapping("/cancellation")
    public String cancellation(HttpSession session, RedirectAttributes attributes){
        session.removeAttribute(SessionConstant.USER_SESSION);
        attributes.addFlashAttribute("msg","注销成功");
        return "redirect:/";
    }
}
