#include "payment.hpp"

double CarPayment::calculateCost(double hours) {
    return hours * 2;
}

double BikePayment::calculateCost(double hours) {
    return hours * 1;
}
