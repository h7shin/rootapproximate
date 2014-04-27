#include "unaryexpression.h"

// IdentityUnaryExpression is a wrapped Expresssion

class IdentityUnaryExpression: public UnaryExpression {
    public:
        IdentityUnaryExpression (Expression *inner) : UnaryExpression(inner) {}
        double evaluate() {
            return inner->evaluate();
        }
};
