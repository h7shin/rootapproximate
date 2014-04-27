#include "function.h"

vector <double> Function::smallestXY() {

        stringstream ss;
        double x = minx;
        bool debug = 0;
        string org_str = scope->getStr();
        string new_str = org_str;
        string replacement;
        vector <double> closestrootXY;
        double evaluated_value;
        Expression *expression;

        for (x = minx; x <= maxx; x += increment) {
            new_str = org_str;
            ss << x;
            replacement = ss.str();

            // Substitute for x
            for (int q = 0; q <= new_str.length(); q++) {
                //cout << new_str[q] << endl;
                if (new_str[q] == 'x') {
                    new_str.erase(q,1);
                    new_str.insert(q, replacement);
                }
            }
            ss.str("");

            if (debug) cout << " " << new_str << x << "," << replacement << "," << maxx << ", " << endl;

            // Change Scope with new_str
            scope->changeScope(new_str);

            // Generate Expression
            expression = scope->generateExpression();

            // Evaluate Expression
            evaluated_value = expression->evaluate() ;

            // Free memory
            delete expression;

            if (debug) cout << replacement << " VALUE:" << evaluated_value<< endl;
            if (x == minx) {
                closestrootXY.push_back(atof(replacement.c_str()));
                closestrootXY.push_back(evaluated_value);
            } else if (abs(closestrootXY[1]) > abs(evaluated_value)) {
                closestrootXY[0]=(atof(replacement.c_str()));
                closestrootXY[1]=(evaluated_value);
            }
            if (debug)  cout << "CLOSEST TO ROOT XY SO FAR" << closestrootXY[0] << ":" << closestrootXY[1] << endl;
        }
        return closestrootXY;
}
