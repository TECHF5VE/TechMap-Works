package com.yl;
import java.util.ArrayList;
public class  BookList {
    private String id;
    private String name;
    private String borrow;
    public BookList(String id, String name, String borrow) {
        super();
        this.id = id;
        this.name = name;
        this.borrow = borrow;
    }
    public BookList() {
    }
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public String getBorrow() {
        return borrow;
    }
    public void setBorrow(String borrow) {
        this.borrow = borrow;
    }
    public void main(String[] args) {
        ArrayList bookArray;
        bookArray = new ArrayList();

    }
}









