#include "binaryexpression.h"

// PowerBinaryExpression is a product of two expressions

class PowerBinaryExpression: public BinaryExpression {
    public:
        PowerBinaryExpression (Expression *left, Expression *right) : BinaryExpression(left, right) {}
        double evaluate() {
            return pow(left->evaluate(), right->evaluate());
        }
};

