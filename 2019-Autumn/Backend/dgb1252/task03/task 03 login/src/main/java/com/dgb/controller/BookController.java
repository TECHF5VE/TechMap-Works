package com.dgb.controller;

import com.dgb.pojo.Book;
import com.dgb.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.Collection;

@Controller
public class BookController {

    @Autowired
    public BookService service;

    /**
     * 显示所有书
     * @param model
     * @return
     */
    @RequestMapping("/Book")
    public String allBook(Model model) {
        Collection<Book> allBooks = service.getAllBooks();
        model.addAttribute("books", allBooks);
        return "book/list";
    }

    /**
     * description: 显示某用户喜欢的所有书
     * @param id
     * @param model
     * @return
     */
    @RequestMapping("/{id}/Book")
    public String addBook(@PathVariable Integer id,Model model){
        Collection<Book> booksByUser = service.getBooksByUser(id);
        model.addAttribute("books",booksByUser);
        return "book/userBooks";
    }

}
