#include "binaryexpression.h"

// ProductBinaryExpression is a product of two expressions

class ProductBinaryExpression: public BinaryExpression {
    public:
        ProductBinaryExpression (Expression *left, Expression *right) : BinaryExpression(left, right) {}
        double evaluate () {
            return left->evaluate() * right->evaluate();
        }
};

