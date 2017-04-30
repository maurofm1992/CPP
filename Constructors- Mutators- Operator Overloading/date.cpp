//*********************************************************************************************
//*********************************************************************************************
//	D A T E  . C P P

#ifndef DATE_H
#define DATE_H
#include "date.h"
#include <iomanip>
#include <iostream>

#endif

using namespace std;

//*************************************************************************************
//Name:  Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class
//
//*************************************************************************************
Date::Date() : myMonth(01), myDay(01), myYear(0001)
{
	cout << "Default constructor is called" << endl; 
}


//*************************************************************************************
//Name:  Date
//Precondition: m , d, and y are inital values for the data memebers, they have to 
//		preserve the class invariant.
//Postcondition: Data memebers myMonth, myDay, and myYear have been
//		initialized to m , d , y respectively. Also sets the parameters for the each 
//		month, year and day.
//Description:  This is an explicit-value constructor that will be called when an 
//		an object is declared and is not empty. also, it will check if all the parameters
//		for the date are valid.
//		
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called" << endl;
	if (m <= 12 && d <= 31 && y <= 2015 && y > 0)
	{
		myMonth = m;
		myDay = d;
		myYear = y;
	}
	//On this part the constructors checks for all the parameters.
	//checks for a valid month.
	if (m == 0 || m > 12)
		cout << setfill('0') << setw(2) << m << " is not a correct month" << endl;

	//checks for a valid day
	if (d > 31)
		cout << d << " is not a correct day" << endl;

	//checks for a valid year
	if (y <= 0)
		cout << setfill('0') << setw(4) << y << " is not a correct year" << endl;

	//checks for a leap year.
	if (y % 4 == 0 && m == 2 && d == 29)
		cout << "ok, this is a leap year."<< endl;

	//checks for the days in the month of february
	if (m == 2 && d > 29)
		cout << "day = " << d << " is incorrect" << endl;

}

//*************************************************************************************
//Name:  Display
//Precondition: The ostream is open.
//Postcondition: The date object has been inserted into ostream out.
//Description: The Date has some parameters in the days months and years 
//		in the way they should be displayed for the user.
//
//*************************************************************************************
void Date::display(ostream & out) 
{
	out << setfill ('0') << setw(2) << myMonth 
		<< "/" << setfill('0') << setw(2) << myDay 
		<< "/" << setfill('0') << setw(4) << myYear;
	out << "\n" << endl; 
}

//*************************************************************************************
//Name:  getMonth
//Precondition: None
//Postcondition: Value stored in myMonth is returned.
//
//*************************************************************************************	
int Date::getMonth()
{
	return myMonth;
}

//*************************************************************************************
//Name:  getDay
//Precondition: None
//Postcondition: Value stored in myDay is returned. 
//
//*************************************************************************************
int Date::getDay()
{
	return myDay;
}

//*************************************************************************************
//Name:  getYear
//Precondition: None
//Postcondition: Value stored in myYear is returned. 
//
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: m <= 12
//Postcondition: data memeber m is set to be equal to myMonth.
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	if (m <= 12)
	{
		myMonth = m;
	}
}

//*************************************************************************************
//Name:  setDay
//Precondition: d <=31 && d != 0
//Postcondition: data memeber d is set to be equal to myDay.
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (d <= 31 && d != 0)
	{
		myDay = d;
	}
}

//*************************************************************************************
//Name:  getYear
//Precondition: y <= 12
//Postcondition:  data memeber y is set to be equal to myYear.
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	if (y != 0)
	{
		myYear = y;
	}

}
ostream & operator<<(ostream & out, Date & dateObj)
{
	out << dateObj.myMonth << '/' << dateObj.myDay
		<< '/' << dateObj.myYear << endl;
	return out;
}

