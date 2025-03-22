#include "seat.hpp"

Seat:: Seat(int number, bool isBooked):seatNumber(number), booked(isBooked){

}

int Seat::getSeatNumber(){
    return seatNumber;
}

bool Seat::isBooked(){
    return booked;
}

void Seat::book(){
    booked= true;
}

void Seat::cancel(){
    booked=false;
}