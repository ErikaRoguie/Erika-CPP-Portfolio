// Factorial.cpp
// Author: Erika Sanders
 //Date : 3/13/2026
//   Class : CSC100 and CIS162AB
// Description: Prompts the user for a value between 1 and 10 (0 to quit), validates the input,
//              computes the factorial of the value when valid, and repeats until the user enters 0.
// Standards: All logic resides in main() per assignment requirements.

#include <iostream>
using namespace std;

int main()
{
    int value;

    cout << "Calculating a Factorial" << endl;
    cout << "Enter a value between 1 and 10. (0 to quit): ";
    cin >> value;

    while (value != 0) {
        while (value < 1 || value > 10) {
            cout << "The value is out of range." << endl;
            cout << "Please re-enter a value between 1 and 10. (0 to quit): ";
            cin >> value;
            if (value == 0) {
                break;
            }
        }

        if (value == 0) {
            break;
        }

        long long factorial = 1;
        for (int i = 1; i <= value; ++i) {
            factorial *= i;
        }

        cout << "------------------" << endl;
        cout << value << "! = " << factorial << endl;

        cout << "Enter a value between 1 and 10. (0 to quit): ";
        cin >> value;
    }

    cout << "Goodbye!" << endl;
    return 0;
}

// Sample Output:
// Calculating a FactorialCalculating a Factorial
//Enter a value between 1 and 10. (0 to quit): 4
------------------
//4! = 24
//Enter a value between 1 and 10. (0 to quit): 7
------------------
//7! = 5040
//Enter a value between 1 and 10. (0 to quit): 8
------------------
//8! = 40320
//Enter a value between 1 and 10. (0 to quit): 23
//The value is out of range.
//Please re-enter a value between 1 and 10. (0 to quit): 0
//Goodbye!