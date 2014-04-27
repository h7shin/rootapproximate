#include "function.h"
#include "rootapproximator.h"
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>      // std::setprecision
using namespace std;


/**
--------------------------------------------------------
Valid Expression:

All expression must be one of the forms below

    a               where 'a' is a number (double)
    -a              where 'a' is a number (double)
    (A ? B)         where ? is one of ('+', '-', '/', '*', '^' ...)
                    and A and B are valid expressions
    -(A)            where A is a valid expression
    ln(A)           where A is a valid expression
    log(A)          where A is a valid expression
    i(A)            where A is a valid expression

the expression only contains a free variable x (value of y
is implicitely defined by subtracting value of y at the end of the expression)

the expression does not have an equal sign
if the operator is '-' either it is of three forms
    -a              where 'a' is a number
    -(...)          negative
    ((...) - (...)) difference

--------------------------------------------------------
Program calculates approximate root of expression from input of y values
(after moving all of the variables and numbers to the right side of the equation)
and save the output of the calculations in csv format

**/


int main () {

    // test();

    string line;
    string originalxyexpression;
    string xyexpression;
    int resolution;
    int maximum;
    int minimum;
    RootApproximator r;
    string buffer;
    string filename;
    int linenumber = 0;
    vector <double> vec;

    cout << "RootApproxmiation" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "" << endl;
    cout << "Place input.rtap file in the same directory" << endl;
    cout << "Format (example):" << endl;
    cout << "(((x ^ 2) + (2 * x)) - y)" << endl;
    cout << "<accuracy/resolution value (0 to infinity)>" << endl;
    cout << "<lower bound of x>" << endl;
    cout << "<upper bound of x>" << endl;
    cout << "<x values one in each line>" << endl;
    cout << "" << endl;
    cout << "Do you wish to use a custom file? [y/n]" << endl;
    cin >> buffer;

    if (buffer == "y") {
        cout << "Enter file name (include .rtap extension)" << endl;
        cin >> filename;
    } else {
        filename = "input.rtap";
    }

    ofstream of ("output.csv", ofstream::out);
    of <<  "x (apx), y , %Error" << endl;
    ifstream file (filename.c_str());

    // Read input.rtap File
    if (file.is_open()) {
        while ( getline (file, line)) {
            if (linenumber == 0) {
                originalxyexpression = line;
                xyexpression = line;
            } else if (linenumber == 1) {
                istringstream ( line ) >> resolution;
            } else if (linenumber == 2) {
                istringstream ( line ) >> minimum;
            } else if (linenumber == 3) {
                istringstream ( line ) >> maximum;
            } else {
                for (int q = 0; q <=xyexpression.length(); q++) {
                    if (xyexpression[q] == 'y') {
                        xyexpression.erase(q,1);
                        xyexpression.insert(q, line);
                        break;
                    }
                }
                cout << xyexpression << endl;

                // Approximate Root
                r = RootApproximator(xyexpression);
                vec = r.getRoot( 0, 10, resolution);

                // Print x, y, and percent error rate
                of  << std::setprecision(10) <<  vec[0] << ", " << line << ", "<< abs(vec[1]/vec[0]*100) << "%"<< endl;
                xyexpression = originalxyexpression;
            }
            linenumber++;
        }
    }
    file.close();
    of.close();
}
