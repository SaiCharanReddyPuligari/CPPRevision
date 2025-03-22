#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include <vector>
#include "seat.hpp"

class Flight{
    private:
        std::string flightNumber;
        std::string origin;
        std::string destination;
        std::string departureTime;
        int capacity;
        std::vector<Seat> seats;
    public:

        Flight(std::string flightNumber, std::string origin,std::string destination, std::string departureTime, int capacity);
        std::string getFlightNumber();
        std::string getOrigin();
        std::string getDestination();
        std::string getDepartureTime();
        int getCapacity();
        std::vector<Seat>& getSeats();

        void displayFlightInfo();
        bool bookSeat(int seatNumber);
        bool cancelSeat(int seatNumber);
        

};

#endif