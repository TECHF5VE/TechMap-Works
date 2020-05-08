package com.dgb.pojo;

public class Book {

    private Integer id;
    private String book_name;
    private String description;

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", book_name='" + book_name + '\'' +
                ", description='" + description + '\'' +
                '}';
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getBook_name() {
        return book_name;
    }

    public void setBook_name(String book_name) {
        this.book_name = book_name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Book(Integer id, String book_name, String description) {
        this.id = id;
        this.book_name = book_name;
        this.description = description;
    }

    public Book() {
    }
}
