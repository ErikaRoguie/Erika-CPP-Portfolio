// ****************************************************************
//   Program Name :  LoopAndCount.cpp
//   Date : 3/11/2026
//   Author:Eika Sanders
//   Class : CSC100 and CIS162AB
//   Description : Looping and Counting Activity 
//   Use a while loop to print many messages declaring your
//   love for C++
// ****************************************************************

#include <iostream>
#include <string>
using namespace std;

void runWhile(int limit) {
    int count = 1;
    int sum = 0;
    cout << "\n-- While loop output --\n";
    while (count <= limit) {
        cout << count << " Coding like poetry should be short and concise." << endl;
        sum += count;
        count++;
    }
    cout << "Message was printed " << limit << " times." << endl;
    cout << "The sum of the numbers from 1 to " << limit << " is " << sum << "." << endl;
}

void runDoWhile(int limit) {
    int count = 1;
    int sum = 0;
    cout << "\n-- Do/while loop output --\n";
    if (limit > 0) {
        do {
            cout << count << " Coding like poetry should be short and concise." << endl;
            sum += count;
            count++;
        } while (count <= limit);
    }
    cout << "Message was printed " << limit << " times." << endl;
    cout << "The sum of the numbers from 1 to " << limit << " is " << sum << "." << endl;
}

void runFor(int limit) {
    int sum = 0;
    cout << "\n-- For loop output --\n";
    for (int count = 1; count <= limit; ++count) {
        cout << count << " Coding like poetry should be short and concise." << endl;
        sum += count;
    }
    cout << "Message was printed " << limit << " times." << endl;
    cout << "The sum of the numbers from 1 to " << limit << " is " << sum << "." << endl;
}

int main() {
    int limit = 0;
    cout << "How many times do you want to print the message? ";
    cin >> limit;

    runWhile(limit);
    runDoWhile(limit);
    runFor(limit);

    return 0;
}
