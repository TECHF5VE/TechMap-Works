package servlet;

import bean.User;
import service.UserService;
import service.UserServiceImp;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String name = request.getParameter("name");
        String password = request.getParameter("password");
        System.out.println("name:" + name);
        System.out.println("password:" + password);
        User user=new User();
        user.setName(name);
        user.setPassport(password);
        UserService service=new UserServiceImp();
        try{
          User  user_new=service.findUser(user);
          if(user_new!=null){
                System.out.println("登录成功");
                //request.getRequestDispatcher("login_success.html");
              request.getRequestDispatcher("/login_success.html").forward(request, response);

              //登录成功跳转到登录成功界面
            }
          else{
              //登录失败跳转到登录失败界面
              System.out.println("登录失败");
              //request.getRequestDispatcher("login_fail.html");
              request.getRequestDispatcher("/login_fail.html").forward(request, response);
            }
            }
        catch (Exception e){
            e.printStackTrace();
        }


    }
}
