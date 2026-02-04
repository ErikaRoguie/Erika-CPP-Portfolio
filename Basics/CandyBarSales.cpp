// Program Name: CandyBarSales.cpp
// Author: Erika Sanders
// Date Written: February 4, 2026
// Class: CSC100AA or CIS162AB
// Brief Description: Calculates how much a student
// organization earns during its fund raising candy sale

#include <iostream>   // must include if you want to use cout
using namespace std;

int main()
{
    // Define variables
    int barsSold;          // number of candy bars sold
    double pricePerBar;    // earnings per bar
    double totalEarned;    // total earnings

    // Prompt the user to enter the number of candy bars sold
    cout << "How many candy bars were sold? ";
    cin >> barsSold;

    // Get the amount earned per bar
    cout << "How much is earned for each bar sold? ";
    cin >> pricePerBar;

    // Calculate the total earnings
    totalEarned = barsSold * pricePerBar;

    // Display the total earnings
    cout << "You have earned $" << totalEarned << endl;

    return 0;
}
