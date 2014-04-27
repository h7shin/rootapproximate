#include "scope.h"

// see interface

string removeOuterParen(string s) {
    bool leftparenfound = 0;
    bool rightparenfound = 0;
    for (int j = 0; j < s.length(); j++) {
        if ((s[j] == '(')) {
            s[j] = ' ';
            leftparenfound = 1;
            break;
        }
    }
    for (int j = 0; j < s.length(); j++) {
        if ((s[s.length() - 1 - j] == ')')) {
            if (leftparenfound) s[s.length() - 1 - j] = ' ';
            rightparenfound = 1;
            break;
        }
    }
    if (!(rightparenfound) ) s = "(" + s;
    return s;
}

// see interface

Expression *Scope::generateExpression() {

    bool debug[3] = {0,0,0};
    if (debug[0]) cout << "Scope is " << s << endl;
    string left;
    string right;
    Scope ls("");
    Scope rs("");
    int depth = 0;
    for (int i = 0; i < s.length(); i++) {

        // Depth Adjustment by detecting parentheses
        if (s[i] == '(') depth++;
        if (s[i] == ')') depth--;
        if (debug[1]) cout << s[i] << "<= at depth " << depth << endl;


        if ((depth == 1) &&
            ((s[i] == '+') || ((s[i] == '-') && (s[i+1] == ' ')) || (s[i] == '/') || (s[i] == '*') ||  (s[i] == '^'))) {

            // Get left and right substring of the string s
            left = s.substr(0,i);
            right = s.substr(i+1, s.length() - 1);

            // Create left and right scopes
            ls = Scope(removeOuterParen(left) + ")");
            rs = Scope("(" + removeOuterParen(right));

            if (debug[2]) cout << ls.getStr() << " bin "<< rs.getStr()  << endl ;

            // Generate the expression recursively from the left and right scopes
            if (s[i] == '+') {
                return new SumBinaryExpression(ls.generateExpression(), rs.generateExpression());
            } else if (s[i] == '-') {
                return new DifferenceBinaryExpression(ls.generateExpression(), rs.generateExpression());
            } else if (s[i] == '/') {
                return new DivisionBinaryExpression(ls.generateExpression(), rs.generateExpression());
            } else if (s[i] == '*') {
                return new ProductBinaryExpression(ls.generateExpression(), rs.generateExpression());
            } else if (s[i] == '^') {
                return new PowerBinaryExpression(ls.generateExpression(), rs.generateExpression());
            }

        } else if ((depth == 1) && ((s[i] == 'n')
                                    || (s[i] == 'g') ||  (s[i] == 'i')  || ((s[i] == '-') && (s[i+1] == '('))))  {

            rs = Scope(s.substr(i+1, s.length() - 1));

            // Generate the expression recursively from the right (inner) scopes
            if (s[i] == 'n') {
                return new LogUnaryExpression(rs.generateExpression());
            } else if (s[i] == 'g') {
                return new LogCommonUnaryExpression(rs.generateExpression());
            } else if (s[i] == '-') {
                return new NegativeUnaryExpression(rs.generateExpression());
            } else if (s[i] == 'i') {
                return new IdentityUnaryExpression(rs.generateExpression());
            }

        } else if (i == s.length() - 1) {

            // Generate a numeric expression (a number)

            if (debug[2]) cout << " numeric "<< s << endl ;
            return new NumericUnaryExpression(atof(removeOuterParen(s).c_str()));
        }
    }
}
