rootapproximate
===============

C++ program (side project) that approximates a root of mathematical function/expression.<br>
The program reads .rtap file as input and determines approximate root of the expression.<br>
<br>
.rtap format (see inpu.rtap as an example):<br>
<br>
First line : some mathematical expression, bring all variables to the right hand side<br>
Second line: resolution 1: low resolution, 5: high resolution (umlimited)<br>
Third line : start value of x<br>
Fourth line: end value of x<br>
first y value<br>
...<br>
last y value<br>
EOF<br>
<br>
The program then exports the output as a .csv file which can be viewed using Excel spreadsheet.
