#pragma once
#include "tripMetaData.hpp"
#include "mutex"
#include "common.hpp"
// #include

class StrategyMgr{
    StrategyMgr(){}
    static StrategyMgr* strategyMgrInstance;
    static mutex mtx;

    public:
    static StrategyMgr* getStrategyMgr();
    PricingStrategy* determinePricingStrategy(TripMetaData* metaData);
    DriverMatchingStrategy* determineMatchingStrategy(TripMetaData* metaData);

};