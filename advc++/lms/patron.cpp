#include "patron.hpp"

Patron:: Patron(string _n, string _id){
    name=_n;
    id=_id;
}

void Patron:: checkOutBook(Book *b){
    if(!b->isAvailable()){
       cout<<"Book is already checked out"<<endl;
    }
    else{
        b->checkOut(); 
        checkOut.push_back(b);
    }
}