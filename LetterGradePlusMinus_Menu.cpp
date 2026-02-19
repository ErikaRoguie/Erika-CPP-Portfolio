/*
----------------------------------------------------
Program Name: LetterGradePlusMinus_Menu.cpp
Author: Erika Sanders
Date Written: February 15, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This menu-driven program accepts a numeric test score
and displays a letter grade with plus/minus (A, A-, B+,
etc.). It includes full input validation to reject
non-numeric input and enforces a valid score range of
0 to 100.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// Get a valid integer from the user (rejects letters/symbols)
int getValidatedInt(const string& prompt)
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
            cout << "Invalid input. Please enter a whole number (digits only).\n";
            continue;
        }

        // Clear any extra characters on the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

// Get a valid score in range 0-100
int getValidatedScore()
{
    while (true)
    {
        int score = getValidatedInt("Enter your numeric test score (0-100): ");

        if (score < 0 || score > 100)
        {
            cout << "Invalid score. Please enter a value from 0 to 100.\n";
            continue;
        }

        return score;
    }
}

// Determine plus/minus letter grade
string getLetterGradePlusMinus(int score)
{
    // A range
    if (score >= 90)
    {
        if (score >= 97) return "A+";
        if (score >= 93) return "A";
        return "A-";
    }

    // B range
    if (score >= 80)
    {
        if (score >= 87) return "B+";
        if (score >= 83) return "B";
        return "B-";
    }

    // C range
    if (score >= 70)
    {
        if (score >= 77) return "C+";
        if (score >= 73) return "C";
        return "C-";
    }

    // D range
    if (score >= 60)
    {
        if (score >= 67) return "D+";
        if (score >= 63) return "D";
        return "D-";
    }

    // F range
    return "F";
}

void showMenu()
{
    cout << "\n====================================\n";
    cout << "      Grade Calculator - Menu\n";
    cout << "====================================\n";
    cout << "1. Enter a score and get grade\n";
    cout << "2. Show grading scale\n";
    cout << "3. Exit\n";
}

void showScale()
{
    cout << "\nGrading Scale (Plus/Minus)\n";
    cout << "--------------------------\n";
    cout << "A+: 97-100\nA : 93-96\nA-: 90-92\n\n";
    cout << "B+: 87-89\nB : 83-86\nB-: 80-82\n\n";
    cout << "C+: 77-79\nC : 73-76\nC-: 70-72\n\n";
    cout << "D+: 67-69\nD : 63-66\nD-: 60-62\n\n";
    cout << "F :  0-59\n";
}

int main()
{
    int choice;

    do
    {
        showMenu();
        choice = getValidatedInt("Choose an option (1-3): ");

        if (choice == 1)
        {
            int score = getValidatedScore();
            string grade = getLetterGradePlusMinus(score);
            cout << "The letter grade is " << grade << endl;
        }
        else if (choice == 2)
        {
            showScale();
        }
        else if (choice == 3)
        {
            cout << "\nGoodbye!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose 1, 2, or 3.\n";
        }

    } while (choice != 3);

    return 0;
}

/*
----------------------------------------------------
TESTED OUTPUT (example)

====================================
      Grade Calculator - Menu
====================================
1. Enter a score and get grade
2. Show grading scale
3. Exit
Choose an option (1-3): a
Invalid input. Please enter a whole number (digits only).
Choose an option (1-3): 1
Enter your numeric test score (0-100): 105
Invalid score. Please enter a value from 0 to 100.
Enter your numeric test score (0-100): 85
The letter grade is B

Choose an option (1-3): 1
Enter your numeric test score (0-100): 69
The letter grade is D+

Choose an option (1-3): 1
Enter your numeric test score (0-100): 50
The letter grade is F

Choose an option (1-3): 1
Enter your numeric test score (0-100): 90
The letter grade is A-

Choose an option (1-3): 3

Goodbye!
----------------------------------------------------
*/
