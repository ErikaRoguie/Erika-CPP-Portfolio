/*
================================================================================
    PROGRAM: UserAuthentication.cpp
    STUDENT: Erika Sanders
    COURSE:  Introduction to C++ Programming
    DATE:    March 8, 2026
    
    DESCRIPTION:
    This program simulates a user authentication and access control system
    using conditional statements. It demonstrates cybersecurity concepts
    including password validation, role-based access levels (Admin/User/Guest),
    and threat level detection (Low/Medium/High). The program validates user
    credentials and grants appropriate system access privileges based on
    the authenticated user's role.
    
    KEY FEATURES:
    - Password authentication with secure password matching
    - Role-based access control with if-else statements
    - Threat level simulation using switch statements
    - Input validation and error handling
================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Define the secure password for authentication
    string securePassword = "Cyber@123";
    string userPassword;
    
    // ========== STEP 1: USER AUTHENTICATION CHECK ==========
    // Prompt the user to enter a password
    cout << "Enter system password: ";
    cin >> userPassword;
    
    // Check if password matches the secure password
    if (userPassword == securePassword)
    {
        cout << "Access Granted" << endl;
        
        // ========== STEP 2: ACCESS LEVEL VALIDATION ==========
        string userRole;
        
        // Prompt user to enter their role
        cout << "Enter your role (Admin/User/Guest): ";
        cin >> userRole;
        
        // Use if-else statements to determine access privileges
        if (userRole == "Admin")
        {
            cout << "Privilege: Full System Access." << endl;
        }
        else if (userRole == "User")
        {
            cout << "Privilege: Limited access to files." << endl;
        }
        else if (userRole == "Guest")
        {
            cout << "Privilege: Read-Only Access." << endl;
        }
        else
        {
            // Display message for invalid role
            cout << "Invalid role entered!" << endl;
        }
        
        // ========== STEP 3: CYBER THREAT ALERT SIMULATION ==========
        int threatLevel;
        
        // Prompt user to enter threat level
        cout << "Enter threat level (1-3): ";
        cin >> threatLevel;
        
        // Use switch statement to respond to different threat levels
        switch (threatLevel)
        {
            case 1:
                // Low threat: Monitor the system
                cout << "Low Threat: Monitor the system." << endl;
                break;
                
            case 2:
                // Medium threat: Enable security protocols
                cout << "Medium Threat: Enable security protocols." << endl;
                break;
                
            case 3:
                // High threat: Immediate lockdown required
                cout << "High Threat: Immediate lockdown required!" << endl;
                break;
                
            default:
                // Invalid threat level
                cout << "Invalid threat level." << endl;
        }
    }
    else
    {
        // Access denied for incorrect password
        cout << "Access Denied" << endl;
    }
    
    return 0;
}

/*
========== TESTED OUTPUT SCENARIOS ==========

TEST SCENARIO 1: Correct password, Admin role, Threat Level 3
-----------------------------------------------------------
Enter system password: Cyber@123
Access Granted
Enter your role (Admin/User/Guest): Admin
Privilege: Full System Access.
Enter threat level (1-3): 3
High Threat: Immediate lockdown required!

TEST SCENARIO 2: Correct password, Guest role, Threat Level 1
-----------------------------------------------------------
Enter system password: Cyber@123
Access Granted
Enter your role (Admin/User/Guest): Guest
Privilege: Read-Only Access.
Enter threat level (1-3): 1
Low Threat: Monitor the system.

TEST SCENARIO 3: Incorrect password
-----------------------------------------------------------
Enter system password: WrongPass
Access Denied

TEST SCENARIO 4: Correct password, Invalid role, Threat Level 2
-----------------------------------------------------------
Enter system password: Cyber@123
Access Granted
Enter your role (Admin/User/Guest): Hacker
Invalid role entered!
Enter threat level (1-3): 2
Medium Threat: Enable security protocols.

========== CODE FEATURES ==========
- Uses if/else conditional statements for password and role validation
- Uses switch statement for threat level responses
- Includes meaningful variable names (securePassword, userPassword, userRole, threatLevel)
- Proper code formatting with comments explaining each section
- Handles all required scenarios including invalid inputs
- Follows structured program flow with clear logical separation
*/
