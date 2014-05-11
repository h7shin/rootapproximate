#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "expression.h"
#include "scope.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <vector>

/**
Function is a class that contains a pointer to scope
**/

class Function {
    double increment;
    double minx;
    double maxx;
    Scope *scope;

    public:
        Function (std::string str) : scope(new Scope(str)), increment(1), minx(0), maxx(100) {}
        Function (std::string str,double increment) :  scope(new Scope(str)), increment(increment), minx(0), maxx(100) {}
        Function (std::string str,double increment, double minx, double maxx) : scope(new Scope(str)), increment(increment), minx(minx), maxx(maxx) {}

        // smallestXY() returns a vector of which first element
        // is the value of x (minx <= x <= maxx) to generate
        // y value closest to 0
       std::vector <double> smallestXY();
};
#endif // _FUNCTION_H_
