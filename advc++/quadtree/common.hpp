#pragma once
#include <iostream>
#include "set"
#include "unordered_map"

#define NO_OF_CABS 3
static int nextqiadid=1;

//enums declaration and values

// enum Color { RED, GREEN, BLUE };  // Default: RED = 0, GREEN = 1, BLUE = 2

// enum class Status { SUCCESS, FAILURE };  // Scoped enum (C++11+)
// Color c = GREEN;  
// Status s = Status::SUCCESS;  
enum class QUAD_STATUS{
    EMPTY_LEAF,
    PARTIALLY_FILLED_LEAF,
    FILLED_LEAF,
    DIVIDED_NODE
};

enum class SUB_QUAD{
    NOT_ASSIGNED,
    NORTH_WEST,
    NORTH_EAST,
    SOUTH_WEST,
    SOUTH_EAST
};