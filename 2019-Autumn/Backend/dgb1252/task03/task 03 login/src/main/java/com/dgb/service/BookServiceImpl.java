package com.dgb.service;

import com.dgb.dao.BUMapper;
import com.dgb.dao.BookMapper;
import com.dgb.pojo.BUid;
import com.dgb.pojo.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Collection;
import java.util.Map;

@Service
public class BookServiceImpl implements BookService{
    @Autowired
    private BookMapper mapper;
    @Autowired
    private BUMapper buMapper;
    @Override
    public Collection<Book> getAllBooks() {
        return mapper.getAllBooks();
    }

    @Override
    public Collection<Book> getBooksByUser(Integer id) {
        return mapper.getBooksByUser(id);
    }

    @Override
    public void deleteBook(Map<String, Integer> idMapper) {
        mapper.deleteBook(idMapper);
    }

    /**
     * description: 判断是否有该书籍,1插入成功,0插入失败
     * @param map
     * @return
     */
    @Override
    public int insertBook(Map<String, Integer> map) {
        BUid query = buMapper.query(map);
        if (query==null)return mapper.insertBook(map);
        else return 0;
    }
}
