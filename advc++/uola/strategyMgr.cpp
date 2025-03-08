#include "strategymgr.hpp"
#include "pricingStrategy.hpp"
#include "driverMatchingStrategy.hpp"
#include "ratingBasedPricingStrategy.hpp"
#include "leastTimeBasedMatchingStrategy.hpp"


StrategyMgr* StrategyMgr::strategyMgrInstance=nullptr;
mutex StrategyMgr::mtx;

StrategyMgr* StrategyMgr::getStrategyMgr(){
    if(strategyMgrInstance == nullptr){
        mtx.lock();//lock is expensive, so we put a lock only if the instance is null
        if(strategyMgrInstance==nullptr){
            strategyMgrInstance=new StrategyMgr();
        }
        mtx.unlock();
    }
    return strategyMgrInstance;
}

PricingStrategy* StrategyMgr:: determinePricingStrategy(TripMetaData* metaData){
    cout<<"Based on location and other factors"<<endl;
    return new RatingBasedPricingStrategy();
}
DriverMatchingStrategy* StrategyMgr:: determineMatchingStrategy(TripMetaData* metaData){
    cout<<"Based on least time and other factors"<<endl;
    return new LeastTimeBasedMatchingStrategy();
}