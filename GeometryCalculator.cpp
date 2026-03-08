// GeometryCalculator.cpp
// Author: Erika
// Description: Displays a menu to calculate areas of geometric shapes
//              based on user input. This program demonstrates use of
//              switch statements, input validation, and simple arithmetic.
// Standards: Follows the Standards for Programming Assignments and the
//            C++ Coding Guideline.

#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14159;
    int choice;

    // display menu
    cout << "***Geometry Calculator***" << endl;
    cout << "1. Calculate the area of a Circle" << endl;
    cout << "2. Calculate the area of a Rectangle" << endl;
    cout << "3. Calculate the area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // validate menu choice
    if (choice < 1 || choice > 4) {
        cout << "You may only enter 1, 2, 3, or 4." << endl;
        cout << "Thanks for using the Geometry Calculator!" << endl;
        return 0;
    }

    switch (choice) {
    case 1: {
        double radius;
        cout << "Enter the circle's radius: ";
        cin >> radius;
        if (radius <= 0) {
            cout << "Only positive values are accepted for radius." << endl;
        } else {
            double area = PI * radius * radius;
            cout << "The area is " << area << endl;
        }
        break;
    }
    case 2: {
        double length, width;
        cout << "Enter the rectangle's length: ";
        cin >> length;
        cout << "Enter the rectangle's width: ";
        cin >> width;
        if (length <= 0) {
            cout << "Only positive values are accepted for length." << endl;
        } else if (width <= 0) {
            cout << "Only positive values are accepted for width." << endl;
        } else {
            double area = length * width;
            cout << "The area is " << area << endl;
        }
        break;
    }
    case 3: {
        double base, height;
        cout << "Enter the length of the base: ";
        cin >> base;
        cout << "Enter the triangle's height: ";
        cin >> height;
        if (base <= 0) {
            cout << "Only positive values are accepted for base." << endl;
        } else if (height <= 0) {
            cout << "Only positive values are accepted for height." << endl;
        } else {
            double area = 0.5 * base * height;
            cout << "The area is " << area << endl;
        }
        break;
    }
    case 4:
        cout << "Quitting program now." << endl;
        break;
    }

    cout << "Thanks for using the Geometry Calculator!" << endl;
    return 0;
}

// Sample test output
/*
***Geometry Calculator***
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 1
Enter the circle's radius: 3.7
The area is 43.0084
Thanks for using the Geometry Calculator!

***Geometry Calculator***
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 2
Enter the rectangle's length: 5.5
Enter the rectangle's width: 3
The area is 16.5
Thanks for using the Geometry Calculator!

***Geometry Calculator***
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 4
Quitting program now.
Thanks for using the Geometry Calculator!

***Geometry Calculator***
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 9
You may only enter 1, 2, 3, or 4.
Thanks for using the Geometry Calculator!

***Geometry Calculator***
1. Calculate the area of a Circle
2. Calculate the area of a Rectangle
3. Calculate the area of a Triangle
4. Quit
Enter your choice (1-4): 3
Enter the length of the base: -6.2
Enter the triangle's height: 4
Only positive values are accepted for base.
Thanks for using the Geometry Calculator!
*/