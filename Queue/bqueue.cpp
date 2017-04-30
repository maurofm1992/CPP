//Mauricio Da Graca
//.cpp file
#include<iostream>
#include "BQUEUE.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: BQUEUE
//Precondition: No memory has been allocated
//Postcondition: memory has been allocated, initialized
BQUEUE::BQUEUE()
{
	cout << "Default constructor has been called" << endl;
	back = NULL;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~BQUEUE
//Precondition: Memory has been allocated
//Postcondition: Memory has been deallocated
BQUEUE::~BQUEUE()
{
	if (back == 0)
	{
		delete back;
	}
	else
	{
		bqnode *N = new bqnode;
		N = back->next;
		while (N != back)
		{
			Dequeue();
		}
	}
	delete back;
	cout << "Destructor has been called" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~BQUEUE
//Precondition: One of the queues is filled 
//Postcondition: The queue has been copied
BQUEUE::BQUEUE(const BQUEUE & key)
{
	back = 0;
	(*this) = key;	//copies one list to the other.
	cout << "Item has been copied" << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Print
//Precondition: none
//Postcondition: Prints the queue
void BQUEUE::Print()
{
	if (back == 0)		// if the queue is empty
	{
		cout << "The queue is empty" << endl;
	}
	else if (back->next == 0)		//if it has one item
	{
		cout << back->time << endl;
	}
	else		//if has two or more items
	{
		bqnode *p = back->next;
		while (p != back)
		{
			cout << p->time << endl;
			p = p->next;
		}
		cout << back->time << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Enqueue
//Precondition: The queue can be empty, have one item or more.
//Postcondition: Adds items to the front.
void BQUEUE::Enqueue(int key)
{
	bqnode *p = new bqnode;
	
	if (back == 0)		//checks if is empty
	{
		p->time = key;
		p->next = NULL;
		p->prev = NULL;
		back = p;
	}
	else if (back->next == 0)		//checks if it has one item
	{
		p->time = key;
		p->next = back;
		p->prev = back;
		back->prev = p;
		back->next = p;
		back = p;
	}
	else		//checks if it has two or more items
	{
		p->time = key;
		p->next = back->next;
		p->prev = back;
		back->next = p;
		back = p;
	}

	cout << "Item has been added" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Dequeue
//Precondition: The queue can be empty, have one item or more.
//Postcondition: removes first element from the list.
void BQUEUE::Dequeue()
{
	
	if (back == 0)		//checks if is empty
	{
		cout << "Queue is empty" << endl;
	}
	else if (back->next == back)	//checks if it has one item
	{
		back = 0;
	}
	else			// checks if has two or more items 
	{
		bqnode *p = back->next;
		back->next = p->next;
		p->next->prev = back;
		delete p;
		cout << "Item removed" << endl;
	}
}

