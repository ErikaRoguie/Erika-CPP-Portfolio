/*
----------------------------------------------------
Program Name: ElectricalLab.cpp
Author: Erika Sanders
Date Written: February 14, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program is a menu-driven "Electrical Lab" mini-project.
It uses Ohm’s Law (V = I × R) to calculate voltage based on
user-entered current and resistance, generates a random voltage
(0 to 100 volts), and shows the difference between calculated
and random voltage. Includes input validation and formatted output.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>    // fixed, setprecision, setw
#include <cstdlib>    // rand, srand
#include <ctime>      // time
#include <limits>     // numeric_limits
#include <cmath>      // fabs

using namespace std;

// Gets a valid number (double) that is >= minValue
double getValidatedDouble(const string& prompt, double minValue)
{
    double value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a numeric value.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (value < minValue)
        {
            cout << "Invalid input. Value must be " << minValue << " or greater.\n";
            continue;
        }

        return value;
    }
}

// Gets a validated menu choice in a range
int getValidatedMenuChoice(const string& prompt, int minChoice, int maxChoice)
{
    int choice;

    while (true)
    {
        cout << prompt;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice < minChoice || choice > maxChoice)
        {
            cout << "Invalid choice. Please enter a number from "
                 << minChoice << " to " << maxChoice << ".\n";
            continue;
        }

        return choice;
    }
}

// Displays the lab header
void displayHeader()
{
    cout << "-----------------------------------------\n";
    cout << "      Electrical Lab - Ohm's Law Sim\n";
    cout << "-----------------------------------------\n";
}

// Displays current settings
void displaySettings(double currentAmps, double resistanceOhms, bool valuesSet)
{
    cout << fixed << setprecision(2);
    cout << "\nCurrent Lab Settings\n";
    cout << "--------------------\n";

    if (!valuesSet)
    {
        cout << "Current (I):     (not set)\n";
        cout << "Resistance (R):  (not set)\n";
    }
    else
    {
        cout << "Current (I):     " << currentAmps << " A\n";
        cout << "Resistance (R):  " << resistanceOhms << " ohms\n";
    }
}

int main()
{
    // Seed random number generator (required)
    srand(time(0));

    // Lab variables
    double currentAmps = 0.0;
    double resistanceOhms = 0.0;
    bool valuesSet = false;

    // Output formatting settings
    cout << fixed << setprecision(2);

    int choice;

    do
    {
        displayHeader();
        cout << "1. Enter current (Amperes)\n";
        cout << "2. Enter resistance (Ohms)\n";
        cout << "3. Run voltage simulation (Calculate vs Random)\n";
        cout << "4. View current settings\n";
        cout << "5. Reset lab values\n";
        cout << "6. Exit\n\n";

        choice = getValidatedMenuChoice("Choose an option (1-6): ", 1, 6);

        if (choice == 1)
        {
            // Current can be 0 or greater
            currentAmps = getValidatedDouble("\nEnter current (Amperes):   ", 0.0);
            valuesSet = true;
            cout << "Current saved.\n\n";
        }
        else if (choice == 2)
        {
            // Resistance should be > 0 for meaningful voltage calculation
            resistanceOhms = getValidatedDouble("\nEnter resistance (Ohms):   ", 0.01);
            valuesSet = true;
            cout << "Resistance saved.\n\n";
        }
        else if (choice == 3)
        {
            if (!valuesSet || resistanceOhms <= 0.0)
            {
                cout << "\nPlease set BOTH values first:\n";
                cout << "- Current (I) must be 0 or greater\n";
                cout << "- Resistance (R) must be greater than 0\n\n";
                continue;
            }

            // Calculate voltage using Ohm's Law: V = I * R
            double calculatedVoltage = currentAmps * resistanceOhms;

            // Random voltage between 0 and 100 inclusive
            double randomVoltage = rand() % 101;

            // Difference between calculated and random
            double voltageDifference = fabs(calculatedVoltage - randomVoltage);

            // Display formatted results with alignment
            cout << "\n";
            cout << setw(25) << left  << "Calculated Voltage:"
                 << setw(10) << right << calculatedVoltage << " V\n";

            cout << setw(25) << left  << "Random Gen. Voltage:"
                 << setw(10) << right << randomVoltage << " V\n";

            cout << setw(25) << left  << "Difference:"
                 << setw(10) << right << voltageDifference << " V\n\n";
        }
        else if (choice == 4)
        {
            displaySettings(currentAmps, resistanceOhms, valuesSet);
            cout << "\n";
        }
        else if (choice == 5)
        {
            currentAmps = 0.0;
            resistanceOhms = 0.0;
            valuesSet = false;
            cout << "\nLab values have been reset.\n\n";
        }

    } while (choice != 6);

    cout << "\nExiting Electrical Lab. Goodbye!\n";
    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT (example - random voltage will vary)

-----------------------------------------
      Electrical Lab - Ohm's Law Sim
-----------------------------------------
1. Enter current (Amperes)
2. Enter resistance (Ohms)
3. Run voltage simulation (Calculate vs Random)
4. View current settings
5. Reset lab values
6. Exit

Choose an option (1-6): 3

Please set BOTH values first:
- Current (I) must be 0 or greater
- Resistance (R) must be greater than 0

Choose an option (1-6): 1

Enter current (Amperes):   2.5
Current saved.

Choose an option (1-6): 2

Enter resistance (Ohms):   10
Resistance saved.

Choose an option (1-6): 3

Calculated Voltage:            25.00 V
Random Gen. Voltage:           63.00 V
Difference:                    38.00 V

Choose an option (1-6): 6

Exiting Electrical Lab. Goodbye!
----------------------------------------------------
*/
