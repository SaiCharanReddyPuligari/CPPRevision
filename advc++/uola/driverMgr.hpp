#include <bits/stdc++.h>
#include "driver.hpp"
using namespace std;

class DriverMgr{
    DriverMgr(); //for singleton constructor should be private
    static DriverMgr* driverMgrInstance;
    static mutex mtx;
    unordered_map<string, Driver*> driversMap;
  public:
  static DriverMgr* getDriverMgr();
  void addDriver(string PriderName, Driver* pRider);
  Driver* getDriver(string PriderName);
  unordered_map<string, Driver*> getDriversMap();
};