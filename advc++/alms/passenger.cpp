#include "passenger.hpp"
#include <string>
#include <iostream>

Passenger::Passenger(std::string name, std::string passportN, std::string contactN):name(name), passportN(passportN), contactN(contactN){

}

std::string Passenger::getName()  { return name; }
std::string Passenger::getPassportN()  { return passportN; }
std::string Passenger::getContactN()  { return contactN; }

void Passenger::displayPassengerInfo() {
    std::cout << "Passenger Details:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Passport Number: " << passportN << std::endl;
    std::cout << "Contact Number: " << contactN << std::endl;
} 