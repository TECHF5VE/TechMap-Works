package function;
import com.yl.*;
import java.lang.reflect.Method;
import java.util.Scanner;
public class AddBook {
    public static void main(String[] args) {
//        try {
//            Method method = BookList.class.getDeclaredMethod("getId", new Class[]{});
//            method.setAccessible(true);
//            Method.invoke(new BookList(), new String[] {});
//        }
//        catch (Exception e) {
//        }
    }
        final int SIZE = 10000000;
        BookList[] booklist = new BookList[SIZE];
        int count = 0;
        public void addbook(){
            if (count < SIZE) {
                System.out.println("当前共有:" + count + "本书!");
                Scanner scan = new Scanner(System.in);
                System.out.println("请输入图书id：");
                String bookId = scan.next();
                System.out.println("请输入图书名：");
                String bookName = scan.next();
                System.out.println("请输入借出状态：");
                String bookBorrow = scan.next();
                BookList book = new BookList(getId(), getName(), getBorrow());
                booklist[count] = book;
                count++;
                System.out.println("添加成功！");
            } else {
                System.out.println("暂时不能添加！");
            }

        }
    }

