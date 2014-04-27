rootapproximate
===============

C++ program (side project) that approximates a root of a valid mathematical function/expression.<br>
The program reads a .rtap file as an input and determines the approximate root of the expression.<br>
<br>
.rtap format (see input.rtap as an example):<br>
<br>
First line : some mathematical expression, bring all variables to the right hand side<br>
Second line: number of iterations/resolution from 1 (low resolution) to 15 (high resolution safe)<br>
Third line : start value of x<br>
Fourth line: end value of x<br>
first y value<br>
...<br>
last y value<br>
EOF<br>
<br>
The program then exports the output as a .csv file which can be viewed using Excel spreadsheet.
