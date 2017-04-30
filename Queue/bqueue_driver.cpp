
//  Name: Mauricio Da Graca
//	Z#:  23333810	
//	Instructor:  Dr. Bullard
//	Class:  Data Structures
//	Term:  Fall 2015
//	Assignment #6 (TLIST)
//	Due Date:  October 21st, 2015   
//	Due Time:  11:00PM
//	Points:  100 
//	
//Description:
//(1) manipulate pointers,
//(2) allocate memory dynamically
//(3) implement a default constructor, copy constructor and destructor
//(4) use only one pointer to add to the back and to dequeue from the front of the queue.
//*********************************************************************************************/

#include <iostream>
#include "bqueue.h"

using namespace std;

int main()
{
	BQUEUE  k;

	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);
	k.Print();

	BQUEUE j = k;

	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Dequeue();

	return 0;
}