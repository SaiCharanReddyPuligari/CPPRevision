#ifndef BOOK_HPP
#define BOOK_HPP
//Header guards are used to avoid multiple declarations of the BOOK_HPP files 
// if mistankenly included in other files
//additionally, you can simply use #pragma once 
#include <bits/stdc++.h>
using namespace std;


class Book{
    string title;
    string author;
    string ISBN;
    bool available;

    public:
    Book(string t, string a, string i);
    void checkOut();
    string getTitle();
    string getAuthor();
    string getISBN();
    bool isAvailable();

};

#endif