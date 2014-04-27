#include "rootapproximator.h"

vector <double> RootApproximator::getRoot (double startx, double finalx, int resolution) {
    char approximate = '~';

    bool debug = 0;
    vector<double> closestrootXY;
    Function eq(y , (finalx - startx)/10, startx, finalx );

    while (resolution > 0) {
        cout << startx << "<= x <=" << finalx << endl;
        eq = Function(y, (finalx - startx)/10, startx, finalx);
        closestrootXY = eq.smallestXY();
        startx = (startx > (closestrootXY[0]-(finalx - startx)/10)) ? startx : closestrootXY[0]-(finalx - startx)/10;
        finalx = (finalx < (closestrootXY[0]+(finalx - startx)/10)) ? finalx : closestrootXY[0]+(finalx - startx)/10;
        resolution -= 1;
    }

    cout <<  closestrootXY[0] << " is the result for x with eval = "<< closestrootXY[1] << " " << approximate << "== 0"<< endl << endl;
    return closestrootXY;
}
