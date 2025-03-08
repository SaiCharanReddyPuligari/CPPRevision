#include <bits/stdc++.h>
#include "rider.hpp"
using namespace std;

class RiderMgr{
    RiderMgr(); //for singleton constructor should be private
    static RiderMgr* riderMgrInstance;
    static mutex mtx;
    unordered_map<string, Rider*> ridersMap;
  public:
  static RiderMgr* getRiderMgr();
  void addRider(string PriderName, Rider* pRider);
  Rider* getRider(string PriderName);
};