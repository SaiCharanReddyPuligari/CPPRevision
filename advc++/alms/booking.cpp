#include "booking.hpp"
#include <iostream>

Booking::Booking(std::string bookingId, Flight* flight, Passenger* passenger, int seatNumber)
    : bookingId(bookingId), flight(flight), passenger(passenger), seatNumber(seatNumber) {}

std::string Booking::getBookingId()  { return bookingId; }
Flight* Booking::getFlight()  { return flight; }
Passenger* Booking::getPassenger()  { return passenger; }
int Booking::getSeatNumber()  { return seatNumber; }
    
void Booking::displayBookingInfo()  {
    std::cout << "\nBooking Details:" << std::endl;
    std::cout << "Booking ID: " << bookingId << std::endl;
    std::cout << "Seat Number: " << seatNumber << std::endl;
    passenger->displayPassengerInfo();
    flight->displayFlightInfo();
} 
