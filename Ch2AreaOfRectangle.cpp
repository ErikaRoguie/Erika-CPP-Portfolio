/* 
Name: Erika Sanders
CSC100AA/CIS162AB
Ch2: C++ program to find the area of a rectangle
*/
# include <iostream>
using namespace std;
int main()
{

	//Define variables. Choose the most appropriate datatype for each variable
	//Assign values to the variables
	int length = 5, width = 2;
	int areaR = 0;


	//Calculate the area of the Rectangle
	areaR = length * width;

	//Display the output to the console
//cout << "Area of the Rectangle " << areaR << endl;
	cout << "Area of the Rectangle for length: " << length <<
		" and width: " << width << " is: " << areaR << endl;

	system("pause");
	return 0;
}

