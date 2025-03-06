#ifndef PATRON_HPP
#define PATRON_HPP

#include<vector>
#include <string>
#include "book.hpp"
using namespace std;

class Patron{
    string name;
    string id;
    vector<Book*> checkOut;

    public:
    Patron(string _name, string _id);
    void checkOutBook(Book *b);
    void returnBook(Book *b);
    string getName();
    string getId();
};

#endif