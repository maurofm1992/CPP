//DISPLAY 13.23 Implementation of the Queue Class
//This is the implementation file queue.cpp.
//This is the implementation of the class Queue.
//The interface for the class Queue is in the header file queue.h.
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "queue.h"
#include <vector>
using namespace std;
#define SIZE 20


//Uses cstddef:
Queue::Queue() : front(NULL), back(NULL)
{

}

Queue::Queue(const Queue& aQueue)
{
	if (aQueue.empty())
		front = back = NULL;

	else
	{
		QueueNodePtr temp_ptr_old = aQueue.front;
		//temp_ptr_old moves through the nodes
		//from front to bak of aQueue.
		QueueNodePtr temp_ptr_new;
		//temp_ptr_new is used to create new nodes.

		back = new QueueNode;
		back->data = temp_ptr_old->data;
		back->link = NULL;
		front = back;
		//First node created and filled with data.
		//New nodes are now added AFTER this first node.

		temp_ptr_old = temp_ptr_old->link;
		//temp_ptr_old now points to second
		//node or NULL if there is no second node.

		while (temp_ptr_old != NULL)
		{
			temp_ptr_new = new QueueNode;
			temp_ptr_new->data = temp_ptr_old->data;
			temp_ptr_new->link = NULL;
			back->link = temp_ptr_new;
			back = temp_ptr_new;
			temp_ptr_old = temp_ptr_old->link;
		}
	}
}
		

Queue::~Queue()
{
	int next;
	while (!empty())
		next = remove();
}
		

//Uses cstddef:
bool Queue::empty() const
{
	return (back == NULL);//front == NULL would also work
}

	//Uses cstddef:
void Queue::add(int item)
{
	if (empty())
	{
			front = new QueueNode;
			front->data = item;
			front->link = NULL;
			back = front;
	}

	else
	{
		QueueNodePtr temp_ptr;
		temp_ptr = new QueueNode;

		temp_ptr->data = item;
		temp_ptr->link = NULL;
		back->link = temp_ptr;
		back = temp_ptr;
	}
}

	//Uses cstdlib and iostream:
int Queue::remove()
{
	if (empty())
	{
		cout << "Error: Removing an item from an empty queue.\n";
		exit(1);
	}

	int result = front->data;

	QueueNodePtr discard;
	discard = front;
	front = front->link;
	if (front == NULL) //if you removed the last node
		back = NULL;

	delete discard;

	return result;
}

