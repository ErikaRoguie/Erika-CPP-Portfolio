/*
----------------------------------------------------
Program Name: StadiumSeating.cpp
Author: Erika Sanders
Date Written: February 8, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates the total income generated
from stadium ticket sales for three seating classes.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>   // Required for fixed, setprecision, showpoint
using namespace std;

int main()
{
    // Define constants for seat prices
    const double CLASS_A_PRICE = 15.00;
    const double CLASS_B_PRICE = 12.00;
    const double CLASS_C_PRICE = 9.00;

    /*
    BONUS:
    Constants are defined when a value should not change
    during program execution. They improve readability,
    prevent accidental modification, and make maintenance easier.

    Examples of constants:
    - Tax rates (e.g., 0.0675)
    - Pi value (3.14159)
    - Fixed pricing (ticket costs, subscription fees)
    - Conversion factors (e.g., inches per foot = 12)
    */

    // Define variables for tickets sold
    int classATicketsSold;
    int classBTicketsSold;
    int classCTicketsSold;

    // Define variable for total income
    double totalIncome;

    // Prompt user for ticket quantities
    cout << "Number of class A tickets sold:  ";
    cin >> classATicketsSold;

    cout << "Number of class B tickets sold:  ";
    cin >> classBTicketsSold;

    cout << "Number of class C tickets sold:  ";
    cin >> classCTicketsSold;

    // Calculate total income
    totalIncome = (classATicketsSold * CLASS_A_PRICE) +
                  (classBTicketsSold * CLASS_B_PRICE) +
                  (classCTicketsSold * CLASS_C_PRICE);

    // Format output for fixed-point notation with 2 decimals
    cout << fixed << showpoint << setprecision(2);

    // Display total income
    cout << "\nThe income from the sale of stadium seats is $"
         << totalIncome << endl;

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT

Number of class A tickets sold:  210
Number of class B tickets sold:  325
Number of class C tickets sold:  62

The income from the sale of stadium seats is $7608.00

----------------------------------------------------
*/
