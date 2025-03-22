#ifndef BOOKING_HPP
#define BOOKING_HPP

#include "flight.hpp"
#include "passenger.hpp"
#include <string>


class Booking{
    private:
        std::string bookingId;
        Flight* flight;
        Passenger* passenger;
        int seatNumber;

    public:
        Booking(std::string bookingId, Flight* flight, Passenger* passenger, int seatNumber);

        std::string getBookingId();
        Flight* getFlight();
        Passenger* getPassenger();
        int getSeatNumber();
        void displayBookingInfo();
        
};
#endif