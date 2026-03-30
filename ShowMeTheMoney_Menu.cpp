/*
----------------------------------------------------
Program Name: ShowMeTheMoney_Menu.cpp
Author: Erika Sanders
Date Written: February 18, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates a person's earnings where
the salary starts at one penny and doubles each day.
It displays a table of daily earnings, cumulative
total, allows repeated calculations through a menu,
and can also show earnings for a full 31-day month.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void showMenu();
int getValidDays();
void runSalarySimulation(int days);
void showThirtyOneDaySummary();

int main()
{
    int choice;

    cout << fixed << setprecision(2);

    do
    {
        showMenu();
        cout << "Choose an option (1-3): ";
        cin >> choice;

        while (choice < 1 || choice > 3)
        {
            cout << "Invalid choice. Please enter 1, 2, or 3: ";
            cin >> choice;
        }

        switch (choice)
        {
            case 1:
            {
                int days = getValidDays();
                runSalarySimulation(days);
                break;
            }

            case 2:
                showThirtyOneDaySummary();
                break;

            case 3:
                cout << "\nPress any key to continue . . ." << endl;
                break;
        }

    } while (choice != 3);

    return 0;
}

// Displays menu
void showMenu()
{
    cout << "\n====================================\n";
    cout << "         Show Me The Money\n";
    cout << "====================================\n";
    cout << "1. Enter days worked and view salary table\n";
    cout << "2. Show full 31-day earnings summary\n";
    cout << "3. Exit\n\n";
}

// Validates days input
int getValidDays()
{
    int days;

    cout << "How many days did the employee work this month? ";
    cin >> days;

    while (days < 1 || days > 31)
    {
        cout << "The number of days must be between 1 and 31.\n";
        cout << "Please re-enter days worked. ";
        cin >> days;
    }

    return days;
}

// Runs salary simulation for selected days
void runSalarySimulation(int days)
{
    double dailyPay = 0.01;
    double totalPay = 0.0;

    cout << "\nDay\tPay\t\tCumulative Total\n";
    cout << "---------------------------------------------\n";

    for (int day = 1; day <= days; day++)
    {
        totalPay += dailyPay;
        cout << day << "\t$" << dailyPay << "\t\t$" << totalPay << endl;
        dailyPay *= 2.0;
    }

    cout << "---------------------------------------------\n";
    cout << "Total $ " << totalPay << endl;

    cout << "\nWould you take this job if offered? ";
    if (totalPay > 1000.00)
        cout << "Yes, because the pay grows very quickly!" << endl;
    else
        cout << "Not for a short time, because it starts very small." << endl;
}

// Shows 31-day summary
void showThirtyOneDaySummary()
{
    double dailyPay = 0.01;
    double totalPay = 0.0;

    for (int day = 1; day <= 31; day++)
    {
        totalPay += dailyPay;
        if (day < 31)
            dailyPay *= 2.0;
    }

    cout << "\n31-Day Earnings Summary\n";
    cout << "------------------------------\n";
    cout << "Pay on Day 31: $" << dailyPay << endl;
    cout << "Total after 31 days: $" << totalPay << endl;
    cout << "------------------------------\n";
    cout << "Yes, I would definitely take this job for the full month!" << endl;
}

/*
----------------------------------------------------
TEST OUTPUT

====================================
         Show Me The Money
====================================
1. Enter days worked and view salary table
2. Show full 31-day earnings summary
3. Exit

Choose an option (1-3): 1
How many days did the employee work this month? 3

Day     Pay             Cumulative Total
---------------------------------------------
1       $0.01           $0.01
2       $0.02           $0.03
3       $0.04           $0.07
---------------------------------------------
Total $ 0.07

Would you take this job if offered? Not for a short time, because it starts very small.

====================================
         Show Me The Money
====================================
1. Enter days worked and view salary table
2. Show full 31-day earnings summary
3. Exit

Choose an option (1-3): 1
How many days did the employee work this month? 45
The number of days must be between 1 and 31.
Please re-enter days worked. -2
The number of days must be between 1 and 31.
Please re-enter days worked. 7

Day     Pay             Cumulative Total
---------------------------------------------
1       $0.01           $0.01
2       $0.02           $0.03
3       $0.04           $0.07
4       $0.08           $0.15
5       $0.16           $0.31
6       $0.32           $0.63
7       $0.64           $1.27
---------------------------------------------
Total $ 1.27

Would you take this job if offered? Not for a short time, because it starts very small.

====================================
         Show Me The Money
====================================
1. Enter days worked and view salary table
2. Show full 31-day earnings summary
3. Exit

Choose an option (1-3): 2

31-Day Earnings Summary
------------------------------
Pay on Day 31: $10737418.24
Total after 31 days: $21474836.47
------------------------------
Yes, I would definitely take this job for the full month!

====================================
         Show Me The Money
====================================
1. Enter days worked and view salary table
2. Show full 31-day earnings summary
3. Exit

Choose an option (1-3): 3

Press any key to continue . . .

----------------------------------------------------
*/
