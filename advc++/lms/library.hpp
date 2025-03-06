#ifndef LIBRARY_HPP
#define LIBRARAY_HPP
#include "book.hpp"
#include <vector>

class Library{
    vector<Book*> books;

    public:
    void addBooks(Book *b);
    void removeBooks(string ISBN);
    Book* searchBook(string ISBN);
    void displayBooks();
};

#endif