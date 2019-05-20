package function;
import com.yl.*;
import java.util.Scanner;
import method.*;
public class FindBook {
    public void find() {

        final int SIZE = 10000000;
        BookList[] booklist = new BookList[SIZE];
        int count = 0;
        Scanner scanen = new Scanner(System.in);
        while (true) {
            System.out.println("请输入按哪种方法查找图书：1、序号,2、书名。");
            int choosee = scanen.nextInt();
            if (choosee == 1) {
                System.out.println("请输入要查找第几本书：");
                int number = scanen.nextInt();
                int id = new FindId(number);

                if (id > -1) {
                    System.out.println("你要查找的书名为：" + booklist[id].getId() + booklist[id].getName() + "是否借出：" + booklist[id].getBorrow());
                } else {
                    System.out.println("输入错误！");
                }
            } else if (choosee == 2) {
                System.out.println("请输入您要查找的书名：");
                String name = scanen.next();
                int id = FindName(name);
                if (id > -1) {
                    System.out.println("查找成功，您查找到的书为第" + (id + 1) + "本书！" + "书名为：" + booklist[id].getId() + booklist[id].getName() + " 是否借出：" + booklist[id].getBorrow());
                }


            } else {
                System.out.println("输入错误！");
            }
        }

    }

}




