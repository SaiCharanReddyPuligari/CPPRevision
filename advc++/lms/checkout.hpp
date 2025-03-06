#pragma once//header guard to avoid duplications in includes
#include <map>
#include <ctime>

#include "book.hpp"
#include "patron.hpp"
using namespace std;
class CheckOut{
    // 
    map<Book*, pair<Patron*, time_t>> checkouts;
    const int DAY_SECONDS = 60*60*24;
    const int MAX_FINE = 10;

    public:
    void checkOut(Book* b, Patron* p);
    void returnBook(Book* b);
    void displayCheckOuts();
    time_t getDueDate(Book* book);
    double calculateFine(Book * book);

};

