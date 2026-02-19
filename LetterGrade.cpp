/*
----------------------------------------------------
Program Name: LetterGrade.cpp
Author: Erika Sanders
Date Written: February 15, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program assigns a letter grade (A, B, C, D, F)
based on a numeric test score entered by the user.
A trailing else sets a flag for invalid values.
----------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int testScore;
    char letterGrade;
    bool validScore = true;

    // Prompt user for input
    cout << "Enter your numeric test score: ";
    cin >> testScore;

    // Determine letter grade using if/else if
    if (testScore >= 90 && testScore <= 100)
        letterGrade = 'A';
    else if (testScore >= 80 && testScore < 90)
        letterGrade = 'B';
    else if (testScore >= 70 && testScore < 80)
        letterGrade = 'C';
    else if (testScore >= 60 && testScore < 70)
        letterGrade = 'D';
    else if (testScore >= 0 && testScore < 60)
        letterGrade = 'F';
    else
        validScore = false;   // Invalid value flag

    // Display result
    if (validScore)
        cout << "The letter grade is " << letterGrade << endl;
    else
        cout << "Invalid test score entered." << endl;

    return 0;
}

/*
----------------------------------------------------
TESTED OUTPUT

Test1:
Enter your numeric test score: 85
The letter grade is B

Test2:
Enter your numeric test score: 69
The letter grade is D

Test3:
Enter your numeric test score: 50
The letter grade is F

Test4:
Enter your numeric test score: 90
The letter grade is A

----------------------------------------------------
*/
