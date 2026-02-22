/*
 TimeCalculator.cpp
 Chapter 4 - Making Decisions using conditional statements

 This program converts seconds to days, hours, or minutes.
 It asks the user to enter a number of seconds and uses
 if / else if statements to determine which unit to display.

 Author: Erika
 Date: 2026-02-22
 Compile: cl /EHsc TimeCalculator.cpp    (MSVC)
          g++ -std=c++17 -O2 TimeCalculator.cpp -o TimeCalculator.exe

 Standards:
 - Clear comments and documentation
 - Meaningful identifiers
 - Proper input validation (basic)
 - Output formatted to two decimal places
*/

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "This program will convert seconds to days, hours, or minutes." << std::endl;
    std::cout << "Enter the number of seconds (60 or more): ";

    double seconds{};
    if (!(std::cin >> seconds)) {
        std::cerr << "Input error. Exiting." << std::endl;
        return 1;
    }

    // Use fixed notation with two decimal places for output
    std::cout << std::fixed << std::setprecision(2);

    if (seconds >= 86400.0) {
        double days = seconds / 86400.0;
        std::cout << "This equals " << days << " days." << std::endl;
    }
    else if (seconds >= 3600.0) {
        double hours = seconds / 3600.0;
        std::cout << "This equals " << hours << " hours." << std::endl;
    }
    else if (seconds >= 60.0) {
        double minutes = seconds / 60.0;
        std::cout << "This equals " << minutes << " minutes." << std::endl;
    }
    else if (seconds >= 0.0) {
        std::cout << "This is less than one minute." << std::endl;
    }
    else {
        std::cout << "Invalid input: negative seconds." << std::endl;
    }

    return 0;
}

/*
 TEST OUTPUT (sample runs):

 RUN 1
 This program will convert seconds to days, hours, or minutes.
 Enter the number of seconds (60 or more): 95000
 This equals 1.10 days.

 RUN 2
 This program will convert seconds to days, hours, or minutes.
 Enter the number of seconds (60 or more): 3000
 This equals 50.00 minutes.

 RUN 3
 This program will convert seconds to days, hours, or minutes.
 Enter the number of seconds (60 or more): 45
 This is less than one minute.

 Additional tests:
 Enter -5  -> Invalid input: negative seconds.
 Enter abc -> Input error. Exiting.
*/
