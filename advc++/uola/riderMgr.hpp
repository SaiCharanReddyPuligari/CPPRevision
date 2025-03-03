#include <bits/stdc++.h>
#include "rider.hpp"
using namespace std;

class RiderMgr{
    RiderMgr();
    static RiderMgr* riderMgrInstance;
    static mutex mtx;
    unordered_map<string, Rider*> ridersMap;
  public:
  static RiderMgr* getRiderMgr();
  void addRider(string PriderName, Rider* pRider);
  Rider* getRider(string PriderName);
};