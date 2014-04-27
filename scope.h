#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <string>
#include "expression.h"
#include "binaryexpression.h"
#include "sumbinaryexpression.h"
#include "differencebinaryexpression.h"
#include "productbinaryexpression.h"
#include "divisionbinaryexpression.h"
#include "powerbinaryexpression.h"
#include "unaryexpression.h"
#include "numericunaryexpression.h"
#include "negativeunaryexpression.h"
#include "logunaryexpression.h"
#include "logcommonunaryexpression.h"
#include "identityunaryexpression.h"
#include <stdlib.h>     /* atof */
#include <iostream>

using namespace std;

// removeOuterParen(string s) removes outer parenthesis of string s
// unless string s has no left parenthesis or has no right parenthesis
string removeOuterParen(string s);

/**
 Class Scope contains a mathematical expression
 a string of numbers, parenthesis, mathematical
 operators and variable x. It can generate an Expression tree
 by calling generateExpression which recursively builds an expression
 tree of number of branches per node is either one or two
**/

class Scope {
    string s;
    public:
        void changeScope(string s) {
            this->s = s;
        }
        string getStr() {
            return s;
        }
        Scope(string s) : s(s) {}

        // Generate expression object from the string s
        Expression *generateExpression();
};
#endif // _SCOPE_H_
