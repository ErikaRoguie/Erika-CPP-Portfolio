/***************************************************************
   Program Id: Salary.cpp   
   Author : Erika Sanders
   Date : 02/26/2026
   Compile: cl /EHsc Salary.cpp    (MSVC)
            g++ -std=c++17 -O2 Salary.cpp -o Salary.exe  
   Class: CSC100 and CIS162AB
   
   Description:
		Demonstrates : Using if..else. Statements
		Demonstrates : Using switch statement.
		Demonstrates : bool variable
		Review : generating random numbers


   Computes the raise and new salary for an employee.

     The input to the program includes the current annual salary
     for the employee and a number indicating the performance
       rating for the employee.  The program computes the raise   and new salary for the employee.  The raise is based on the
       following performance ratings:


  ***************************************************************/

#include <iostream>  //needed for cout and cin
#include <iomanip>   //needed for formatting 
#include <cstdlib>   // needed for rand
#include <ctime>     // needed for time 
#include <string>  

using namespace std;

int main ()
{
      double currentSalary = 0.0;  // current annual salary
      int rating = 0;              // performance rating
      double raise = 0.0;          // dollar amount of the raise
 
	   
      // Get the current salary and performance rating
      cout << "Enter the current annual salary: ";
      cin >> currentSalary ;
      cout << "Enter the performance rating: \n";
      
      cout << "1=excellent, 2=good, and 3=poor.  Rating is : ";
      cin >> rating ;

      // Compute the raise -- Use if ... else ...

      if( rating == 1)
      {
	   raise = currentSalary * 0.06;
      }
	
      else if (rating == 2)
      {
	   raise = currentSalary * 0.04;
      }
	  
      else if (rating == 3)
      {
	  raise = currentSalary * 0.015;
      }

     else
     {
	  cout << "Invalid rating. No raise calculated" << endl;
	  raise = 0.0;
      }
     // now write as switch statement -Fill in the code.
     {
        double raiseSwitch = 0.0;
        switch (rating)
        {
           case 1:
              raiseSwitch = currentSalary * 0.06;
              break;
           case 2:
              raiseSwitch = currentSalary * 0.04;
              break;
           case 3:
              raiseSwitch = currentSalary * 0.015;
              break;
           default:
              // invalid rating; leave raiseSwitch as 0.0
              break;
        }
        // Use the switch-calculated raise for output (demonstration)
        raise = raiseSwitch;
     }

      // Print the results
	  cout << fixed << showpoint << setprecision(2);
	  cout << "Amount of your current salary:\t$" << setw(9) <<currentSalary << endl;
	  cout << "Amount of your raise: \t\t$" << setw(9) << raise << endl;
      cout << "Your new expected salary: \t$" << setw(9) << (currentSalary + raise) <<endl;


   return 0;
}

/*
 TEST OUTPUT (sample runs):

 RUN 1
 Enter the current annual salary: 50000
 Enter the performance rating:
 1=excellent, 2=good, and 3=poor.  Rating is : 1
 Amount of your current salary:	$50000.00
 Amount of your raise: 		$3000.00
 Your new expected salary: 	$53000.00

 RUN 2
 Enter the current annual salary: 75000
 Enter the performance rating:
 1=excellent, 2=good, and 3=poor.  Rating is : 2
 Amount of your current salary:	$75000.00
 Amount of your raise: 		$3000.00
 Your new expected salary: 	$78000.00

 RUN 3
 Enter the current annual salary: 60000
 Enter the performance rating:
 1=excellent, 2=good, and 3=poor.  Rating is : 3
 Amount of your current salary:	$60000.00
 Amount of your raise: 		$900.00
 Your new expected salary: 	$60900.00

 Additional tests:
 Enter invalid rating (e.g., 4 or -1) -> Invalid rating. No raise calculated; raise = $0.00; new salary = current salary.
*/