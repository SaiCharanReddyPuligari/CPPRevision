#pragma once
#include "common.hpp"
#include "location.hpp"



class Quad{
    Location* center;
    double halfWidth;
    double halfHeight;
    QUAD_STATUS status;
   // Cab* cab;
    Location* cabsLocation;
    Quad* nwchild;
    Quad* nechild;
    Quad* swchild;
    Quad* sechild;
    Quad* parent;
    int quadid;

    public:
    Quad(Location* pCenter, double pHalfWidth, double pHalfHeight, Quad* pParent):
    center(pCenter), halfWidth(pHalfWidth), halfHeight(pHalfHeight), parent(pParent){
        quadid = nextqiadid;
        nextqiadid++;
        status = QUAD_STATUS::EMPTY_LEAF;
        nwchild = nullptr;
        nechild = nullptr;
        swchild = nullptr;
        sechild = nullptr;
        //cab = nullptr;
        cabsLocation = nullptr;
    }

};