//Mauricio Da Graca
//Foundations main file
//05/27/15
/*This programm will evaluate all the grades of a student and at the end will
give the studen tthe final grade and the final letterg grade.
*/
#include "student.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string> 
using namespace std;




int main()
{
	int choice;
	string lastname, firstname;
	int quiz1;
	int quiz2;
	int m;
	int f;
	ifstream doc_input;
	ofstream doc_output;
	
	

	//Greet the user 
	cout << ("Hello this software takes all the grades of the students and gives you") << endl;
	cout << ("the final grade with the corresponding letter.") << endl;
	cout << "***************************************************************************" << endl;


	//This is an extra part on the program
	//Ask the user how many students wants to see from 1-6

	cout << "\nHow many Students final grades would you like to see?" << endl;
	cout << "(from 1-6)" << endl;
	cin >> choice;

	//declare the class and the student.
	Studentrecord student1;

	//open file and check of it opens
	doc_input.open("Input.txt");
	if (doc_input.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	//open file and check of it opens
	doc_output.open("Output.txt");
	if (doc_output.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	

	for (int i = 0; i < choice; i++)
	{ 
		doc_input >> lastname >> firstname >> quiz1 >> quiz2 >> m >> f;

		//the sey takes the arguments of the student on the file
		student1.set(lastname, firstname, quiz1, quiz2, m, f);
		student1.print();
		student1.percentage();
		student1.final_letter();
		student1.print2(doc_output);

	}
	
}

