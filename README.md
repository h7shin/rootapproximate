rootapproximate
===============

C++ program (side project) that approximates a root of mathematical function/expression.
The program reads .rtap file as input and determines approximate root of the expression.

.rtap format (see inpu.rtap as an example):

First line : some mathematical expression, bring all variables to right hand side
Second line: resolution 1: low resolution, 5: high resolution (umlimited)
Third line : start value of x
Fourth line: end value of x
first y value
...
last y value
EOF

The program then exports the output as a .csv file which can be viewed using Excel spreadsheet.
