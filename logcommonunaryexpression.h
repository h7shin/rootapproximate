#include "unaryexpression.h"

// LogCommonUnaryExpression is a common log of inner expresssion

class LogCommonUnaryExpression: public UnaryExpression {
    public:
        LogCommonUnaryExpression (Expression *inner) : UnaryExpression(inner) {}
        double evaluate() {
            return log10(inner->evaluate());
        }
};
