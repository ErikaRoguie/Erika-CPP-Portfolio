/*
----------------------------------------------------
Program Name: Exam.cpp
Author: Erika Sanders
Date Written: February 14, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program calculates the percentage of correct
answers a student received on a test. It uses
getline to read the student's full name, prevents
integer division errors using type casting, and
formats the output to one decimal place.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>   // for fixed, setprecision
#include <string>    // for string and getline

using namespace std;

int main()
{
    // Variable declarations
    string studentFullName;
    int numberOfQuestions;
    int numberCorrect;
    double percentageCorrect = 0.0;

    // Prompt for student's full name
    cout << "Enter student's first and last name: ";
    getline(cin, studentFullName);

    // Prompt for test information
    cout << "Number of questions on the test: ";
    cin >> numberOfQuestions;

    cout << "Number of answers the student got correct: ";
    cin >> numberCorrect;

    // Prevent division by zero
    if (numberOfQuestions > 0)
    {
        // Type casting to avoid int/int division
        percentageCorrect = (static_cast<double>(numberCorrect) 
                            / numberOfQuestions) * 100;
    }
    else
    {
        cout << "Number of questions must be greater than zero.\n";
        return 1;
    }

    // Format output to 1 decimal place
    cout << fixed << setprecision(1);

    // Display results
    cout << studentFullName << "\t" 
         << percentageCorrect << "%" << endl;

    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT

Enter student's first and last name: John Smith
Number of questions on the test: 40
Number of answers the student got correct: 31
John Smith    77.5%

----------------------------------------------------
*/
