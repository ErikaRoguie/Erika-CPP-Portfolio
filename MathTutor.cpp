/*
----------------------------------------------------
Program Name: MathTutor.cpp
Author: Erika Sanders
Date Written: February 16, 2026
Course: CSC100AA / CIS162AB
Brief Description:
This program is a math tutor for young students.
It generates random problems using addition, subtraction,
and multiplication with numbers between 10 and 49.

Features:
- Menu to choose operation mode (Add/Subtract/Multiply/Mixed)
- Multiple questions per quiz
- Input validation (rejects non-numeric answers)
- Score tracking (correct/incorrect + percentage)
- Replay option
----------------------------------------------------
*/

#include <iostream>
#include <iomanip>    // setw, setprecision, fixed
#include <cstdlib>    // rand, srand
#include <ctime>      // time
#include <limits>     // numeric_limits

using namespace std;

// Returns a validated integer (rejects letters/symbols)
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
            cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

// Returns a validated menu choice within a range
int getValidatedChoice(const string& prompt, int minChoice, int maxChoice)
{
    while (true)
    {
        int choice = getValidatedInt(prompt);
        if (choice < minChoice || choice > maxChoice)
        {
            cout << "Invalid choice. Please enter " << minChoice
                 << " through " << maxChoice << ".\n";
            continue;
        }
        return choice;
    }
}

// Generates a random integer between low and high inclusive
int randInRange(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

// Displays a single math flash card and returns the student's validated answer
int askFlashCard(int top, int bottom, char opSymbol)
{
    cout << "Math Flash Card\n";
    cout << "---------------\n";
    cout << setw(4) << top << endl;
    cout << opSymbol << setw(3) << bottom << endl;
    cout << " -----\n";

    // Prompt for answer (validated)
    int answer = getValidatedInt(" ");
    return answer;
}

int main()
{
    // Seed random number generator (seed once at program start)
    srand(static_cast<unsigned int>(time(0)));

    const int MIN_NUM = 10;
    const int MAX_NUM = 49;

    char playAgain;

    do
    {
        cout << "\n====================================\n";
        cout << "         Math Tutor - Menu\n";
        cout << "====================================\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Mixed (random +, -, *)\n";

        int mode = getValidatedChoice("Choose a mode (1-4): ", 1, 4);
        int numQuestions = getValidatedChoice("How many questions (1-20): ", 1, 20);

        int correctCount = 0;

        for (int q = 1; q <= numQuestions; q++)
        {
            // Pick operation symbol
            char opSymbol;
            if (mode == 1) opSymbol = '+';
            else if (mode == 2) opSymbol = '-';
            else if (mode == 3) opSymbol = '*';
            else
            {
                int r = randInRange(1, 3);       // 1..3
                opSymbol = (r == 1) ? '+' : (r == 2) ? '-' : '*';
            }

            // Generate numbers in range 10..49
            int a = randInRange(MIN_NUM, MAX_NUM);
            int b = randInRange(MIN_NUM, MAX_NUM);

            // For subtraction, ensure non-negative result (larger on top)
            if (opSymbol == '-' && b > a)
            {
                int temp = a;
                a = b;
                b = temp;
            }

            // Compute correct answer
            int correctAnswer;
            if (opSymbol == '+') correctAnswer = a + b;
            else if (opSymbol == '-') correctAnswer = a - b;
            else correctAnswer = a * b;

            cout << "\nQuestion " << q << " of " << numQuestions << "\n";
            int studentAnswer = askFlashCard(a, b, opSymbol);

            // Check and score
            if (studentAnswer == correctAnswer)
            {
                cout << "Congratulations! That's correct.\n";
                correctCount++;
            }
            else
            {
                cout << "Sorry, the correct answer is " << correctAnswer << "\n";
            }
        }

        // Results summary
        int incorrectCount = numQuestions - correctCount;
        double percent = (static_cast<double>(correctCount) / numQuestions) * 100.0;

        cout << "\n====================================\n";
        cout << "              Quiz Results\n";
        cout << "====================================\n";
        cout << "Correct:   " << correctCount << endl;
        cout << "Incorrect: " << incorrectCount << endl;
        cout << fixed << setprecision(1);
        cout << "Score:     " << percent << "%\n";

        // Replay option
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for practicing! Goodbye!\n";
    return 0;
}

/*
----------------------------------------------------
TEST OUTPUT (example - random numbers will vary)

====================================
         Math Tutor - Menu
====================================
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Mixed (random +, -, *)
Choose a mode (1-4): 1
How many questions (1-20): 2

Question 1 of 2
Math Flash Card
---------------
  32
+ 11
 -----
 43
Congratulations! That's correct.

Question 2 of 2
Math Flash Card
---------------
  49
+ 32
 -----
 71
Sorry, the correct answer is 81

====================================
              Quiz Results
====================================
Correct:   1
Incorrect: 1
Score:     50.0%

Would you like to play again? (y/n): n

Thanks for practicing! Goodbye!
----------------------------------------------------
*/

