package com.dgb.service;

import com.dgb.pojo.Book;

import java.util.Collection;
import java.util.Map;

public interface BookService {
    Collection<Book> getAllBooks();
    Collection<Book> getBooksByUser(Integer id);
    void deleteBook (Map<String,Integer> idMapper);
    int insertBook (Map<String,Integer> idMapper);
}
