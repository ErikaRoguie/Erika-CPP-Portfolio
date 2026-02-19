/*
----------------------------------------------------
Program Name: GradeCalculator.cpp
Author: Erika Sanders
Date Written: February 14, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This menu-driven program calculates a student’s test
percentage and letter grade. It uses getline() to read
a full name, validates all inputs, prevents int/int
division using type casting, and formats aligned output
using setw with one decimal place.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>    // fixed, setprecision, setw
#include <string>     // string, getline
#include <limits>     // numeric_limits

using namespace std;

// Validates that a full name is not empty (and not just spaces)
string getValidatedFullName(const string& prompt)
{
    string name;

    while (true)
    {
        cout << prompt;
        getline(cin, name);

        // Check if name contains at least one non-space character
        bool hasLetter = false;
        for (char ch : name)
        {
            if (ch != ' ' && ch != '\t')
            {
                hasLetter = true;
                break;
            }
        }

        if (hasLetter)
            return name;

        cout << "Invalid input. Please enter a first and last name (not blank).\n";
    }
}

// Validates an integer input within a range [minValue, maxValue]
int getValidatedIntInRange(const string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (value < minValue || value > maxValue)
        {
            cout << "Invalid input. Please enter a value from "
                 << minValue << " to " << maxValue << ".\n";
            continue;
        }

        return value;
    }
}

// Determines letter grade from percentage
char getLetterGrade(double percent)
{
    if (percent >= 90.0) return 'A';
    if (percent >= 80.0) return 'B';
    if (percent >= 70.0) return 'C';
    if (percent >= 60.0) return 'D';
    return 'F';
}

// Menu choice validation
int getMenuChoice()
{
    return getValidatedIntInRange("\nChoose an option (1-4): ", 1, 4);
}

int main()
{
    string studentFullName = "";
    int numberOfQuestions = 0;
    int numberCorrect = 0;
    double percentageCorrect = 0.0;
    bool dataEntered = false;

    cout << fixed << setprecision(1); // required formatting

    int choice;
    do
    {
        cout << "\n========================================\n";
        cout << "         Grade Calculator - Menu\n";
        cout << "========================================\n";
        cout << "1. Enter student and test data\n";
        cout << "2. Calculate and display results\n";
        cout << "3. Reset\n";
        cout << "4. Exit\n";

        choice = getMenuChoice();

        switch (choice)
        {
            case 1:
            {
                studentFullName = getValidatedFullName("Enter student's first and last name: ");

                // Questions must be > 0; choose a reasonable max like 500
                numberOfQuestions = getValidatedIntInRange("Number of questions on the test: ", 1, 500);

                // Correct must be between 0 and numberOfQuestions
                numberCorrect = getValidatedIntInRange(
                    "Number of answers the student got correct: ",
                    0, numberOfQuestions
                );

                dataEntered = true;
                cout << "\nData saved.\n";
                break;
            }

            case 2:
            {
                if (!dataEntered)
                {
                    cout << "\nPlease enter student and test data first (Option 1).\n";
                    break;
                }

                // Prevent int/int division with type casting
                percentageCorrect =
                    (static_cast<double>(numberCorrect) / numberOfQuestions) * 100.0;

                char letterGrade = getLetterGrade(percentageCorrect);
                string passFail = (percentageCorrect >= 60.0) ? "PASS" : "FAIL";

                cout << "\n----------------------------------------\n";
                cout << "Results\n";
                cout << "----------------------------------------\n";

                // Aligned output using setw
                cout << setw(20) << left  << "Student:"
                     << studentFullName << endl;

                cout << setw(20) << left  << "Questions:"
                     << numberOfQuestions << endl;

                cout << setw(20) << left  << "Correct:"
                     << numberCorrect << endl;

                cout << setw(20) << left  << "Percentage:"
                     << percentageCorrect << "%" << endl;

                cout << setw(20) << left  << "Letter Grade:"
                     << letterGrade << endl;

                cout << setw(20) << left  << "Status:"
                     << passFail << endl;

                break;
            }

            case 3:
                studentFullName = "";
                numberOfQuestions = 0;
                numberCorrect = 0;
                percentageCorrect = 0.0;
                dataEntered = false;
                cout << "\nAll values reset.\n";
                break;

            case 4:
                cout << "\nGoodbye!\n";
                break;
        }

    } while (choice != 4);

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT (shows validation + aligned results)

========================================
         Grade Calculator - Menu
========================================
1. Enter student and test data
2. Calculate and display results
3. Reset
4. Exit

Choose an option (1-4): 2

Please enter student and test data first (Option 1).

Choose an option (1-4): 1
Enter student's first and last name:
Invalid input. Please enter a first and last name (not blank).
Enter student's first and last name: John Smith
Number of questions on the test: 0
Invalid input. Please enter a value from 1 to 500.
Number of questions on the test: 40
Number of answers the student got correct: 50
Invalid input. Please enter a value from 0 to 40.
Number of answers the student got correct: 31

Data saved.

Choose an option (1-4): 2

----------------------------------------
Results
----------------------------------------
Student:            John Smith
Questions:          40
Correct:            31
Percentage:         77.5%
Letter Grade:       C
Status:             PASS

Choose an option (1-4): 4

Goodbye!
----------------------------------------------------
*/
