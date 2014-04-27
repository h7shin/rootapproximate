#ifndef _UNARYEXPRESSION_H_
#define _UNARYEXPRESSION_H_

#include <cmath>
#include "expression.h"
#include <iostream>
using namespace std;

/** Unary Expression is a subclass of Expression
that contains one subexpression of type Expression **/

class UnaryExpression: public Expression {
    protected:
        Expression *inner;
    public:
        virtual double evaluate() = 0;
        UnaryExpression (Expression *inner) : inner(inner) {}
        ~UnaryExpression() {
            delete inner;
        }
};




#endif
