#include "library.hpp"
#include "patron.hpp"
#include "checkout.hpp"


int main(){
    Library library;

    Book* b1= new Book("Good", "sai", "123");
    Book* b2= new Book("Bad", "char", "456");

    Patron patron1("John Smith", "123");
    Patron patron2("Jane Doe", "456");
    CheckOut checkout;

    library.addBooks(b1);
    library.addBooks(b2);
    library.displayBooks();

    checkout.checkOut(b1, &patron1);

    time_t dueDate = checkout.getDueDate(b1);

    if(dueDate!=-1){
        cout<<"Due Date: "<<ctime(&dueDate)<<endl;
    }

    double fine = checkout.calculateFine(b1);
    if(fine>0){
        cout<<"Fine: "<<fine<<endl;
    }
        // display all current checkouts
        checkout.displayCheckOuts();
        library.displayBooks();

        // return a book
        checkout.returnBook(b1);
    
        // display all current checkouts
        checkout.displayCheckOuts();
    return 0;

}