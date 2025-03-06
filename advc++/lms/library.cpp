#include "library.hpp"


// void addBooks(string ISBN);
// void removeBooks(string ISBN);
// Book* searchBook(string ISBN);
// void displayBooks();

void Library::addBooks(Book *b){
    books.push_back(b);
    cout<<"Book: "<<b->getTitle()<<"added to the libraray"<<endl;
}

void Library:: removeBooks(string ISBN){
    for(int i=0;i<books.size();i++){
        if(books[i]->getISBN()==ISBN){
            books.erase(books.begin()+i);
            cout<<"Book erased"<<endl;
        }
    }
}

Book* Library:: searchBook(string ISBN){
    for(int i=0;i<books.size();i++){
        if(books[i]->getISBN()==ISBN){
            return books[i];
        }
    }

    return nullptr;
}

void Library::displayBooks(){
    cout << "Books in the library: " << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << "Title: " << books[i]->getTitle() << endl;
        cout << "Author: " << books[i]->getAuthor() << endl;
        cout << "ISBN: " << books[i]->getISBN() << endl;
        cout << "Availability: " << (books[i]->isAvailable() ? "Available" : "Checked out") << endl;
        cout << endl;
    }
}