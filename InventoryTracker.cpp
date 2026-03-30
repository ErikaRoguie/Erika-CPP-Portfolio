// InventoryTracker.cpp
// Student Name: Erika Sanders
// Course: CSC100 and CIS162AB
// Date: 03/24/2026
// Description: Real-time inventory tracker using sentinel-controlled loop and accumulator.

#include <iostream>
#include <limits>

using namespace std;

int main() {
    const int SENTINEL = 999;
    int initialInventory = -1;
    int currentInventory = 0;
    int transaction = 0;
    int netChange = 0;
    int transactionCount = 0;

    // Prompt for initial inventory and validate
    while (true) {
        cout << "Enter initial inventory count (non-negative): ";
        if (!(cin >> initialInventory)) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (initialInventory < 0) {
            cout << "Inventory cannot be negative. Try again.\n";
            continue;
        }
        break;
    }

    currentInventory = initialInventory;
    netChange = 0;
    transactionCount = 0;

    // Sentinel-controlled transaction loop
    while (true) {
        cout << "Enter transaction amount (positive to add, negative to remove, 999 to exit): ";

        if (!(cin >> transaction)) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (transaction == SENTINEL) {
            break;
        }

        // Check removal does not go negative
        if (transaction < 0 && currentInventory + transaction < 0) {
            cout << "Cannot remove " << -transaction << " items; inventory would go negative. Try again.\n";
            continue;
        }

        currentInventory += transaction;
        netChange += transaction;
        transactionCount++;

        cout << "Transaction processed. Current inventory: " << currentInventory << "\n";
    }

    // Summary output
    cout << "\nInventory Summary:\n";
    cout << "---------------------------\n";
    cout << "Total transactions: " << transactionCount << "\n";
    cout << "Net inventory change: " << netChange << "\n";
    cout << "Final inventory: " << currentInventory << "\n";

    if (netChange > 0) {
        cout << "Inventory increased by " << netChange << " items.\n";
    } else if (netChange < 0) {
        cout << "Inventory decreased by " << -netChange << " items.\n";
    } else {
        cout << "Inventory remained unchanged.\n";
    }

    return 0;
}

//* Sample Output:
// Enter initial inventory count (non-negative): 100        
// Enter transaction amount (positive to add, negative to remove, 999 to exit): -20
// Transaction processed. Current inventory: 80
// Enter transaction amount (positive to add, negative to remove, 999 to exit):
// 50
// Transaction processed. Current inventory: 130
// Enter transaction amount (positive to add, negative to remove, 999 to exit): -
// 150
// Cannot remove 150 items; inventory would go negative. Try again.
// Enter transaction amount (positive to add, negative to remove, 999 to exit): -
// 30
// Transaction processed. Current inventory: 100
// Enter transaction amount (positive to add, negative to remove, 999 to exit): 999
// Inventory Summary:
// ---------------------------
// Total transactions: 3
// Net inventory change: 0
// Final inventory: 100
// Inventory remained unchanged.
