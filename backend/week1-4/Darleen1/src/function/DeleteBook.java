package function;
import java.lang.reflect.Method;
import java.util.Scanner;
import com.yl.BookList;
import method.*;
public class DeleteBook {
    public void delete() {
        final int SIZE = 10000000;
        BookList[] booklist = new BookList[SIZE];
        int count = 0;
        Scanner scan = new Scanner(System.in);
        while (true) {
            System.out.println("请输入按哪种方法删除图书：1、id，2、书名。");
            int choose = scan.nextInt();
            if (choose == 1) {
                System.out.println("请输入要删除第几本书：");
                int id = scan.nextInt();
                if (id > -1) {
                    for (int i = id; i < count - 1; i++)//用for循环的形式实现对数组的删除
                        booklist[i] = booklist[i + 1];
                    count--;
                    System.out.println("删除成功！");
                } else {
                    System.out.println("输入错误！");
                }
            } else {
                System.out.println("请输入您要删除的书名：");
                String name = scan.next();
                int id = FindName(name);
                if (id > -1) {
                    for (int j = id; j < count - 1; j++)//用for循环的形式实现对数组的删除
                    {
                        booklist[j] = booklist[j + 1];
                    }
                    count--;
                    System.out.println("删除成功！");
                } else {
                    System.out.println("未查找到您想要的书名");
                }
            }


        }
    }
//查找图书
}
