#include "book.hpp"

Book :: Book(string t, string a, string i){
    title = t;
    author = a;
    ISBN = i;
    available = true;
}

void Book:: checkOut(){
    if(available){
        available = false;
        cout<<"Book is checkout"<<endl;
    }
    else{
        cout<<"Book is not available";
    }
}

string Book :: getTitle(){
    return title;
}
string Book :: getAuthor(){
    return author;
}
string Book :: getISBN(){
    return ISBN;
}

bool Book:: isAvailable(){
    return available;
}