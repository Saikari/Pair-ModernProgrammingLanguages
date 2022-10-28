// GeometricProgression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GeomProgression.h"
int main()
{
    GeomProgression gp(10, 5.0);
    gp.printProgression();
    gp.printElem(5);
    gp.printSumProgIndex(5);
    gp.~GeomProgression();
}
