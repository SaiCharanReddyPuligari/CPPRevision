#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <chrono>
#include "payment.hpp"

class Vehicle {
  protected:
    Payment* payment;
    std::chrono::time_point<std::chrono::system_clock> parkedTime;

  public:
    virtual std::string getType() = 0;
    virtual double calculateCost(double hours);
    
    void setParkedTime();
    std::chrono::time_point<std::chrono::system_clock> getParkedTime();
    
    virtual ~Vehicle();
};

class Car : public Vehicle {
  public:
    Car();
    std::string getType() override;
};

class Bike : public Vehicle {
  public:
    Bike();
    std::string getType() override;
};


#endif // VEHICLE_HPP
