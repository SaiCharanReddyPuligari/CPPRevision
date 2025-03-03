#include "parkinglot.hpp"
#include <iostream>

ParkingLot::ParkingLot(int floors, int rows) {
    this->floors = floors;
    this->rows = rows;
    spots.resize(floors);

    for (int i = 0; i < floors; i++) {
        spots[i].resize(rows);

    }
}

bool ParkingLot::park(Vehicle* v, int floor, int row) {
    if (spots[floor][row] == nullptr) {
        spots[floor][row] = v;
        std::cout << v->getType() << " parked successfully at floor " << floor << ", row " << row << std::endl;
        return true;
    } else {
        std::cout << "Spot already occupied." << std::endl;
        return false;
    }
}

bool ParkingLot::leave(Vehicle* v) {
    for (int i = 0; i < floors; i++) {
        for (int j = 0; j < rows; j++) {
            
                if (spots[i][j] == v) {
                    double hours = calculateHoursParked(spots[i][j]);
                    double cost = spots[i][j]->calculateCost(hours);
                    spots[i][j] = nullptr;
                    std::cout << v->getType() << " left successfully. Total cost: " << cost << std::endl;
                    return true;
                }
            
        }
    }
    std::cout << v->getType() << " not found." << std::endl;
    return false;
}

int ParkingLot::availableSpots(int floor) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
            if (spots[floor][i] == nullptr) {
                count++;
            }
    }
    return count;
}

double ParkingLot::calculateHoursParked(Vehicle* v) {
    auto now = std::chrono::system_clock::now();
    auto parkedTime = v->getParkedTime();
    auto duration = std::chrono::duration_cast<std::chrono::hours>(now - parkedTime);
    return duration.count();
}
