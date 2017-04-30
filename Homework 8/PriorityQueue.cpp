#include "PriorityQueue.h"
#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <vector>

PriorityQueue::PriorityQueue()
{

}

PriorityQueue::~PriorityQueue()
{
	int next;
	while (!empty())
		next = remove();
}

int PriorityQueue::remove()
{
	
}
