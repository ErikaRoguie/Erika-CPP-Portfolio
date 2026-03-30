/*
----------------------------------------------------
Program Name: MathTutor.cpp
Author: Erika Sanders
Date Written: February 16, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program acts as a math tutor for a young student.
It generates two random integers between 10 and 49,
displays them as an addition problem, and prompts
the user for an answer. The program determines whether
the answer is correct and displays an appropriate message.
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>   // for setw
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main()
{
    // Seed random number generator
    srand(time(0));

    // Generate two random numbers between 10 and 49
    int number1 = rand() % 40 + 10;  // 10–49
    int number2 = rand() % 40 + 10;  // 10–49

    int studentAnswer;
    int correctAnswer = number1 + number2;

    // Display formatted math problem
    cout << "Math Flash Card\n";
    cout << "---------------\n";

    cout << setw(4) << number1 << endl;
    cout << "+ " << setw(2) << number2 << endl;
    cout << " -----" << endl;

    // Prompt user for answer
    cout << " ";
    cin >> studentAnswer;

    // Check answer
    if (studentAnswer == correctAnswer)
    {
        cout << "Congratulations! That's correct." << endl;
    }
    else
    {
        cout << "Sorry, the correct answer is "
            << correctAnswer << endl;
    }

    return 0;
}

/*
----------------------------------------------------
TEST OUTPUT – Correct Guess Example

Math Flash Card
---------------
  32
+ 11
 -----
  43
Congratulations! That's correct.

----------------------------------------------------
TEST OUTPUT – Incorrect Guess Example

Math Flash Card
---------------
  49
+ 32
 -----
  71
Sorry, the correct answer is 81

----------------------------------------------------
*/

