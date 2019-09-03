package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBUtil {
    private static final String DATABASE_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/task03?useUnicode=true&characterEncoding=UTF-8&userSSL=false&serverTimezone=GMT%2B8"; // 见上面的解释
    private static final String DATABASE_USER = "root"; // 用户名
    private static final String DATABASE_PASSWORD = "123456"; // 密码
    public static Connection get_connection()throws Exception {
        Connection conn=null;
        try {
            Class.forName(DATABASE_DRIVER);
            conn = DriverManager.getConnection(DATABASE_URL,DATABASE_USER,DATABASE_PASSWORD);//使用的是mysql8.0 url得注意加上编码时区等等东西，被坑了两天因为这个跟5.5版本不一样连不上数据库难受
            //System.out.println(conn);
            //conn.close();
        }
        catch (SQLException ex)
        {
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
            System.out.println("连接失败");


        }
        return conn;

    }


}
