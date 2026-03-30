/*
----------------------------------------------------
Program Name: ShowMeTheMoney.cpp
Author: Erika Sanders
Date Written: February 18, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates a person's earnings where
the salary starts at one penny and doubles each day.
It displays a table of daily earnings and total pay
in dollars. Includes input validation and a do..while
loop to repeat the program.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int days;
    char again;

    cout << fixed << setprecision(2);

    do
    {
        // Prompt for days worked
        cout << "How many days did the employee work this month? ";
        cin >> days;

        // Input validation
        while (days < 1 || days > 31)
        {
            cout << "The number of days must be between 1 and 31.\n";
            cout << "Please re-enter days worked. ";
            cin >> days;
        }

        // Variables
        double dailyPay = 0.01;   // 1 penny in dollars
        double totalPay = 0.0;

        // Display table header
        cout << "\nDay\tPay\n";
        cout << "------------------\n";

        // Loop through each day
        for (int day = 1; day <= days; day++)
        {
            cout << day << "\t" << dailyPay << endl;
            totalPay += dailyPay;
            dailyPay *= 2;   // double pay each day
        }

        // Display total
        cout << "------------------\n";
        cout << "Total $ " << totalPay << endl;

        // Ask to repeat
        cout << "\nDo you want to try again? (Y or N) ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "\nPress any key to continue . . ." << endl;

    return 0;
}

/*
----------------------------------------------------
TEST OUTPUT

How many days did the employee work this month? 3

Day     Pay
------------------
1       0.01
2       0.02
3       0.04
------------------
Total $ 0.07

Do you want to try again? (Y or N) y

How many days did the employee work this month? 45
The number of days must be between 1 and 31.
Please re-enter days worked. -2
The number of days must be between 1 and 31.
Please re-enter days worked. 3

Day     Pay
------------------
1       0.01
2       0.02
3       0.04
------------------
Total $ 0.07

Do you want to try again? (Y or N) n

Press any key to continue . . .

----------------------------------------------------
*/
