//DISPLAY 13.22 Program Using the Queue Class
//Program to demonstrate use of the Queue class.
#include <iostream>
#include "queue.h"
#include "PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue q;
	q.add(3);
	q.add(100);
	q.add(333);
	q.add(52);
	q.add(4);

	while (!q.empty())
		cout << q.remove() << endl;

	return 0;
}
