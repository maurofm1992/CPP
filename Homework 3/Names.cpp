//Mauricio Da Graca
//Homework #3
//05/27/2015
//Foundations
/*This assignment will compare the user input
with the .txt file and see if there are any matches.
if there are matches the match will be shown to the user
and also will be shown the psoition of the name.
If there are no matches the program will tell the user as well.
*/


#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

void instructions();
//post condition: Explains the purpose of the program to the user

string toupper(string option);
//pre -condition: has the name already entered from the user as a parameter
//post- condition: the first letter of the word from the user puts it Upper cas.

int find_boys(string name, int boys);
//Pre-condition: The user has to input the name desire to find in the list
//Post-condition: The file with the names will be open
//The system will return if the name was found in the boys list

int find_girls(string name, int girls);
//Pre-condition: The user has to input the name desire to find in the list
//Post-condition: The file with the names will be open.
//The system will return if the name was found in the girls list


int main()
{
	string name;
	int boys = 1;
	int girls = 1;

	//call the function for instructions.
	instructions();

	//get the name from the user.
	cout << "Enter the name you would like to search for: ";
	cin >> name;
	cout << endl;

	//put the first letter to upper case.
	name = toupper(name);

	//search in the boys list.
	boys = find_boys(name, boys);
	if (boys == 0)
	{
		cout << name << " is not ranked among the top 1000 boy names." << endl;
		cout << endl;
	}
	//search in the girls list.
	girls = find_girls(name, girls);
	if (girls == 0)
	{
		cout << name << " is not ranked among the top 1000 girl names." << endl;
		cout << endl;
	}

	return 0;
}


void instructions()
{
	cout << "This program allows you to search for the rank of a name from a list of the" << endl;
	cout << "1000 most popular male and female baby names of 2012." << endl;
	cout << "******************************************************************************" << endl;
}
string toupper(string option)
{
	option[0] = toupper(option[0]);
	return option;
}

int find_boys(string name, int boys)
{
	int rank;
	string male, female;
	ifstream doc_names;

	//open the file
	doc_names.open("babynames2012.txt");
	//check if opens correctly
	if (doc_names.fail())
	{
		cout << "Output file opening failed.\n";

	}

	while (!doc_names.eof())
	{
		//set the list in the loop.
		doc_names >> rank >> male >> female;

		if (name == male)
		{
			cout << name << " is ranked " << rank << " in popularity among boys." << endl;
			cout << endl;
			return 1;
		}
		else
			boys = 0;
	}
	return boys;


	//close the file
	doc_names.close();
}

int find_girls(string name, int girls)
{
	int rank;
	string male, female;
	ifstream doc_names;

	//open the file
	doc_names.open("babynames2012.txt");
	//check if opens correctly
	if (doc_names.fail())
	{
		cout << "Output file opening failed." << endl;
	}

	//set the list in the loop.
	while (!doc_names.eof())
	{
		doc_names >> rank >> male >> female;

		if (name == female)
		{
			cout << name << " is ranked " << rank << " in popularity among girls." << endl;
			cout << endl; 
			return 1;
		}
		else
			girls = 0;
	}
	return girls;
	doc_names.close();
}
