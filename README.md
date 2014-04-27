rootapproximate
===============

C++ program (side project) that approximates a root of mathematical function/expression.
The program reads .rtap file as input and determines approximate root of the expression.

.rtap format (see inpu.rtap as an example)
<some mathematical expression, bring all variables to right hand side>
<resolution 1: low resolution, 5: high resolution (umlimited)>
<start value of x>
<end value of x>
<first y value>
...
<last y value>

The program then exports the output as a .csv file which can be viewed using Excel spreadsheet.
