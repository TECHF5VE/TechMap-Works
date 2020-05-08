package com.dgb.config;

import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import static com.dgb.util.SessionConstant.USER_SESSION;

/**
 * 登录拦截器
 */
public class LoginHandlerInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        Object user = request.getSession().getAttribute(USER_SESSION);
        if (user == null) {
            request.setAttribute("msg", "请登录后重试");
            request.getRequestDispatcher("/").forward(request, response);
            return false;
        } else {
            return true;
        }
    }


}
