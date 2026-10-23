#pragma once
#include <iostream>

struct position {
    int x;
    int y;
    int z;
};

class Vec3 {
public:
    Vec3 (int x, int y, int z) {
        pos.x = x;
        pos.y = y;
        pos.z = z; 
    }

    // setters
    void setVals(position newPos) {
        pos = newPos;
    }   

    // getters
    position getPos() {
        return pos;
    }

private:
    position pos;
};