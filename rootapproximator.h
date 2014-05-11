#ifndef _ROOTAPPROXIMATOR_H_
#define _ROOTAPPROXIMATOR_H_

#include "function.h"
#include <string>

/**
RootApproximator is a wrapper object of string y
a mathematical expression, and determines
a value of x such that value of the string y is closest
to 0 through getRoot() method
**/

class RootApproximator {

        std::string y;

    public:

        RootApproximator() : y("") {};
        RootApproximator(std::string y) : y(y) {};
        std::vector <double> getRoot (double startx, double finalx, int resolution);
};

#endif // _ROOTAPPROXIMATOR_H_
