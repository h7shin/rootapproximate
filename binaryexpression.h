#ifndef _BINARYEXPRESSION_H_
#define _BINARYEXPRESSION_H_

#include "expression.h"

/**
Binary Expression is a subclass of Expression
that contains two subexpressions of type Expression
**/

class BinaryExpression : public Expression {
    protected:
        Expression *left;
        Expression *right;
    public:
        virtual double evaluate() = 0;
        BinaryExpression (Expression *left, Expression *right) : Expression(), left(left), right(right) {}
        ~BinaryExpression() {
            delete left;
            delete right;
        }
};

#endif // _BINARUEXPRESSION_H_
