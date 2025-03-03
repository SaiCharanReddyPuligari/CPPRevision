#include "parkinglot.hpp"
#include <iostream>

int main() {
    ParkingLot lot(3, 10);
    Car car1, car2;
    Bike bike1, bike2;

    car1.setParkedTime();
    lot.park(&car1, 0, 0);
    car2.setParkedTime();
    lot.park(&car2, 0,  1);
    bike1.setParkedTime();
    lot.park(&bike1, 0,  2);;

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;

    lot.leave(&car1);
    lot.leave(&bike2);

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;

    return 0;
}
