#pragma once
#include "driver.hpp"
#include "rider.hpp"

class TripMetaData{
     Location* srcloc;
     Location* dstloc;
     RATING riderRating;
     RATING driverRating;

     public:
     TripMetaData(Location* psrcloc,Location* pdstloc, RATING priderRating)
     :srcloc(psrcloc), dstloc(pdstloc), riderRating(priderRating){
        driverRating = RATING::UNASSIGNED;
     }

     RATING getRiderRating(){
        return riderRating;
     }

     RATING getDriverRating(){
        return driverRating;
     }

     void setDriverRating(RATING pDriverRating){
        driverRating = pDriverRating;
     }
};