package method;
import com.yl.BookList;
public class FindName {
    final int SIZE = 10000000;
    BookList[] booklist = new BookList[SIZE];
    int count = 0;
    int findName(String name)//按书名查找，返回id
    {
        int id = -1;
        for (int i = 0; i < count; i++) {
            if (booklist[i].getName().equals(name)) {
                id = i;
                break;
            } else if (i < count)
                continue;
            else {
                System.out.println("未查找到您想要的书名");
                break;
            }
        }
        return id;
    }
}

