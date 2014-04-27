#include "binaryexpression.h"

class DifferenceBinaryExpression: public BinaryExpression {
    public:
        DifferenceBinaryExpression (Expression *left, Expression *right) : BinaryExpression(left, right)  {}
        double evaluate () {
            return left->evaluate() - right->evaluate();
        }
};
