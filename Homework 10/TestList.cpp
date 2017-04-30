//Mauricio Da Graca
//homework 5-2 
//Foundations
//06/21/2015

//Program to demonstrate use of the class template GenericList.
#include <iostream>
#include "MyList.h"
#include "MyList.cpp"
#include <string.h>
#include <cstdlib>
using namespace std;
using namespace mauriciodagraca;

int main()
{
		//ADD to the list//
	MyList<int> first_list(2);
	
	//////// ADD /////////////
	for (int i = 0; i < 5; i++)
		first_list.add(i + 1);

	cout << "Display list 1 contents" << endl;
	//display list 1 contents
	cout << "second_list = \n"
		<< first_list;

	cout << "Demonstrate the NEW add" << endl;
	first_list.add(2); // the add member function should print an error message
	first_list.add(55); // this should work fine

	////////// FIND /////////////
	cout << "Demonstrate find" << endl;
	int a, b;
	a = first_list.find(4); // exists
	b = first_list.find(34); // doesn't exist
	if (a >= 0)
		cout << "The position of 4 in the list is " << a << endl;
	else
		cout << "It is not in the list!" << endl;
	if (b >= 0)
		cout << "The position of 34 in the list is " << a << endl;
	else
		cout << "It is not in the list!" << endl;

	///////// REMOVE ////////////
	cout << "Demonstrate remove" << endl;
	for (int i = 0; i < 5; i++)
		first_list.remove(i + 1);
	// Display contents here (should only have the node with 55 in it)

	MyList<char> second_list(10);
	second_list.add('A');
	second_list.add('B');
	second_list.add('C');

	//////// ADD /////////////
	for (int i = 0; i < 5; i++)
		second_list.add('a' + i);

	cout << "Display list 2 contents" << endl;
	// write code to display list 2 contents
	cout << "second_list = \n"
		<< second_list;

	
	// MyList list3 = list2; // assignment operator
	MyList<char> third_list(10); 

	third_list = second_list;

	// cout << "Display list 3 contents" << endl;
	cout << "second_list = \n"
		<< third_list;
	// write code to display list 3 contents


	return 0;
}

