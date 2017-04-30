/*Name: Mauricio Da Graca                          Z#: 23333810
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 09/02/2015               Due Time: 5:30pm
Total Points: 100
Assignment 3: Date program

Description: This programm is made to test the implements of a class.
			 Constructors, mutators, operator overloading. 

*********************************************************************************************/
#include <iostream>
#include <string>
#include "date.h"

using namespace std;


int main()
{

	Date myDate;
	myDate.display(cout);
	Date yourDate(12,31,1957);
	yourDate.display(cout);
	Date test1Date(15,1,1962); //should generate error message that bad month
	cout << endl;
	Date test2Date(2, 29, 1956); //ok, should say leep year
	test2Date.display(cout);
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	cout << endl;
	Date test4Date(12,31,0000); //should generate error message that bad year
	cout << endl;
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year
	cout << endl;

	cout << yourDate.getMonth() << endl; 
	cout << yourDate.getDay() << endl;
	cout << yourDate.getYear() << endl << endl;
	
	// sets the month and the day to an specific value.
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << "test2Date: " << test2Date << "yourDate: " << yourDate << endl;
	

	return 0;
}
