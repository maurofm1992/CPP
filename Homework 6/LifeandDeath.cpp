//Mauricio Da Graca
//Foundations
//06/03/2015	
//Homework 6
/*Generate a random number between 0 and 1, if this number is less than or equal to the 
death probability then predict that the user will live to the current age. If the random number is greater than the death probability, 
then increase the age by one and repeat the calculations with a new random number for the next probability value.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string> 
#include <ctime> 

//constant variables.
const int data_row = 120;
const int data_col = 3;

using namespace std;

void userInput(int &ageUser, char &sexUser);
//Post condition: sets the age and the sex of the user.
//arguments are passe by reference

void male(double& death, int& age);
//Pre-condition: the age and sex are already set
//Post-condition: the program will let the user know until what age he will live.
//arguments are passe by reference

void female(double& death, int& age);
//Pre-condition: the age and sex are already set
//Post-condition: the program will let the user know until what age she will live.
//arguments are passe by reference

int main()
{
	//declaration variables.
	ifstream doc_input;
	double input[data_row][data_col];
	int age = 0;
	double male_death, female_death;
	int i = 0;
	int j = 0;
	int user_age;
	char user_sex;
	
	//Greeting the user.
	cout << "Welcome to the Life and Death program." << endl;
	
	//Get the user age and sex.
	userInput(user_age, user_sex);

	//open file and see if it open.
	doc_input.open("LifeDeathProbability.txt");
	if (doc_input.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	
	while (!doc_input.eof())
	{
		//set the values on the file to the array variables.
		doc_input >> age >> male_death >> female_death;
		input[i][j] = age;
		input[i][j + 1] = male_death;
		input[i][j + 2] = female_death;
		i++;
		j = 0;

		//first match the age of the user.
		if (age == user_age)
		{
		
			if (user_sex == 'm')
			{
				male(male_death, age); //function call
			}
			
			else if (user_sex == 'f')
			{
				female(female_death, age); //function call
			}
		}
	}
}

void userInput(int &ageUser, char &sexUser)
{
	//prompt the user and get.
	cout << "Please enter your age: ";
	cin >> ageUser;

	while (ageUser >= 119 || ageUser <= 0)
	{
		cout << "Please enter a valid age: " << endl;
		cin >> ageUser;
	}
	cout << "\n Please enter your sex (m = male, f = female): ";
	cin >> sexUser;
	while (sexUser != 'f' && sexUser != 'm')
	{
		cout << "Please enter a valid sex: " << endl;
		cin >> sexUser;
	}
}

void male(double& death, int& age)
{
	//generate the random number
	double random;
	unsigned seed = time(0);
	srand(seed);
	random = ((double)rand() / (RAND_MAX)) + 0;

	cout << random << endl;

	while (random <= death)
	{
		cout << random << endl;
		age++;
		cout << "The age now is:" << age << endl;
		random = ((float)rand() / (RAND_MAX)) + 0;

	}

	if (random > death)
	{
		cout << "You will live until you are: " << age << endl;
		cout << "Thank you for using the program. BYE." << endl;
		exit(1);
	}
}

void female(double& death, int& age)
{
	//generate the random number.
	double random;
	unsigned seed = time(0);
	srand(seed);
	random = ((double)rand() / (RAND_MAX)) + 0;

	cout << random << endl;

	while (random <= death)
	{
		cout << random << endl;
		age++;
		cout << "The age now is:" << age << endl;
		random = ((float)rand() / (RAND_MAX)) + 0;

	}

	if (random > death)
	{
		cout << "You will live until you are: " << age << endl;
		cout << "Thank you for using the program. BYE." << endl;
		exit(1);
	}
}