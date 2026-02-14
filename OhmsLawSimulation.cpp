/*
----------------------------------------------------
Program Name: OhmsLawSimulation.cpp
Author: Erika Sanders
Date Written: February 14, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program simulates Ohm’s Law (V = I × R).
It prompts the user for current and resistance,
calculates the voltage, generates a random
voltage between 0 and 100 volts, and displays
the difference between the two voltages.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>   // for fixed, setprecision, setw
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main()
{
    // Declare variables
    double currentAmps;
    double resistanceOhms;
    double calculatedVoltage;
    double randomVoltage;
    double voltageDifference;

    // Seed the random number generator
    srand(time(0));

    // Display program header
    cout << "-----------------------------------------\n";
    cout << " Ohm's Law Voltage Simulation Program\n";
    cout << "-----------------------------------------\n";

    // Prompt user for input
    cout << "Enter current (Amperes):   ";
    cin >> currentAmps;

    cout << "Enter resistance (Ohms):   ";
    cin >> resistanceOhms;

    // Calculate voltage using Ohm's Law
    calculatedVoltage = currentAmps * resistanceOhms;

    // Generate random voltage between 0 and 100
    randomVoltage = rand() % 101;  // 0–100 inclusive

    // Calculate difference
    voltageDifference = abs(calculatedVoltage - randomVoltage);

    // Format output
    cout << fixed << setprecision(2);

    cout << "\n";
    cout << setw(25) << left << "Calculated Voltage:" 
         << setw(10) << right << calculatedVoltage << " V" << endl;

    cout << setw(25) << left << "Random Gen. Voltage:" 
         << setw(10) << right << randomVoltage << " V" << endl;

    cout << setw(25) << left << "Difference:" 
         << setw(10) << right << voltageDifference << " V" << endl;

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT

-----------------------------------------
 Ohm's Law Voltage Simulation Program
-----------------------------------------
Enter current (Amperes):   2.5
Enter resistance (Ohms):   10

Calculated Voltage:            25.00 V
Random Gen. Voltage:           63.00 V
Difference:                    38.00 V

----------------------------------------------------
*/
