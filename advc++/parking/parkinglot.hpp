#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include <vector>
#include "vehicle.hpp"
using namespace std;

class ParkingLot {
  private:
    vector<vector<Vehicle*>> spots;
    int floors;
    int rows;

  public:
    ParkingLot(int floors, int rows);

    bool park(Vehicle* v, int floor, int row);
    bool leave(Vehicle* v);
    int availableSpots(int floor);
    int handicappedSpots(int floor);
    double calculateHoursParked(Vehicle* v);
};

#endif // PARKINGLOT_HPP
