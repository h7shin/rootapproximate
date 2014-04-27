#include "unaryexpression.h"

// NegativeCommonUnaryExpression is a negative of an inner expression

class NegativeUnaryExpression: public UnaryExpression {
    public:
        NegativeUnaryExpression (Expression *inner) : UnaryExpression(inner) {}
        double evaluate() {
            return -(inner->evaluate());
        }
};
