/*
----------------------------------------------------
Program Name: TwoNumbers.cpp
Author: Erika Sanders
Date Written: February 6, 2026
Class: CSC100AA / CIS162AB
Brief Description:
This program declares two integer variables and
performs basic arithmetic operations (addition,
subtraction, multiplication, and division).
The results are displayed to the screen.
----------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    // Declare and initialize integer variables
    int num1 = 25;
    int num2 = 75;

    // Declare variables to store results
    int sum;
    int difference;
    int product;
    int quotient;

    // Perform arithmetic operations
    sum = num1 + num2;

    // Subtract smaller value from larger value
    difference = num2 - num1;

    product = num1 * num2;

    // Divide larger value by smaller value
    quotient = num2 / num1;

    // Display results
    cout << "The values are:\t\t" << num1 << " and " << num2 << endl << endl;
    cout << "\tSum:\t\t" << sum << endl;
    cout << "\tDifference:\t" << difference << endl;
    cout << "\tProduct:\t" << product << endl;
    cout << "\tQuotient:\t" << quotient << endl;

    return 0;
}

/*
----------------------------------------------------
Difference between / (divide) and % (modulus):

The division operator (/) returns the quotient of
two numbers.

The modulus operator (%) returns the remainder
after division.

Example:
75 / 25 = 3
75 % 25 = 0
----------------------------------------------------

Observations when changing int to double:

- Using int division truncates decimal values.
- Using double allows fractional results.
- Example:
  int:    75 / 25 = 3
  double: 75.0 / 25.0 = 3.0
----------------------------------------------------

Test Output (Initial Values: 25 and 75)

The values are:     	25 and 75

    	Sum:        	100
    	Difference: 	50
    	Product:    	1875
    	Quotient:   	3

----------------------------------------------------

Test Output (Changed Values: 125 and 25)

The values are:     	125 and 25

    	Sum:        	150
    	Difference: 	100
    	Product:    	3125
    	Quotient:   	5
----------------------------------------------------
*/
