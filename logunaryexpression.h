#include "unaryexpression.h"

// LogUnaryExpression is a natural logarithm of inner expresssion

class LogUnaryExpression: public UnaryExpression {
    public:
        LogUnaryExpression (Expression *inner) : UnaryExpression(inner) {}
        double evaluate() {
            return log(inner->evaluate());
        }
};
