#include "checkout.hpp"
#include "book.hpp"
#include "patron.hpp"
#include <bits/stdc++.h>

// void checkOut(Book* b, Patron* p);
// void returnBook(Book* b);
// void displayCheckOuts();
// time_t getDueDate(Book* book);
// double calculateFine(Book * book);

void CheckOut::checkOut(Book *b, Patron* p){
    if(b->isAvailable()){
        p->checkOutBook(b);

        time_t dueDate = time(0) + 60*60*24*7; //7 days from the current time

        checkouts[b]= {p, dueDate};
    }
    else{
        cout<<"Book not available"<<endl;
    }
}

void CheckOut:: returnBook(Book *b){

    if(checkouts.find(b)!=checkouts.end()){
        Patron* p = checkouts[b].first;

        p->returnBook(b);
        checkouts.erase(b);
    }
}

void CheckOut:: displayCheckOuts(){
    for(auto x:checkouts){

        cout<<"Book: "<<x.first->getTitle()<<" Author: "<<x.first->getAuthor()<<endl;

        cout<<"Patron: "<<x.second.first->getName()<<"Due Date: "<<ctime(&x.second.second)<<endl;
    }
}

time_t CheckOut:: getDueDate(Book* b){
    if(checkouts.count(b)==1){
        return checkouts[b].second;
    }
    else{
        cout<<"Book is not yet checked out"<<endl;
        return -1;
    }
}

double CheckOut:: calculateFine(Book *b){
    time_t dueDate = this->getDueDate(b);

    time_t currenDate = time(0);

    double secondsLate = difftime(currenDate, dueDate);

    if(secondsLate < 0){
        //book already returned before 7 days
        return 0.0;
    }
    else{
        //calclating fine
        int daysLate = secondsLate /DAY_SECONDS;

        double fine=daysLate*0.50;

        return min(fine, (double)MAX_FINE);
    }
}

