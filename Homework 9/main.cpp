//Mauricio Da Graca
//Homework 5 a
//Foundations 
//This assignment uses the circular linked list.

#include <iostream>
using namespace std;

void integerCheck(int &integer);

struct Node{
	int num;
	Node*link;
};

int main()
{
	Node *head = NULL;
	Node *current;
	int suitors;
	cout << "Enter the number of suitors: ";
	cin >> suitors;
	integerCheck(suitors);
	if (suitors == 1)
	{
		cout << "To win the princess, you should stand in position " << suitors << endl;
	}

	else{
		//create the circular linked list, starting with #1
		head = new Node;
		head->num = 1;
		head->link = head;
		current = head;

		for (int i = 2; i <= suitors; i++){
			Node *newNode = new Node;
			newNode->num = i;
			newNode->link = head;
			current->link = newNode;
			current = newNode;
		}
		current = head;
		do
{
			//skip to 3rd sutor
			current = current->link;
			Node * prev = current;
			current = current->link;
			Node * next = current->link;
			prev->link = next;

			cout << "Suitor at position number " << current->num << "is OUT!" << endl;
			delete current;
			current = next;
		} while (current != current->link);
		cout << "To win the princess, you should stand in position " << current->num << endl;
		delete current;
	}
	return 0;
}

void integerCheck(int &integer)
{
	while (cin.fail() || !cin.good() || integer != static_cast<int>(integer) || integer <= 0)
	{
		cout << "Error, invalid entry. " << endl
			<< "Pease make a different entry: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin.sync();
		cin >> integer;
		cout << integer;
	}
}