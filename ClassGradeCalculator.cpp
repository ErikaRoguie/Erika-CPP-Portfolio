/*
----------------------------------------------------
Program Name: ClassGradeCalculator.cpp
Author: Erika Sanders
Date Written: February 14, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This menu-driven program calculates individual test
percentages and letter grades for multiple students.
It also computes class statistics: mean (average),
minimum score, and maximum score (with student names).
Includes full input validation, getline for names,
and formatted aligned output using setw.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>     // fixed, setprecision, setw
#include <string>      // string, getline
#include <limits>      // numeric_limits
#include <vector>      // vector

using namespace std;

// -------------------- Validation Helpers --------------------

string getValidatedFullName(const string& prompt)
{
    string name;

    while (true)
    {
        cout << prompt;
        getline(cin, name);

        bool hasNonSpace = false;
        for (char ch : name)
        {
            if (ch != ' ' && ch != '\t')
            {
                hasNonSpace = true;
                break;
            }
        }

        if (hasNonSpace)
            return name;

        cout << "Invalid input. Please enter a first and last name (not blank).\n";
    }
}

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

// -------------------- Grade Helpers --------------------

char getLetterGrade(double percent)
{
    if (percent >= 90.0) return 'A';
    if (percent >= 80.0) return 'B';
    if (percent >= 70.0) return 'C';
    if (percent >= 60.0) return 'D';
    return 'F';
}

string getPassFail(double percent)
{
    return (percent >= 60.0) ? "PASS" : "FAIL";
}

// -------------------- Data Structure --------------------

struct StudentResult
{
    string fullName;
    int questions;
    int correct;
    double percent;
    char letter;
    string status;
};

// -------------------- Display Helpers --------------------

void printStudentTable(const vector<StudentResult>& results)
{
    cout << "\n----------------------------------------\n";
    cout << "Class Results (All Students)\n";
    cout << "----------------------------------------\n";

    cout << left
         << setw(22) << "Name"
         << setw(10) << "Correct"
         << setw(12) << "Questions"
         << setw(12) << "Percent"
         << setw(8)  << "Grade"
         << setw(8)  << "Status"
         << endl;

    cout << string(72, '-') << endl;

    for (const auto& s : results)
    {
        cout << left
             << setw(22) << s.fullName.substr(0, 21)  // keep table neat
             << setw(10) << s.correct
             << setw(12) << s.questions
             << setw(12) << (to_string(s.percent).substr(0, 5) + "%") // simple trim
             << setw(8)  << s.letter
             << setw(8)  << s.status
             << endl;
    }
}

void computeAndPrintStats(const vector<StudentResult>& results)
{
    if (results.empty())
    {
        cout << "\nNo student data available. Please add students first.\n";
        return;
    }

    double sum = 0.0;

    double minPercent = results[0].percent;
    double maxPercent = results[0].percent;
    string minName = results[0].fullName;
    string maxName = results[0].fullName;

    for (const auto& s : results)
    {
        sum += s.percent;

        if (s.percent < minPercent)
        {
            minPercent = s.percent;
            minName = s.fullName;
        }

        if (s.percent > maxPercent)
        {
            maxPercent = s.percent;
            maxName = s.fullName;
        }
    }

    double mean = sum / results.size();

    cout << "\n----------------------------------------\n";
    cout << "Class Statistics\n";
    cout << "----------------------------------------\n";

    cout << fixed << setprecision(1);

    cout << setw(20) << left << "Class Mean:"
         << setw(6)  << right << mean << "%\n";

    cout << setw(20) << left << "Minimum:"
         << setw(6)  << right << minPercent << "%  (" << minName << ")\n";

    cout << setw(20) << left << "Maximum:"
         << setw(6)  << right << maxPercent << "%  (" << maxName << ")\n";
}

// -------------------- Main Program --------------------

int main()
{
    cout << fixed << setprecision(1);

    vector<StudentResult> results;

    int choice;
    do
    {
        cout << "\n========================================\n";
        cout << "     Class Grade Calculator - Menu\n";
        cout << "========================================\n";
        cout << "1. Add a student result\n";
        cout << "2. View all student results\n";
        cout << "3. View class statistics (mean/min/max)\n";
        cout << "4. Reset (clear all data)\n";
        cout << "5. Exit\n";

        choice = getValidatedIntInRange("Choose an option (1-5): ", 1, 5);

        if (choice == 1)
        {
            StudentResult s;

            s.fullName = getValidatedFullName("\nEnter student's first and last name: ");

            s.questions = getValidatedIntInRange("Number of questions on the test: ", 1, 500);
            s.correct = getValidatedIntInRange("Number of answers correct: ", 0, s.questions);

            // Avoid int/int division with type casting
            s.percent = (static_cast<double>(s.correct) / s.questions) * 100.0;
            s.letter = getLetterGrade(s.percent);
            s.status = getPassFail(s.percent);

            results.push_back(s);

            cout << "\nSaved: " << s.fullName << "  (" << s.percent << "%, "
                 << s.letter << ", " << s.status << ")\n";
        }
        else if (choice == 2)
        {
            if (results.empty())
                cout << "\nNo student data available. Please add students first.\n";
            else
                printStudentTable(results);
        }
        else if (choice == 3)
        {
            computeAndPrintStats(results);
        }
        else if (choice == 4)
        {
            results.clear();
            cout << "\nAll class data has been cleared.\n";
        }

    } while (choice != 5);

    cout << "\nGoodbye!\n";
    return 0;
}

/*
----------------------------------------------------
SAMPLE RUN OUTPUT (example)

========================================
     Class Grade Calculator - Menu
========================================
1. Add a student result
2. View all student results
3. View class statistics (mean/min/max)
4. Reset (clear all data)
5. Exit
Choose an option (1-5): 1

Enter student's first and last name: John Smith
Number of questions on the test: 40
Number of answers correct: 31

Saved: John Smith  (77.5%, C, PASS)

Choose an option (1-5): 1

Enter student's first and last name: Mary Joe
Number of questions on the test: 20
Number of answers correct: 19

Saved: Mary Joe  (95.0%, A, PASS)

Choose an option (1-5): 1

Enter student's first and last name: Alex Lee
Number of questions on the test: 10
Number of answers correct: 4

Saved: Alex Lee  (40.0%, F, FAIL)

Choose an option (1-5): 3

----------------------------------------
Class Statistics
----------------------------------------
Class Mean:            70.8%
Minimum:              40.0%  (Alex Lee)
Maximum:              95.0%  (Mary Joe)

Choose an option (1-5): 5

Goodbye!
----------------------------------------------------
*/
