#include <iostream>
#include "Vec3.h"
#include "DHtable.h"

int main() {

    DHtable table(5);


    table.setTheta({20, 40, 70, 50, 30});

    table.setAlen({0,1,9,5,4});
    table.setDlen({1,2,8,4,6});
    table.setAlpha({30,60,100,0,20});

    table.printTable();
    table.setFinalMat();
    table.printFinalMat();

    return 0; 
}