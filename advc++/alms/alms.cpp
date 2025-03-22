#include "alms.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

AirlineManagementSystem::AirlineManagementSystem():bookingIdCounter(1){}

AirlineManagementSystem::~AirlineManagementSystem(){
    for (auto flight : flights) delete flight;
    for (auto passenger : passengers) delete passenger;
    for (auto booking : bookings) delete booking;
}

void AirlineManagementSystem::addFlight(Flight* flight){
    flights.push_back(flight);
}

void AirlineManagementSystem::addPassenger(Passenger* passenger) {
    passengers.push_back(passenger);
}

std::string AirlineManagementSystem::createBooking(Flight* flight, Passenger* passenger, int seatNumber){
    if(!flight->bookSeat(seatNumber)){
        return "";
    }

    std::string bookingId = "B"+std::to_string(bookingIdCounter++);
    Booking* booking = new Booking(bookingId, flight, passenger, seatNumber);
    bookings.push_back(booking);
    return bookingId;
}

bool AirlineManagementSystem::cancelBooking(std::string bookingId){
    Booking* booking = findBooking(bookingId);
    if(!booking) return false;

    booking->getFlight()->cancelSeat(booking->getSeatNumber());

    auto it = std::find(bookings.begin(), bookings.end(), booking);

    if (it != bookings.end()) {
        bookings.erase(it);
        delete booking;
        return true;
    }
    return false;
}

void AirlineManagementSystem::displayAllFlights() {
    std::cout << "\nAll Flights:" << std::endl;
    for (const auto& flight : flights) {
        flight->displayFlightInfo();
        std::cout << "------------------------" << std::endl;
    }
}

void AirlineManagementSystem::displayAllPassengers() {
    std::cout << "\nAll Passengers:" << std::endl;
    for (const auto& passenger : passengers) {
        passenger->displayPassengerInfo();
        std::cout << "------------------------" << std::endl;
    }
}

void AirlineManagementSystem::displayAllBookings()  {
    std::cout << "\nAll Bookings:" << std::endl;
    for (const auto& booking : bookings) {
        booking->displayBookingInfo();
        std::cout << "------------------------" << std::endl;
    }
}


Flight* AirlineManagementSystem::findFlight(std::string flightNumber)  {
    for (auto flight : flights) {
        if (flight->getFlightNumber() == flightNumber) return flight;
    }
    return nullptr;
}

Passenger* AirlineManagementSystem::findPassenger(std::string passportNumber)  {
    for (auto passenger : passengers) {
        if (passenger->getPassportN() == passportNumber) return passenger;
    }
    return nullptr;
}

Booking* AirlineManagementSystem::findBooking(std::string bookingId)  {
    for (auto booking : bookings) {
        if (booking->getBookingId() == bookingId) return booking;
    }
    return nullptr;
} 