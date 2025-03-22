#ifndef AIRLINE_MANAGEMENT_SYSTEM_HPP
#define AIRLINE_MANAGEMENT_SYSTEM_HPP

#include <vector>
#include <string>

#include "flight.hpp"
#include "passenger.hpp"
#include "booking.hpp"

class AirlineManagementSystem{
    private:
        std::vector<Flight*> flights;
        std::vector<Passenger*> passengers;
        std::vector<Booking*> bookings;
        int bookingIdCounter;

    public:
        AirlineManagementSystem();
        ~AirlineManagementSystem();

        void addFlight(Flight* flight);
        void addPassenger(Passenger* passenger);
        std::string createBooking(Flight* flight, Passenger* passenger, int seatNumber);
        bool cancelBooking(std::string bookingId);

        void displayAllFlights() ;
        void displayAllPassengers() ;
        void displayAllBookings() ;
        
        Flight* findFlight(std::string flightNumber) ;
        Passenger* findPassenger(std::string passportNumber) ;
        Booking* findBooking(std::string bookingId) ;
};
#endif