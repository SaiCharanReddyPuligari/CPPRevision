#include "patron.hpp"

// Patron(string _name, string _id);
// void checkOutBook(Book *b);
// void returnBook(Book *b);
// string getName();
// string getId();

Patron:: Patron(string _n, string _id){
    name=_n;
    id=_id;
}

void Patron:: checkOutBook(Book *b){//passing pointer because the vector checkout store Book pointer
    if(!b->isAvailable()){
       cout<<"Book is already checked out"<<endl;
    }
    else{
        b->checkOut(); 
        checkOut.push_back(b); 
    }
}

void Patron:: returnBook(Book *b){

    for(int i=0;i<checkOut.size(); i++){
        
        if(checkOut[i]->getISBN()==b->getISBN()){
            checkOut.erase(checkOut.begin()+ i);
            cout<<"Book has been returned by Patron: "<<name<<endl;
            return;
        }
    }
    cout<<"Did not checkout this book"<<endl;
}

string Patron:: getName(){
    return name;
}

string Patron:: getId(){
    return id;
}