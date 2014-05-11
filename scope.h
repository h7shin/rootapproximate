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

// removeOuterParen(string s) removes outer parenthesis of string s
// and returns a resulting substring (if the string do not have
// at least one of each left and right parenthesis, the same
// string is returned

std::string removeOuterParen(std::string s);

/**
 Class Scope contains a mathematical expression
 a string of numbers, parenthesis, mathematical
 operators and variable x. It can generate an Expression tree
 by calling generateExpression()
**/

class Scope {

    std::string s;

    public:

        // ChangeScope(s) changes scope with new expression string
        void changeScope(std::string s) ;

        // getStr returns a string inside the scope
        std::string getStr() ;

        Scope(std::string s) : s(s) {}

        // Generate expression object from the string s
        Expression *generateExpression();
};
#endif // _SCOPE_H_
