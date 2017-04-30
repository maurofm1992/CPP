//Mauricio Da Graca
//Homework #1

//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//Function definitions:
//This function displays how the game is played.
void instructions();

//This function is going to get the choice from the user
char Choice( );

//This function compares the decision of the user with the one of the computer
void Winner(char user, int comp);

using namespace std;

int main()
{
	char final_decision;
	char again = 'y';
	int rock = 1;
	int paper = 2;
	int scissors = 3;
	//Call the function for the instructions
	instructions();

	while (again == 'y')
	{
		
		unsigned seed = time(0);
		srand(seed);
		int compselect = (rand() % 3) + 1;
		//Call the function to get the decision from the user.
		final_decision = Choice();
		
		//Show the choice to the user.
		cout << "\nYour choice was: " << final_decision << endl;

		//Call the function to compare the decisions.
		Winner(final_decision, compselect);
		
		cout << "--------------------------------------------------------" << endl;
		cout << "\nWould you like to play again?" << endl;
		cout << "Yes = y" << endl;
		cout << "No = n" << endl;
		cin >> again;

	}

	cout << "Thanks for playing. Good Bye" << endl;
	return 0;
}

void instructions()
{
	//Displays the instructions for the user.
	cout << "Welcome to the Rock, Paper, Scissors game." << endl;
	cout << "The rules are simple: " << endl;
	cout << "1. Rock beats Scissors." << endl;
	cout << "2. Paper beats Rock." << endl;
	cout << "3. Scissors beats Paper." << endl;
	cout << "It's you againts the computer, Good Luck." << endl;


}

char Choice( )
{
	char decision;
	//promp the user.
	cout << "****************************************************" << endl;
	cout << "\nPlease select one option:" << endl;
	cout << "Rock     -- r" << endl;
	cout << "Paper    -- p" << endl;
	cout << "Scissors -- s" << endl;
	cin >> decision;
	
	//Let the user know if the decision is not the one listed and try again.
	while (decision != 'r' && decision != 'p' && decision != 's')
	{
		cout << "ERROR!!. Please enter an option from th above menu." << endl;
		cin >> decision;
	}
	// return the char.
	return decision;
}

void Winner(char user, int comp)
{
	// If user enters rock.
	if (user == 'r')
	{
		if (comp == 1)
		{
			cout << "The computer picked Rock \n";
			cout << "This is a tie! \n";
		}
		else if (comp == 2)
		{			
			cout << "The computer picked Paper \n";
			cout << "Paper beats Rock. You lose! \n";
		}
		else if (comp == 3)
		{
			cout << "The computer picked Scissors \n";
			cout << "Rock beats Scissors. Godd job! \n";
		}
	}

	// If user enters Paper.
	if (user == 'p')
	{
		if (comp == 1)
		{
			cout << "The computer picked Rock \n";
			cout << "Paper beats Rock. Nice one! \n";
		}
		else if (comp == 2)
		{
			cout << "The computer picked Paper \n";
			cout << "This is a tie! \n";
		}
		else if (comp == 3)
		{
			cout << "The computer picked Scissors \n";
			cout << "Scissors beats Paper. Better luck next time! \n";
		}
	}

	// If user enters Scissors.
	if (user == 's')
	{
		if (comp == 1)
		{
			cout << "The computer picked Rock \n";
			cout << "Rock beats Scissors. YOU LOSE! \n";
		}
		else if (comp == 2)
		{
			cout << "The computer picked Paper \n";
			cout << "Scissors beat Paper. YOU WIN! \n";
		}
		else if (comp == 3)
		{
			cout << "The computer picked Scissors \n";
			cout << "TIE! \n";
		}
	}
}
