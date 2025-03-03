#ifndef PAYMENT_HPP
#define PAYMENT_HPP

class Payment {
  public:
    virtual double calculateCost(double hours) = 0;
    virtual ~Payment() = default;
};

class CarPayment : public Payment {
  public:
    double calculateCost(double hours) override;
};

class BikePayment : public Payment {
  public:
    double calculateCost(double hours) override;
};


#endif // PAYMENT_HPP
