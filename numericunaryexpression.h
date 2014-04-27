#include "unaryexpression.h"

// NumericUnaryExpression is a number expression

class NumericUnaryExpression: public UnaryExpression {
        double value;
    public:
        NumericUnaryExpression (double value ) : value(value), UnaryExpression(0) {
        }
        double evaluate() {
            return value;
        }
};
