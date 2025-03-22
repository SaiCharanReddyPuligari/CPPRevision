#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>

class Passenger{
    private:
        std::string name;
        std::string passportN;
        std::string contactN;
    public:

        Passenger(std::string name, std::string passportN, std::string contactN);
        std::string getName();
        std::string getPassportN();
        std::string getContactN();
        void displayPassengerInfo();
};

#endif