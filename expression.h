#include <cmath>
#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_


/**
Expression is an object that is recursively generated from
mathematical expression that can be evaluated as a double
**/

class Expression {
    public:
        Expression () {}
        virtual double evaluate() = 0;
        virtual ~Expression() {};
};

#endif
