/*
----------------------------------------------------
Program Name: FullNameGreeting.cpp
Author: Erika Sanders
Date Written: February 12, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program prompts the user to enter their full
name (first, middle, and last) and displays a
greeting using their first and last name.
----------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName;
    string middleName;
    string lastName;

    // Prompt user for input
    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your middle name: ";
    getline(cin, middleName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    // Display greeting (first and last only)
    cout << "\nHello, " << firstName << " " << lastName << "!" << endl;

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT

Enter your first name: John
Enter your middle name: Michael
Enter your last name: Smith

Hello, John Smith!

----------------------------------------------------
*/
