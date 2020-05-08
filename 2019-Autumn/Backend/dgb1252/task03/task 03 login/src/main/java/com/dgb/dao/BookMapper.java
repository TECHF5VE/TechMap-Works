package com.dgb.dao;

import com.dgb.pojo.Book;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.Map;
@Mapper
@Repository
public interface BookMapper {
    /**
     * description: 查询现有的所有书籍
     * @return Book集合
     */
    Collection<Book> getAllBooks();

    /**
     * description: 查询某用户的喜爱的书籍
     * @param id
     * @return Book集合
     */
    Collection<Book> getBooksByUser(Integer id);

    /**
     * description: 删除某用户喜爱的书籍
     * @param idMapper
     */
    void deleteBook (Map<String,Integer> idMapper);

    /**
     * description: 添加喜爱的书籍
     * @param map
     * @return 是否插入
     */
    int insertBook (Map<String,Integer> map);
}
