package method;
import com.yl.BookList;
public class FindId
{
    final int SIZE = 10000000;
    BookList[] booklist = new BookList[SIZE];
    int count = 0;
    public  FindId(int number) {
    }
    int findId(int number)
    //按序号查找，返回id
    {
        if (number <= count) {
            int id = number - 1;
            return id;
        } else
            return -1;

    }
}
