/*
----------------------------------------------------
Program Name: StadiumSeating_Menu.cpp
Author: Erika Sanders
Date Written: February 12, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates total income from stadium
ticket sales for three seating classes. It uses a
menu and input validation to ensure correct entries.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// BONUS:
// Constants are defined when a value should not change during program execution.
// They improve readability, prevent accidental modification, and make updates easier.
// Examples of constants: tax rates, ticket prices, conversion factors (12 inches per foot),
// and mathematical constants (pi ≈ 3.14159).

// Seat prices (constants)
const double CLASS_A_PRICE = 15.00;
const double CLASS_B_PRICE = 12.00;
const double CLASS_C_PRICE = 9.00;

// Function to safely get a non-negative integer with validation
int getNonNegativeInt(const string& prompt)
{
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        // Check for non-integer input
        if (cin.fail())
        {
            cin.clear(); // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter a whole number (0 or greater).\n";
            continue;
        }

        // Discard any extra input on the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Check for negative values
        if (value < 0)
        {
            cout << "Invalid input. Please enter a number 0 or greater.\n";
            continue;
        }

        return value;
    }
}

// Function to display current ticket counts
void displayCurrentCounts(int aSold, int bSold, int cSold)
{
    cout << "\nCurrent Tickets Sold\n";
    cout << "---------------------\n";
    cout << "Class A: " << aSold << endl;
    cout << "Class B: " << bSold << endl;
    cout << "Class C: " << cSold << endl;
}

int main()
{
    int classATicketsSold = 0;
    int classBTicketsSold = 0;
    int classCTicketsSold = 0;

    bool ticketsEntered = false;
    int choice = 0;

    cout << fixed << showpoint << setprecision(2);

    do
    {
        cout << "\n====================================\n";
        cout << "\tStadium Seating - Menu\n";
        cout << "====================================\n";
        cout << "1. Enter tickets sold\n";
        cout << "2. View current ticket counts\n";
        cout << "3. Calculate and display total income\n";
        cout << "4. Reset ticket counts\n";
        cout << "5. Exit\n";

        choice = getNonNegativeInt("Choose an option (1-5): ");

        switch (choice)
        {
            case 1:
                classATicketsSold = getNonNegativeInt("Number of class A tickets sold:  ");
                classBTicketsSold = getNonNegativeInt("Number of class B tickets sold:  ");
                classCTicketsSold = getNonNegativeInt("Number of class C tickets sold:  ");
                ticketsEntered = true;
                break;

            case 2:
                displayCurrentCounts(classATicketsSold, classBTicketsSold, classCTicketsSold);
                break;

            case 3:
            {
                if (!ticketsEntered)
                {
                    cout << "\nPlease enter ticket quantities first (Option 1).\n";
                    break;
                }

                double totalIncome =
                    (classATicketsSold * CLASS_A_PRICE) +
                    (classBTicketsSold * CLASS_B_PRICE) +
                    (classCTicketsSold * CLASS_C_PRICE);

                cout << "\nThe income from the sale of stadium seats is $"
                     << totalIncome << endl;
                break;
            }

            case 4:
                classATicketsSold = 0;
                classBTicketsSold = 0;
                classCTicketsSold = 0;
                ticketsEntered = false;
                cout << "\nTicket counts have been reset to 0.\n";
                break;

            case 5:
                cout << "\nExiting program. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid option. Please choose 1 through 5.\n";
        }

    } while (choice != 5);

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT (includes validation example)

====================================
    Stadium Seating - Menu
====================================
1. Enter tickets sold
2. View current ticket counts
3. Calculate and display total income
4. Reset ticket counts
5. Exit
Choose an option (1-5): 3

Please enter ticket quantities first (Option 1).

Choose an option (1-5): 1
Number of class A tickets sold:  -2
Invalid input. Please enter a number 0 or greater.
Number of class A tickets sold:  210
Number of class B tickets sold:  325
Number of class C tickets sold:  62

Choose an option (1-5): 3

The income from the sale of stadium seats is $7608.00

Choose an option (1-5): 5

Exiting program. Goodbye!
----------------------------------------------------
*/
