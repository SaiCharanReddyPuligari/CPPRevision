#pragma once
#include <bits/stdc++.h>
using namespace std;

class Product{
    string name;
    double price;
    int stock;

    public:
    Product(string name, double price, int stock);
    string getName();
    double getPrice();
    int getStock();

    void setName(string name);

};