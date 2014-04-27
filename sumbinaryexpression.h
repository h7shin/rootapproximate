#include "binaryexpression.h"

// SumBinaryExpression is a sum of two expressions

class SumBinaryExpression: public BinaryExpression {
    public:
        SumBinaryExpression (Expression *left, Expression *right) : BinaryExpression(left, right) {}
        double evaluate () {
            return left->evaluate() + right->evaluate();
        }
};
