#ifndef SEAT_HPP
#define SEAT_HPP

class Seat{
    private:
        int seatNumber;
        bool booked;
    public:
        Seat(int number, bool isBooked=false);

        int getSeatNumber();
        bool isBooked();
        void book();
        void cancel();
};
#endif