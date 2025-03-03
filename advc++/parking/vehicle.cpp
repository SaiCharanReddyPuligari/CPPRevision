#include "vehicle.hpp"

void Vehicle::setParkedTime() {
    parkedTime = std::chrono::system_clock::now();
}

std::chrono::time_point<std::chrono::system_clock> Vehicle::getParkedTime() {
    return parkedTime;
}

double Vehicle::calculateCost(double hours) {
    return payment->calculateCost(hours);
}

Vehicle::~Vehicle() {
    delete payment;  // Prevent memory leaks
}

Car::Car() {
    payment = new CarPayment();
}

std::string Car::getType() {
    return "Car";
}

Bike::Bike() {
    payment = new BikePayment();
}

std::string Bike::getType() {
    return "Bike";
}

