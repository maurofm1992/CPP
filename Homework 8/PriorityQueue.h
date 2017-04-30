#include "Queue.h"

class PriorityQueue : public Queue
{
public:
	PriorityQueue();
	~PriorityQueue();
	virtual int remove();
};