/*
----------------------------------------------------
Program Name: restaurant_bill.cpp
Author: Erika Sanders
Date Written: February 6, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates and displays the tax,
tip, and total bill for a restaurant meal using
cout statements, variables, arithmetic operators,
and escape sequences.
----------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    // Define and initialize variables
    double mealCost = 44.50;
    double taxRate = 0.0675;     // 6.75% tax
    double tipRate = 0.15;       // 15% tip

    double taxAmount = 0.0;
    double tipAmount = 0.0;
    double totalBill = 0.0;

    // Perform calculations
    taxAmount = mealCost * taxRate;
    tipAmount = (mealCost + taxAmount) * tipRate;
    totalBill = mealCost + taxAmount + tipAmount;

    // Display formatted output using escape sequences
    cout << "------------------------------\n";
    cout << "Restaurant Bill\n";
    cout << "-------------------------------\n\n";

    cout << "Meal Cost:\t$" << mealCost << endl;
    cout << "Tax:\t\t$ " << taxAmount << endl;
    cout << "Tip:\t\t$ " << tipAmount << endl;
    cout << "---------------------------------------\n";
    cout << "Total:\t\t$" << totalBill << endl;

    return 0;
}

/*
----------------------------------------------------
Tested Output

------------------------------
Restaurant Bill
-------------------------------

Meal Cost: 	$44.5
Tax:      	$ 3.00375
Tip:       	$ 7.12556
---------------------------------------
Total     	$54.6293
----------------------------------------------------
*/
