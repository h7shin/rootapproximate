#ifndef _ROOTAPPROXIMATOR_H_
#define _ROOTAPPROXIMATOR_H_

#include "function.h"
#include <string>
using namespace std;

/**
RootApproximator is a wrapper object of string y
a mathematical expression, and determines
a value of x such that value of the string y is closest
to 0 through getRoot() method
**/

class RootApproximator {

        string y;

    public:

        RootApproximator() : y("") {};
        RootApproximator(string y) : y(y) {};
        double getRoot (double startx, double finalx, int resolution);
};

#endif // _ROOTAPPROXIMATOR_H_
