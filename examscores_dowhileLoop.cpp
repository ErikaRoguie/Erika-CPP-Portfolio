/*
This program averages 3 test scores. It uses a do-while loop that allows the 
code to repeat as many times as the user wishes.

*/
#include <iostream>
using namespace std;

int main()
{
	int score1, score2, score3;
	double average;
	char again;

	do 
	{
		//Get 3 test scores
		cout << "\n Enter 3 scores and I will average them: ";
		cin >> score1 >> score2 >> score3;

		//Calculate and display the average
		average = (score1 + score2 + score3)/3.0;
		cout << "The average is " << average << "\n\n";

		//Do you want to try again
		cout << "Do you want to average another set?(Y/N)";
		cin >> again;


	}while(again == 'Y' || again == 'y');


}