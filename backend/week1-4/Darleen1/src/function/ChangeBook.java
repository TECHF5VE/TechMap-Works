package function;
import com.yl.BookList;
import java.util.Scanner;
import method.*;
public class ChangeBook {
    final int SIZE = 10000000;
    BookList[] booklist = new BookList[SIZE];
    int count = 0;

    public void change() {
        Scanner fc = new Scanner(System.in);
        while (true) {
            System.out.println("请输入按哪种方法修改图书：1、id,2、书名.");
            int choose = fc.nextInt();
            if (choose == 1) {
                System.out.println("请输入要修改第几本书：");
                int number = fc.nextInt();
                FindId id = new FindId(number);
                if (id > -1) {
                    System.out.println("原书名为：" + booklist[id].getName() + " 请输入你要修改为什么书名：");
                    String str = fc.next();
                    System.out.println("请输入是否借出：");
                    String borroe = fc.next();
                    booklist[id].setName(str);
                    booklist[id].setBorrow(borroe);
                    System.out.println("修改成功！");
                } else {
                    System.out.println("输入错误！");
                }
            }


        }
    }
}
