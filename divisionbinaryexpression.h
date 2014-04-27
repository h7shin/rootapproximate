#include "binaryexpression.h"

class DivisionBinaryExpression: public BinaryExpression {
    public:
        DivisionBinaryExpression (Expression *left, Expression *right) : BinaryExpression(left, right) {}
        double evaluate () {
            return left->evaluate() / right->evaluate();
        }
};
